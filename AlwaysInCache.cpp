#include "AlwaysInCache.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace cs3100
{
	AlwaysInCache::AlwaysInCache(SimulationParameters* par)	
	{
		p = par;
		firstIteration = true; 
		fifoIndex = 0;
		secondChanceIndex = 0;
		Page _page;
		PageSC _pageSC;
		for (unsigned i = 0; i < 5; i++)
		{
			cache.push_back(0);
			cacheLRU.push_back(_page);
			cacheMRU.push_back(_page);
			cacheSC.push_back(_pageSC);
			cacheLRU.at(i).time = 0;
			cacheLRU.at(i).value = 0;
			cacheMRU.at(i).time = 0;
			cacheMRU.at(i).value = 0;
			cacheSC.at(i).value = 0;
			cacheSC.at(i).check = false;
		}
	}

	bool AlwaysInCache::in(int)
	{
		// Generate random page number.
		int page = (rand() % 9) + 1;

		// UNCOMMENT DESIRED ALGORITHM TO TEST.
		//firstInFirstOut(page);
		//leastRecentlyUsed(page);
		//mostRecentlyUsed(page);
		secondChance(page);

		return true;
	}

	// Determines if integer is already in cache or not.
	bool AlwaysInCache::inCache(int n)
	{
		bool found = false;
		for (unsigned int i = 0; i < cache.size(); i++)
			if (n == cache.at(i))
				found = true;
		return found;
	}

	bool AlwaysInCache::inCacheLRU(int n)
	{
		bool found = false;
		for (unsigned int i = 0; i < cacheLRU.size(); i++)
			if (n == cacheLRU.at(i).value)
				found = true;
		return found;
	}

	bool AlwaysInCache::inCacheMRU(int n)
	{
		bool found = false;
		for (unsigned int i = 0; i < cacheMRU.size(); i++)
			if (n == cacheMRU.at(i).value)
				found = true;
		return found;
	}

	bool AlwaysInCache::inCacheSC(int n)
	{
		bool found = false;
		for (unsigned int i = 0; i < cacheSC.size(); i++)
			if (n == cacheSC.at(i).value)
				found = true;
		return found;
	}

	// SECOND CHANCE MEMORY SCHEDULING ALGORITHM //
	void AlwaysInCache::secondChance(int x)
	{
		// Comment this out later....!!!!
		if (inCacheSC(x))
			return;
		else
		{
			// If current memory location has check mark,
			// assign page to this location.
			if (cacheSC.at(secondChanceIndex).check)
			{
				cacheSC.at(secondChanceIndex).value = x;
				cacheSC.at(secondChanceIndex).check = false;
			}
			// otherwise, check it and loop until next checked 
			// index is found.
			else
			{
				cacheSC.at(secondChanceIndex).check = true;
				bool found = false;
				// finds next memory location to be replaced.
				while (!found)
				{
					secondChanceIndex++;
					if (cacheSC.at(secondChanceIndex).check)
						found = true;
					if (secondChanceIndex == 4)
						secondChanceIndex = -1;
				}

				cacheSC.at(secondChanceIndex).value = x;
				cacheSC.at(secondChanceIndex).check = false;
				p->cacheMissCost++;
			}
		}
	}


	// MOST RECENTLY USED SCHEDULING ALGORITHM //
	void AlwaysInCache::mostRecentlyUsed(int x)
	{
		int index;

		for (unsigned int i = 0; i < cacheMRU.size(); i++)
			cacheMRU.at(i).time++;

		if (firstIteration)
		{
			cacheMRU.at(0).value = x;
			cacheMRU.at(0).time = 0;
			firstIteration = false;
			p->cacheMissCost++;
		}
		else
		{
			if (inCacheMRU(x))
			{
				for (unsigned int i = 0; i < cacheMRU.size(); i++)
					if (x == cacheMRU.at(i).value)
						index = i;

				cacheMRU.at(index).time = 0;
			}
			else
			{
				index = 50;
				for (unsigned int i = 0; i < cacheMRU.size(); i++)
					if (cacheMRU.at(i).time < index)
						index = i;
				cacheMRU.at(index).value = x;
				cacheMRU.at(index).time = 0;
				p->cacheMissCost++;
			}
		}
	}

	// LEAST RECENTLY USED ALGORITHM //
	void AlwaysInCache::leastRecentlyUsed(int x)
	{
		int index;
		// Increment time for all pages in memory.
		for (unsigned int i = 0; i < cacheLRU.size(); i++)
			cacheLRU.at(i).time++;
	
		if (firstIteration)
		{
			cacheLRU.at(0).value = x;
			cacheLRU.at(0).time = 0;
			firstIteration = false;
			p->cacheMissCost++;
		}
		else
		{
			if (inCacheLRU(x))
			{
				for (unsigned int i = 0; i < cacheLRU.size(); i++)
					if (x == cacheLRU.at(i).value)
						index = i;

				cacheLRU.at(index).time = 0;
			}
			else
			{
				index = 0;
				for (unsigned int i = 0; i < cacheLRU.size(); i++)
					if (cacheLRU.at(i).time > index)
						index = i;
				// assign page to memory and reset counter (time) variable.
				cacheLRU.at(index).value = x;
				cacheLRU.at(index).time = 0;
				// Add time penalty for page replacement.
				p->cacheMissCost++;
			}
		}
	}

	// FIRST IN FIRST OUT MEMORY SCHEDULING ALGORITHM //
	void AlwaysInCache::firstInFirstOut(int x)
	{
		if (inCache(x))
			return;
		else
		{
			// Push next page onto next element of cache.
			cache.at(fifoIndex) = x;
			if (fifoIndex < 4)
				fifoIndex++;
			else
				fifoIndex = 0;

			// Add time penalty for page replacement.
			p->cacheMissCost++;
		}
	}
}

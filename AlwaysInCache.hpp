#ifndef CS3100_SCHEDULER_ALWAYS_IN_CACHE_HPP
#define CS3100_SCHEDULER_ALWAYS_IN_CACHE_HPP

#include "CacheAlgorithm.hpp"
#include "Simulation.hpp"
#include <vector>

namespace cs3100
{
  class AlwaysInCache : public CacheAlgorithm
  {
	struct Page
	{
		int value;
		int time;
	};
	struct PageSC
	{
		int value;
		bool check;
	};
  public:
	cs3100::SimulationParameters* p;
	AlwaysInCache(cs3100::SimulationParameters*);
	void mostRecentlyUsed(int);
	void leastRecentlyUsed(int);
	void firstInFirstOut(int);
	void secondChance(int);
	bool in(int)override; 
	void load(int) override {}
	std::vector<int> cache;
	std::vector<Page> cacheLRU; // For use with LRU algorithm.
	std::vector<Page> cacheMRU; // For use with MRU algorithm.
	std::vector<PageSC> cacheSC;  // For use with Second Chance algorithm.
	bool inCache(int);
	bool inCacheLRU(int);
	bool inCacheMRU(int);
	bool inCacheSC(int);
	int fifoIndex;
	int secondChanceIndex;
	bool firstIteration;
  };
}

#endif

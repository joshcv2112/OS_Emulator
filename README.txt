Joshua Vaughan
A01490610

The memory algorithms I wrote for this program are found in the file 'AlwaysInCache.cpp'. To test different algorithms, simply comment or uncomment one of the lines in the 'AlwaysInCache::in()' function. Feel free to change that to test all four algorithms written for this assignment.
By default this program is set to use the FIFO CPU scheduling algorithm, that too can be changed by commenting/uncommenting the code segments in main.

For my report I ran each of the 4 memory algorithms 10 times, and averaged the data for each of them. Below are the average number of page replacements done for each algorithm:

	First in First out: 28.6
	Least Recently Used: 29.3
	Most Recently Used: 48.1
	Second Chance: 46.3

As you can see in the above data, FIFO and Least Recently Used were the most efficient algorithms when considering the number of page replacements done. I found this surprising as I did not expect the FIFO algorithm to require the lowest number of page replacements, I would have guessed that the Second Chance algorithm would do better in that regard.
My calculations were all done using a cache size of 5, using the FIFO CPU algorithm by default.

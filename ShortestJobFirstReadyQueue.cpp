#include "ShortestJobFirstReadyQueue.hpp"
#include "Simulation.hpp"
#include <stdexcept>
namespace cs3100
{
  void ShortestJobFirstReadyQueue::add(int job)
  {
	float x = 0.0f;
	for (unsigned int i = 0; i < simulation->jobs[job].tasks.size(); i++)
		x += simulation->jobs[job].tasks[i].duration;
	
	x /= simulation->jobs[job].tasks.size();
	sum += x;
	avg = sum/job+1;
	

	queue.push(x);
  }

  int ShortestJobFirstReadyQueue::next()
  {
	if (queue.empty()) return -1;
	auto result = queue.front();
	queue.pop();
	return result;
  }
}

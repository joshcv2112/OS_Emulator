#include "ApproximateShortestJobFirstReadyQueue.hpp"
#include "Simulation.hpp"
#include <stdexcept>
namespace cs3100
{

  void ApproximateShortestJobFirstReadyQueue::add(int job)
  {
    throw std::runtime_error("Shortest Job First not implemented yet");

	float x = 0.0f;

	for (unsigned int i = 0; i < past_durations.size(); i++)
		x += past_durations.at(i);

	past_durations.push_back(simulation->jobs[job].tasks[0].duration);
	x += simulation->jobs[job].tasks[0].duration;		

	queue.push(x/past_durations.size());
  }

  int ApproximateShortestJobFirstReadyQueue::next()
  {
	if (queue.empty()) return -1;
	auto result = queue.front();
	queue.pop();
	return result;
  }
}

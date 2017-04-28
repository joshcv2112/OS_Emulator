#include "ReadyQueue.hpp"
#include <queue>
#include <vector>
namespace cs3100
{
  class Simulation;

  class ApproximateShortestJobFirstReadyQueue : public ReadyQueue
  {
 public:
    ApproximateShortestJobFirstReadyQueue();
    // Approximate Shortest Job First needs to be able to look inside current
    // simulation
    void associateSimulator(Simulation* s);

    void add(int) override;
    int next() override;

    std::queue<float> queue;
	std::vector<float> past_durations;
    Simulation* simulation;
	float sum;
	float avg;
	float maximumTimeSlice;
  };
}

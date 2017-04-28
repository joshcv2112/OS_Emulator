#include "ReadyQueue.hpp"
#include <queue>
namespace cs3100
{
  class Simulation;

  class ShortestJobFirstReadyQueue : public ReadyQueue
  {
  public:
    ShortestJobFirstReadyQueue()
	{
		sum = 5.0f;
	}
    void associateSimulator(Simulation* s);
    void add(int) override;
    int next() override;
	float average(float, float);

    std::queue<float> queue;
    Simulation* simulation;
	float sum;
	float avg;
	float maximumTimeSlice;	// Use this for SJFRQ algorithm, not params one
  };
}

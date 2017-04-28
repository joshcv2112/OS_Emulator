#include "AlwaysInCache.hpp"
#include "FifoReadyQueue.hpp"
#include "ShortestJobFirstReadyQueue.hpp"
#include "ApproximateShortestJobFirstReadyQueue.hpp"
#include "Simulation.hpp"
#include <iostream>
#include <limits>

namespace
{
  void report(cs3100::Simulation& s)
  {
    /*TODO create a report based on the results in s*/
    std::cout << "Efficiency : " << s.getEfficiency() << std::endl;
    std::cout << "Task\tLatency\tResponseTime" << std::endl;
    for (size_t i = 0; i < s.getJobs(); ++i)
    {
      std::cout << i << "\t" << s.rawLatency(i) << "\t" << s.rawResponseTime(i)
                << std::endl;
    }
  }

  template <typename ReadyType, typename CacheType>
  void runSimulation(cs3100::SimulationParameters const& p, cs3100::SimulationParameters *params)
  {
    cs3100::Simulation s(
      p, std::make_unique<ReadyType>(), std::make_unique<CacheType>(params));
    s.run();
    report(s);
  }
}

int main()
{
  // FIFO Algorithm
  cs3100::SimulationParameters fifo;
  //cs3100::SimulationParameters *pPtr;
  fifo.cpus = 4;
  fifo.devices = 2;
  fifo.cacheSize = 0;
  fifo.contextSwitchCost = 0.1f;
  fifo.cacheMissCost = 1.0f;
  fifo.maximumTimeSlice = std::numeric_limits<float>::max();
  fifo.jobs = 10;
  fifo.meanTimeBetweenJobs = 10.0f;
  fifo.stddevTimeBetweenJobs = 2.0f;
//  pPtr = &fifo;
  runSimulation<cs3100::FifoReadyQueue, cs3100::AlwaysInCache>(fifo, &fifo);
  std::cout << "Number of Page Replacements: " << fifo.cacheMissCost << std::endl;
  // Round Robin Algorithm
/*  cs3100::SimulationParameters roundRobin;
  roundRobin.cpus = 4;
  roundRobin.devices = 2;
  roundRobin.cacheSize = 0;
  roundRobin.contextSwitchCost = 0.1f;
  roundRobin.cacheMissCost = 1.0f;
  roundRobin.maximumTimeSlice = 5.0f;
  roundRobin.jobs = 10;
  roundRobin.meanTimeBetweenJobs = 10.0f;
  roundRobin.stddevTimeBetweenJobs = 2.0f;
  // create simulation with specific parameters and algorithms
  runSimulation<cs3100::FifoReadyQueue, cs3100::AlwaysInCache>(roundRobin);*/

  // SHORTEST JOB FIRST ALGORITHM
  /*cs3100::SimulationParameters shortestJobFirst;
  shortestJobFirst.cpus = 2;
  shortestJobFirst.devices = 2;
  shortestJobFirst.cacheSize = 0;
  shortestJobFirst.contextSwitchCost = 1.0f;
  shortestJobFirst.cacheMissCost = 1.0f;
  shortestJobFirst.maximumTimeSlice = std::numeric_limits<float>::max();
  shortestJobFirst.jobs = 10;
  shortestJobFirst.meanTimeBetweenJobs = 10.0f;
  shortestJobFirst.stddevTimeBetweenJobs = 2.0f;
  // Create simulation
  runSimulation<cs3100::ShortestJobFirstReadyQueue, cs3100::AlwaysInCache>(shortestJobFirst);*/

  // APPROXIMATE SHORTEST JOB FIRST ALGORITHM
/*  cs3100::SimulationParameters approximateShortestJobFirst;
  approximateShortestJobFirst.cpus = 2;
  approximateShortestJobFirst.devices = 2;
  approximateShortestJobFirst.cacheSize = 0;
  approximateShortestJobFirst.contextSwitchCost = 1.0f;
  approximateShortestJobFirst.cacheMissCost = 1.0f;
  approximateShortestJobFirst.maximumTimeSlice = std::numeric_limits<float>::max();
  approximateShortestJobFirst.jobs = 10;
  approximateShortestJobFirst.meanTimeBetweenJobs = 10.0f;
  approximateShortestJobFirst.stddevTimeBetweenJobs = 2.0f;
  // Create simulation
  runSimulation<cs3100::ApproximateShortestJobFirstReadyQueue, cs3100::AlwaysInCache>(approximateShortestJobFirst);*/

}









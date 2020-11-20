#include <chrono>
#include <iostream>

#include "formatters.h"

namespace scppb
{
	class Benchmark
	{
	public:
		Benchmark(TimeFactor tf = Milliseconds);
		virtual ~Benchmark();
		void StartClock();
		double GetExecutionTime();
		void FormatExecutionTime(std::string function, double executionTime);

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> _startTimePoint;
		std::chrono::time_point<std::chrono::high_resolution_clock> _endTimePoint;
		void StopClock();
		FormatTuple _ft;
	};
} // namespace scppb

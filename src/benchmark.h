#include <chrono>
#include <iostream>

namespace scppb
{
	using namespace std::chrono;

	enum TimeFactor
	{
		Seconds,
		Milliseconds,
		Microseconds,
		Nanoseconds,
	};

	class Benchmark
	{
	public:
		Benchmark(TimeFactor tf = Milliseconds);
		virtual ~Benchmark();
		void startClock();
		double getExecutionTime();
		void formatExecutionTime(std::string function, double executionTime);

	private:
		time_point<high_resolution_clock> _startTimePoint;
		time_point<high_resolution_clock> _endTimePoint;
		TimeFactor _tf;
		std::string _timeFormatString;
		void setTimeFormatString();
		void stopClock();
		double getExecutionTimeInTimeFactor();
	};
} // namespace scppb

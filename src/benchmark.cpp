#include "benchmark.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace scppb;

Benchmark::Benchmark(TimeFactor tf)
{
	_tf = tf;
	setTimeFormatString();
}

Benchmark::~Benchmark() {}

void Benchmark::startClock()
{
	_startTimePoint = chrono::high_resolution_clock::now();
}

void Benchmark::stopClock()
{
	_endTimePoint = chrono::high_resolution_clock::now();
}

double Benchmark::getExecutionTime()
{
	stopClock();
	return getExecutionTimeInTimeFactor();
}

void Benchmark::formatExecutionTime(string function, double executionTime)
{
	cout << "Function " + function + " took " << executionTime << _timeFormatString << " to execute" << endl;
}

double Benchmark::getExecutionTimeInTimeFactor()
{
	using namespace std::chrono;

	auto duration = _endTimePoint - _startTimePoint;

	switch (_tf)
	{
	case Seconds:
		return duration_cast<seconds>(duration).count();
	case Milliseconds:
		return duration_cast<milliseconds>(duration).count();
	case Microseconds:
		return duration_cast<microseconds>(duration).count();
	case Nanoseconds:
		return duration_cast<nanoseconds>(duration).count();
	}
}

void Benchmark::setTimeFormatString()
{
	switch (_tf)
	{
	case Seconds:
		_timeFormatString = " s";
		break;
	case Milliseconds:
		_timeFormatString = " ms";
		break;
	case Microseconds:
		_timeFormatString = " us";
		break;
	case Nanoseconds:
		_timeFormatString = " ns";
		break;
	}
}
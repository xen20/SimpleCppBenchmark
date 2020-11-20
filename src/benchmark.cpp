#include "benchmark.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace scppb;

Benchmark::Benchmark(TimeFactor tf)
{
	_ft = FormatTuple::getFormatTupleFromTimeFactor(tf);
}

Benchmark::~Benchmark() {}

void Benchmark::StartClock()
{
	_startTimePoint = chrono::high_resolution_clock::now();
}

void Benchmark::StopClock()
{
	_endTimePoint = chrono::high_resolution_clock::now();
}

double Benchmark::GetExecutionTime()
{
	StopClock();
	auto mStart = chrono::time_point_cast<chrono::microseconds>(_startTimePoint)
					  .time_since_epoch()
					  .count();
	auto mEnd = chrono::time_point_cast<chrono::microseconds>(_endTimePoint)
					.time_since_epoch()
					.count();

	auto executionTime = (mEnd - mStart) * _ft.divisor;

	return executionTime;
}

void Benchmark::FormatExecutionTime(string function, double executionTime)
{
	cout << "Function " + function + " took " << executionTime << _ft.divisorName
		 << "to execute" << endl;
}
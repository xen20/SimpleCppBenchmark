#include "src/benchmark.h"

using namespace std;

int main(int argc, char **argv)
{
    scppb::Benchmark benchmark(scppb::Microseconds);
    benchmark.startClock();

    for (auto i = 0; i < 1000; ++i)
    {
        cout << i << endl;
    }

    auto executionTime = benchmark.getExecutionTime();
    benchmark.formatExecutionTime("main", executionTime);

    return 0;
}
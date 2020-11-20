#include "src/benchmark.h"
#include "src/formatters.h"

using namespace std;

int main(int argc, char **argv)
{
    scppb::Benchmark benchmark(scppb::Microseconds);
    benchmark.StartClock();

    for (auto i = 0; i < 1000; ++i)
    {
        cout << i << endl;
    }

    auto executionTime = benchmark.GetExecutionTime();
    benchmark.FormatExecutionTime("main", executionTime);

    return 0;
}
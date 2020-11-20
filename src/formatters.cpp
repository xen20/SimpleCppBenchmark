#include "formatters.h"

using namespace scppb;

FormatTuple::FormatTuple(double _divisor, std::string _divisorName)
{
    divisor = _divisor;
    divisorName = _divisorName;
};

FormatTuple::FormatTuple() {}
FormatTuple::~FormatTuple() {}

FormatTuple FormatTuple::getFormatTupleFromTimeFactor(TimeFactor tf)
{
    switch (tf)
    {
    case Seconds:
        return FormatTuple(10E-7, " s ");
        break;
    case Milliseconds:
        return FormatTuple(10E-4, " ms ");
        break;
    case Microseconds:
        return FormatTuple(1, " us ");
        break;
    }
}
#pragma once

#include <iostream>

namespace scppb
{
    enum TimeFactor
    {
        Seconds,
        Milliseconds,
        Microseconds
    };

    class FormatTuple
    {
    public:
        double divisor;
        std::string divisorName;

        static FormatTuple getFormatTupleFromTimeFactor(TimeFactor tf);
        FormatTuple();
        ~FormatTuple();

    private:
        FormatTuple(double _divisor, std::string _divisorName);
    };
}; // namespace scppb
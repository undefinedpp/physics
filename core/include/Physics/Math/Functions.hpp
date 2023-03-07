#pragma once
#include <cmath>

namespace physics
{
    class Functions
    {
    public:
        template <class T>
        static T Clamp(T value, T min, T max)
        {
            if(value < min) return min;
            if(value > max) return max;
            return value;
        }

        template <class T>
        static T RClamp(T value, T min, T max)
        {
            T rmin = std::min(min, max);
            T rmax = std::max(min, max);
            return Clamp(value, rmin, rmax);
        }

        template <class T>
        static T Lerp(T start, T end, T time)
        {
            return time * end + start * (1.0f - time);
        }
    };
}
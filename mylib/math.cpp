#include "math.hpp"
#include <cmath>

namespace mylib {

    float HeronFormula(float x, float y, float z)
    {
        float s = (x + y + z) / 2.0f;
        return std::sqrt(s * (s - x) * (s - y) * (s - z));
    }
}
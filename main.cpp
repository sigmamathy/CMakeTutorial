#include <iostream>
#include "math.hpp"

int main(int argc, char** argv)
{
    float x, y, z;
    std::cin >> x >> y >> z;
    std::cout << "Area of the triangle: " << mylib::HeronFormula(x, y, z) << '\n';
    return 0;
}
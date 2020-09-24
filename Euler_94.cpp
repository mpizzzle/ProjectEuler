#include <boost/multiprecision/cpp_dec_float.hpp>
#include "Euler.h"

uint64_t Euler::AlmostEquilateralTriangles()
{
    //where s = semiperimeter (((2 * a) + b) / 2), b = a +- 1
    //A = sqrt(s * ((s - a) ^ 2) * (s - b))
    //A = sqrt((a + (b / 2)) * ((b / 2) ^ 2) * (a - (b / 2)))
    //A = sqrt((a + (a +- 1 / 2)) * ((a +-1 / 2) ^ 2) * (a - (a +-1 / 2)))
    uint64_t perimeter = 0;
    uint64_t bil = 1000000000;

    for (uint64_t side = 3; side < bil / 2; side += 2) {
        number<cpp_dec_float<50>> area1 = sqrt((side + ((side + 1) / 2)) * pow(((side + 1) / 2), 2) * (side - ((side + 1) / 2)));
        number<cpp_dec_float<50>> area2 = sqrt((side + ((side - 1) / 2)) * pow(((side - 1) / 2), 2) * (side - ((side - 1) / 2)));

        if (area1 == boost::multiprecision::floor(area1) && ((3 * side) + 1) < bil) {
            perimeter += (3 * side) + 1;
            //std::cout << side << ", " << side << ", " << side + 1 << ", area: " << area1 << std::endl;
        }
        if (area2 == boost::multiprecision::floor(area2) && ((3 * side) - 1) < bil) {
            perimeter += (3 * side) - 1;
            //std::cout << side << ", " << side << ", " << side - 1 << ", area: " << area2 << std::endl;
        }
    }

    return perimeter;
}

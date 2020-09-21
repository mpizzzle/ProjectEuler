#include "Euler.h"

cpp_int Euler::SelfPowers()
{
    cpp_int i;

    for (int j = 1; j <= 1000; ++j)
        i += EulerUtility::power(j, j);

    return i;
}
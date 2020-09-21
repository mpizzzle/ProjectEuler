#include "Euler.h"

int Euler::CombinatoricSelections()
{
    int total = 0;

    for (int i = 1; i <= 100; ++i)
        for (int j = 1; j <= i; ++j)
            if (EulerUtility::choose(i, j) > 1000000)
                ++total;

    return total;
}
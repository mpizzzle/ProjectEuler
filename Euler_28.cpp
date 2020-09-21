#include "Euler.h"

long Euler::SpiralDiagonals()
{
    long sum = 1;

    for (int i = 3; i <= 1001; i += 2)
        sum += ((int)(pow(i, 2)) * 4) - (i * 6) + 6;

    return sum;
}
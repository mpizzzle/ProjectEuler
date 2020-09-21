#include "Euler.h"

int Euler::QuadraticPrimes()
{
    for (int i = 40; i >= 0; --i)
        if (pow(i, 2) - i + 41 < 1000)
            return ((int)pow(i, 2) - i + 41) * ((i * -2) + 1);

    return 0;
}
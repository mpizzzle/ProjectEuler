#include "Euler.h"

int Euler::SumOfMultiplesOf3And5Ceiling1000()
{
    int sumOfMultiples = 0;

    for (int i = 0; i < 1000; ++i) {
        if ((i % 3 == 0) || (i % 5 == 0))
            sumOfMultiples += i;
    }

    return sumOfMultiples;
} 
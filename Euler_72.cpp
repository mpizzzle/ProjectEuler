#include "Euler.h"

llui Euler::CountingFractions()
{
    llui total = 0;
    
    std::vector<int> primesIndexed = EulerUtility::getPrimesUnderCeilingIndexed(1e6);
    std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(1e6);

    for (int i = 1; i <= 1e6; ++i)
    {
        total += EulerUtility::phi(i, primes, primesIndexed);
    }

    return total;
}
#include <numeric>
#include "Euler.h"

int Euler::NonAbundantSums()
{
    int ceiling = 28123;
    std::vector<int> abundantNumbers;
    std::vector<int> nonAbundantSums(ceiling * 2 + 1, 0);

    for (int i = 1; i <= ceiling; ++i)
    {        
        if(EulerUtility::sumOfDivisors(i) > 2 * i)
            abundantNumbers.push_back(i);

        nonAbundantSums[i - 1] = i;
    }

    for (int abnum : abundantNumbers)
        for (int abnum2 : abundantNumbers)
            nonAbundantSums[abnum + abnum2 - 1] = 0;

    return std::accumulate(nonAbundantSums.begin(), nonAbundantSums.end(), 0);
}
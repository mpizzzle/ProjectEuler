#include <algorithm>
#include <numeric>

#include "Euler.h"

void addNewPrimeFactors(int nextDivisor, std::vector<int> &p_factors, std::vector<int> &primes)
{
    std::vector<int> myPrimeFactors(p_factors.size(), 0);
    int i = 0;

    while (nextDivisor != 1 && primes[i] <= nextDivisor)
    {
        if ((primes[i] != -1) && (nextDivisor % primes[i] == 0))
        {
            nextDivisor /= primes[i];
            myPrimeFactors[i] += 1;
        }
        else
            ++i;
    }

    for (uint64_t j = 0; j < myPrimeFactors.size(); ++j)
        if (p_factors[j] < myPrimeFactors[j])
            p_factors[j] = myPrimeFactors[j];
}

int Euler::DivisibleBy1To20()
{
    int ceiling = 20;
    std::vector<int> noOfPrimeFactors(ceiling, 0);
    std::vector<int> primeFactors;
    std::vector<int> primes = EulerUtility::getPrimesUnderCeilingIndexed(ceiling);

    for (int i = 2; i <= ceiling; ++i)
        addNewPrimeFactors(i, noOfPrimeFactors, primes);

    for (uint64_t i = 0; i < noOfPrimeFactors.size(); ++i)
        for (int j = 0; j < noOfPrimeFactors[i]; ++j)
            primeFactors.push_back(primes[i]);

    return std::accumulate(primeFactors.begin(), primeFactors.end(), 1, EulerUtility::multiply);
}

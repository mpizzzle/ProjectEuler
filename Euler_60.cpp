#include <algorithm>
#include <unordered_set>

#include "Euler.h"

int Euler::PrimePairSets()
{
    std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(100000);

    std::vector<std::vector<int>> concatPrimes(10000, std::vector<int>());

    for (int i = 0; i < 10000; ++i)
    {
        if (EulerUtility::isPrime(i, 5))
        {
            for (int p : primes)
            {
                if (p < i)
                {
                    std::vector<int> concat(1, i);
                    concat.push_back(p);

                    int c = EulerUtility::digitsToInteger(concat);

                    if (EulerUtility::isPrime(c, 5))
                    {
                        std::swap(concat[0], concat[1]);
                        c = EulerUtility::digitsToInteger(concat);

                        if (EulerUtility::isPrime(c, 5))
                        {
                            concatPrimes[i].push_back(p);
                            concatPrimes[p].push_back(i);
                        }
                    }
                }
                else
                    break;
            }
        }
    }

    for (int i = 0; i < 10000; ++i)
    {
         for (int j : concatPrimes[i])
        {
            std::vector<int> intersection_a = EulerUtility::intersect(concatPrimes[i], concatPrimes[j]);

            for (int k : intersection_a)
            {
                std::vector<int> intersection_b = EulerUtility::intersect(intersection_a, concatPrimes[k]);

                for (int l : intersection_b)
                {
                    std::vector<int> intersection_c = EulerUtility::intersect(intersection_b, concatPrimes[l]);

                    if (intersection_c.size() > 0)
                        return i + j + k + l + intersection_c[0];
                }
            }
        }
    }

    return 0;
}
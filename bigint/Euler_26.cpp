#include "Euler.h"

int Euler::ReciprocalCycles()
{
    std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(1000);

    for (int j = primes.size() - 1; j >= 0; --j)
    {
        bool highestReciprocalCycle = true;

        for (int i = 1; i < primes[j]; ++i)
        {
            BigInteger bi = EulerUtility::power(10, i);

            if (((bi % primes[j] == 1) && (i != (primes[j] - 1))) || ((bi % primes[j] != 1) && (i == (primes[j] - 1))))
            {
                highestReciprocalCycle = false;
                break;
            }
        }

        if (highestReciprocalCycle)
            return primes[j];
    }

    return 0;
}
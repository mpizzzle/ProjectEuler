#include "Euler.h"

int Euler::NoOfCircularPrimes()
{
    int total = 2; //this algorithm misses out 2 and 5

    std::vector<int> primes = EulerUtility::getPrimesUnderCeilingIndexed(1000000);

    for (int prime : primes)
    {
        if (prime != -1)
        {
            bool potentialCircularPrime = true;

            std::vector<int> digits = EulerUtility::intToDigits(prime);

            for (int digit : digits)
                if ((digit == 0) || (digit == 5) || (digit % 2 == 0))
                {
                    potentialCircularPrime = false;
                    break;
                }

            if (potentialCircularPrime)
                for (int j = 0; j <= log10(prime); ++j)
                {
                    if (primes[EulerUtility::digitsToInteger(digits)] == -1)
                    {
                        potentialCircularPrime = false;
                        break;
                    }

                    std::rotate(digits.begin(), digits.begin() + 1, digits.end());
                }

            if (potentialCircularPrime)
                ++total;
        }
    }

    return total;
}
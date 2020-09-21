#include <algorithm>
#include "Euler.h"

struct pair
{
    int prime;
    int digit;
};

int Euler::PrimeDigitReplacements()
{
    std::vector<int> primes = EulerUtility::getPrimesUnderCeilingIndexed(1000000);
    std::vector<pair> candidates;

    for (int prime : primes)
    {
        if (prime != -1)
        {
            std::vector<int> digits = EulerUtility::intToDigits(prime);

            int repeatedDigits[3] = {0, 0, 0};

            for (uint64_t i = 0; i < digits.size() - 1; ++i)
                if (digits[i] <= 2)
                    ++repeatedDigits[digits[i]];

            for (int i = 0; i < 3; ++i)
                if (repeatedDigits[i] == 3)
                {
                    pair p;
                    p.prime = prime;
                    p.digit = i;
                    candidates.push_back(p);
                }
        }
    }

    for (pair p : candidates)
    {
        std::vector<int> digits = EulerUtility::intToDigits(p.prime);
        std::vector<int> indices;
        int sizeOfFamily = 1;

        for (uint64_t i = 0; i < digits.size() - 1; ++i)
            if (digits[i] == p.digit)
                indices.push_back(i);

        for (int i = 0; i < 10; ++i)
        {
            if ((i != p.digit) && (i != 0 || indices[0] != 0))
            {
                for (int idx : indices)
                    digits[idx] = i;

                if (primes[EulerUtility::digitsToInteger(digits)] > 0)
                    ++sizeOfFamily;
            }
        }

        if (sizeOfFamily >= 8)
            return p.prime;
    }

    return 0;
}

#include "Euler.h"

llui Euler::GoldbachsOtherConjecture()
{
    std::vector<int> primes = EulerUtility::getPrimesUnderCeilingIndexed(1000000);

    for (int i = 33; i < primes.size(); ++i)
    {
        if ((i & 1) && primes[i] == -1)
        {
            bool conjecture_holds = false;

            for (int j = 0; j < i; ++j)
            {
                if (primes[j] != -1)
                {
                    if (EulerUtility::isPerfectSquare((i - j) / 2))
                    {
                        conjecture_holds = true;
                        break;
                    }
                }
            }

            if (!conjecture_holds)
                return i;
        }
    }

    return 0;
}
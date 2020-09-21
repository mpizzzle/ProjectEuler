#include "Euler.h"

int Euler::PowerfulDigitCounts()
{
    int count = 0;

    for (BigInteger i = 1; i < 10; ++i)
    {
        for (int p = 1;; ++p)
        {
            if (EulerUtility::BigIntToDigits(EulerUtility::power(i, p)).size() == p)
            {
                ++count;
            }
            else
            {
                break;
            }
        }
    }

    return count;
}
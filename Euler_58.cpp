#include "Euler.h"

ll Euler::SpiralPrimes()
{
    ll n = 8, d = 13, i = 26, count = 7, topRight = 31;
    int mod3 = -1;

    while ((n / (double)d) * 100 >= 10)
    {
        topRight += i;
        count += 2;
        d += 4;
        i += 8;
        mod3 = (mod3 + 1) % 3;

        if (EulerUtility::isPrime(topRight + count - 1, 5))
            ++n;

        if (mod3 != 0)
            if (EulerUtility::isPrime(topRight, 5))
                ++n;

        if (mod3 != 1)
            if (EulerUtility::isPrime(topRight + (count * 2) - 2, 5))
                ++n;
    }

    return count;
}
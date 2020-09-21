#include "Euler.h"

int Euler::SquareRootConvergents()
{
    BigInteger n = 3, d = 2;
    int count = 0;

    for (int i = 1; i < 1000; ++i)
    {
        n += d;
        std::swap(n, d);
        n += d;

        if (EulerUtility::BigIntToDigits(n).size() > EulerUtility::BigIntToDigits(d).size())
            ++count;
    }

    return count;
}
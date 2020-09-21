#include "Euler.h"

BigInteger partition(BigInteger &n, std::vector<BigInteger> &cache)
{
    BigInteger p = 0;

    if (n >= 0)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (cache[n.toInt() - 1] != 0)
        {
            return cache[n.toInt() - 1];
        }

        int k = 1;

        BigInteger s1 = 0;
        BigInteger s2 = 0;

        while (n - s2 >= 0)
        {
            s1 = (k * (3 * k - 1)) / 2;
            s2 = (k * (3 * k + 1)) / 2;

            BigInteger sign = (k - 1) & 1 ? -1 : 1;

            p += sign * partition(n - s1, cache);
            p += sign * partition(n - s2, cache);
            ++k;
        }

        cache[n.toInt() - 1] = p;
    }

    return p;
}

llui Euler::CoinPartitions()
{
    int ceiling = 100000;
    std::vector<BigInteger> cache(ceiling, 0);

    for (int i = 1; i < ceiling; ++i)
    {
        if ((i - 4) % 5 == 0)
        {
            BigInteger n = partition(BigInteger(i), cache);

            if (n % 1000000 == 0)
            {
                return i;
            }
        }
    }

    return 0;
}
#include "Euler.h"

cpp_int partition(cpp_int &n, std::vector<cpp_int> &cache)
{
    cpp_int p = 0;

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

        cpp_int s1 = 0;
        cpp_int s2 = 0;

        while (n - s2 >= 0)
        {
            s1 = (k * (3 * k - 1)) / 2;
            s2 = (k * (3 * k + 1)) / 2;

            cpp_int sign = (k - 1) & 1 ? -1 : 1;

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
    std::vector<cpp_int> cache(ceiling, 0);

    for (int i = 1; i < ceiling; ++i)
    {
        if ((i - 4) % 5 == 0)
        {
            cpp_int n = partition(cpp_int(i), cache);

            if (n % 1000000 == 0)
            {
                return i;
            }
        }
    }

    return 0;
}
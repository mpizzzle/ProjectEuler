#include "Euler.h"

ll partition(int n, std::vector<int> &cache)
{
    ll p = 0;

    if(n >= 0)
    {
        if(n == 0 || n == 1)
        {
            return 1;
        }
        if(cache[n - 1] != 0)
        {
            return cache[n - 1];
        }

        int k = 1;

        ll s1 = 0;
        ll s2 = 0;

        while (n - s2 >= 0)
        {
            s1 = (k * (3 * k - 1)) / 2;
            s2 = (k * (3 * k + 1)) / 2;

            int sign = (k - 1) & 1 ? -1 : 1;

            p += sign * partition(n - s1, cache);
            p += sign * partition(n - s2, cache);
            ++k;
        }

        cache[n - 1] = p;
    }

    return p;
}

int Euler::CountingSums()
{
    return partition(100, std::vector<int>(100, 0)) - 1;
}
#include "Euler.h"

ll partition(int n, std::vector<int> &cache)
{
    ll p = 0;
    std::vector<int> cache_ref = cache;

    if(n >= 0)
    {
        if(n == 0 || n == 1)
        {
            return 1;
        }
        if(cache_ref[n - 1] != 0)
        {
            return cache_ref[n - 1];
        }

        int k = 1;

        ll s1 = 0;
        ll s2 = 0;

        while (n - s2 >= 0)
        {
            s1 = (k * (3 * k - 1)) / 2;
            s2 = (k * (3 * k + 1)) / 2;

            int sign = (k - 1) & 1 ? -1 : 1;

            p += sign * partition(n - s1, cache_ref);
            p += sign * partition(n - s2, cache_ref);
            ++k;
        }

        cache_ref[n - 1] = p;
    }

    return p;
}

int Euler::CountingSums()
{
    std::vector<int> cache(100, 0);
    return partition(100, cache) - 1;
}

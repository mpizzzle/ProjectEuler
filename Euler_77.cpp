#include "Euler.h"

int primeSumRecurse(int n, int max, std::vector<int> &primes)
{
    int sum = 0;

    for(int i = max; i < primes.size(); i++)
    {
        if (n - primes[i] == 0)
			++sum;
        if (n - primes[i] > 0)
			sum += primeSumRecurse(n - primes[i], i, primes);
    }

    return sum;     
}

int Euler::PrimeSummations()
{
	int ceiling = 1000;
	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(ceiling);
	std::reverse(primes.begin(), primes.end());

	int n = 0;
	int i = -1;

	while (n <= 5000)
	{
		++i;
		n = primeSumRecurse(i, 0, primes);
	}

	return i;
}
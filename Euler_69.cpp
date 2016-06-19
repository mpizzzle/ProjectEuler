#include "Euler.h"

int Euler::EulerTotient()
{
	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(1e6);
	std::vector<int> primesIndexed = EulerUtility::getPrimesUnderCeilingIndexed(1e6);
	double NoverPhi = 0, n = 0;

	for (double i = 2; i <= 1e6; ++i)
	{
		int p = EulerUtility::phi(i, primes, primesIndexed);

		if (i / p > NoverPhi)
		{
			NoverPhi = i / p;
			n = i;
		}
	}

	return n;
}
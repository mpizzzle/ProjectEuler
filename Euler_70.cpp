#include <algorithm>

#include "Euler.h"

int Euler::TotientPermutation()
{
	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(1e7);
	std::vector<int> primesIndexed = EulerUtility::getPrimesUnderCeilingIndexed(1e7);
	double NoverPhi = 1e8, n = 0;

	for (double i = 2; i <= 1e7; ++i)
	{
		int p = EulerUtility::phi(i, primes, primesIndexed);

		std::vector<int> digits = EulerUtility::intToDigits(i);

		if ((std::is_permutation(digits.begin(), digits.end(), EulerUtility::intToDigits(p).begin())) && (NoverPhi > i / p))
		{
			NoverPhi = i / p;
			n = i;
		}
	}

	return n;
}
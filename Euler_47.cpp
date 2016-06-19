#include <unordered_set>

#include "Euler.h"

std::unordered_set<int> distinctPrimeFactors(llui target, std::vector<int> &primes)
{
	std::unordered_set<int> distinctPrimeFactors;

	int i = 0;

	while (target != 1)
	{
		if (target % primes[i] == 0)
		{
			target /= primes[i];
			distinctPrimeFactors.insert(primes[i]);
		}
		else
			++i;
	}

	return distinctPrimeFactors;
}

int Euler::DistinctPrimeFactors()
{
	int consecutive = 0;
	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(1000000);

		for (int i = 647; ; ++i)
		{
			consecutive = (distinctPrimeFactors(i, primes).size() == 4) ? consecutive + 1 : 0;

			if (consecutive == 4)
				return i - 3;
		}

		return 0;
}
#include "Euler.h"

int getNumberOfDivisorsFromPrimeFactors(llui target, std::vector<int> &primes)
{
	std::vector<int> noOfEachPrimeFactor;

	int divisors = 1;
	int i = 0;

	bool first = true;

	while (target != 1)
	{
		if (target % primes[i] == 0)
		{
			target /= primes[i];

			if (first)
			{
				first = false;
				noOfEachPrimeFactor.push_back(1);
			}
			else
				noOfEachPrimeFactor[noOfEachPrimeFactor.size() - 1] += 1;
		}
		else
		{
			first = true;
			++i;
		}
	}

	if (!noOfEachPrimeFactor.empty())
	{
		for (unsigned i = 0; i < noOfEachPrimeFactor.size(); ++i)
		{
			divisors *= (noOfEachPrimeFactor[i] + 1);
		}
	}

	return divisors;
}

llui Euler::TriangleNoWithGreaterThan500Divisors()
{
	llui currentTriangle = 1;

	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(100000);

	for (int i = 2; getNumberOfDivisorsFromPrimeFactors(currentTriangle, primes) <= 500; ++i)
		currentTriangle += i;

	return currentTriangle;
}
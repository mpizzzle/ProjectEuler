#include "Euler.h"

int Euler::AmicableNumbers()
{
	std::vector<unsigned> sumDivisors(10001, 0);

	for(int i = 2; i < 10000; ++i)
		sumDivisors[i] = EulerUtility::sumOfDivisors(i) - i;

	int sum = 0;

	for (unsigned i = 0; i < sumDivisors.size(); ++i)
		if (sumDivisors[i] < sumDivisors.size() && sumDivisors[sumDivisors[i]] == i && sumDivisors[i] != i)
			sum += i;

	return sum;
}
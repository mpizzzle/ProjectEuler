#include "Euler.h"

BigInteger Euler::SelfPowers()
{
	BigInteger i;

	for (int j = 1; j <= 1000; ++j)
		i += EulerUtility::power(j, j);

	return i;
}
#include "Euler.h"

llui Euler::DigitFactorials()
{
	int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	llui sum = 0;

	for (unsigned i = 0 ; i < 50000; ++i)
	{
		long currentTotal = 0;

		std::vector<int> digits = EulerUtility::intToDigits(i);

		for (int digit : digits)
			currentTotal += factorials[digit];

		if (i == currentTotal)
			sum += currentTotal;
	}

	return sum - 3;
}
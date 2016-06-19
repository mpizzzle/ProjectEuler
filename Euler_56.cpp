#include <numeric>

#include "Euler.h"

int Euler::PowerfulDigitSum()
{
	int highestDigitSum = 0;

	for (int i = 1; i < 100; ++i)
	{
		for (int j = 1; j < 100; ++j)
		{
			std::vector<int> digits = EulerUtility::powerDigits(i,j);
			int digitSum = std::accumulate(digits.begin(), digits.end(), 0);

			if (digitSum > highestDigitSum)
				highestDigitSum = digitSum;
		}
	}

	return highestDigitSum;
}
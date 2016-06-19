#include <algorithm>
#include "Euler.h"

int Euler::PermutedMultiples()
{
	for (int i = 1;;++i)
	{
		std::vector<int> digits = EulerUtility::intToDigits(i);

		for (int j = 2; j < 7; ++j)
		{
			std::vector<int> multiple = EulerUtility::intToDigits(i * j);

			if (!std::is_permutation(digits.begin(), digits.end(), multiple.begin()))
				break;

			if (j == 6)
				return i;
		}
	}

	return 0;
}
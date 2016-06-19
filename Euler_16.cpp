#include <numeric>

#include "Euler.h"

int Euler::DigitSum()
{
	std::vector<int> digits;

	digits.push_back(2);

	for (int i = 1; i < 1000; ++i)
	{
		for (unsigned j = 0; j < digits.size(); ++j)
			digits[j] *=2;

		for (unsigned j = 0; j < digits.size(); ++j)
		{
			if (digits[j] >= 10)
			{
				digits[j] = digits[j] % 10;

				if (j == digits.size() - 1)
				{
					digits.push_back(1);
				}
				else
				{
					digits[j + 1] += 1;
				}
			}
		}
	}

	return std::accumulate(digits.begin(), digits.end(), 0);
}
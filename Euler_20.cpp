#include <numeric>

#include "Euler.h"

llui Euler::FactorialDigitSum()
{
	std::vector<int> digits = EulerUtility::factorialDigits(100);

	return std::accumulate(digits.begin(), digits.end(), 0);
}
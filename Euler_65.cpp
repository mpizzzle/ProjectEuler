#include <numeric>

#include "Euler.h"

std::vector<BigInteger> recurseFraction2(std::vector<BigInteger> period, BigInteger n, std::vector<BigInteger> fraction)
{
	if (n > period.size() - 1)
		return fraction;

	std::swap(fraction[0], fraction[1]);

	fraction[0] = (fraction[1] * period[period.size() - n.toInt() - 1]) + fraction[0];

	return recurseFraction2(period, n + 1, fraction);
}

std::vector<BigInteger> recurseFraction2(std::vector<BigInteger> period, BigInteger n)
{
	std::vector<BigInteger> fraction;

	fraction.push_back(period[period.size() - 1]);
	fraction.push_back(1);

	return recurseFraction2(period, 1, fraction);
}

BigInteger periodiuy()
{
	std::vector<BigInteger> period;

	period.push_back(2);

	int n = 2;

	for (int i = 1; i < 100; ++i)
	{
		if (i % 3 == 2)
		{
			period.push_back(n);
			n += 2;
		}
		else
		{
			period.push_back(1);
		}
	}

	
	std::vector<BigInteger> approx = recurseFraction2(period, 0);
	return approx[0];
}

int Euler::ConvergentsOfE()
{
	std::vector<int> digits = EulerUtility::BigIntToDigits(periodiuy());

	return std::accumulate(digits.begin(), digits.end(), 0);
}

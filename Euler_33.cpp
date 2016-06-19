#include "Euler.h"

std::vector<int> lowestTerm(int n, int d, std::vector<int> &p)
{
	for (unsigned i = 0; i < p.size(); )
	{
		if ((n % p[i] == 0) && (d % p[i] == 0))
		{
			n /= p[i];
			d /= p[i];

			i = 0;
		}
		else
			++i;
	}

	std::vector<int> l;

	l.push_back(n);
	l.push_back(d);

	return l;
}

void addDigitCancellingFraction(std::vector<int> &denom, std::vector<int> &numer, std::vector<int> &primes, std::vector<std::vector<int>> &dc_fractions, int n, int d, bool first)
{
	if (denom[first] == numer[!first])
	{
		std::vector<int> lowest = lowestTerm(n, d, primes);
		std::vector<int> lowestCancelled = lowestTerm(numer[first], denom[!first], primes);
		if ((lowestCancelled[0] == lowest[0]) && (lowestCancelled[1] == lowest[1]))
			dc_fractions.push_back(lowest);
	}
}

int Euler::DigitCancellingFractionsDenominator()
{
	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(52);

	std::vector<std::vector<int>> dc_fractions;

	for (int denominator = 10; denominator < 100; ++ denominator)
	{
		std::vector<int> denom = EulerUtility::intToDigits(denominator);

		for (int numerator = 10; numerator < denominator; ++numerator)
		{
			std::vector<int> numer = EulerUtility::intToDigits(numerator);

			addDigitCancellingFraction(denom, numer, primes, dc_fractions, numerator, denominator, true);
			addDigitCancellingFraction(denom, numer, primes, dc_fractions, numerator, denominator, false);
		}
	}

	int n = 1, d = 1;

	for (std::vector<int> fraction : dc_fractions)
	{
		n *= fraction[0];
		d *= fraction[1];
	}

	std::vector<int> lowestProduct = lowestTerm(n, d, primes);

	return lowestProduct[1];
}
#include <unordered_set>

#include "Euler.h"

std::vector<int> getPowers(int ceiling)
{
	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(ceiling);
	std::vector<int> powers(ceiling + 1, 0);

	for (int j = 0; j <= ceiling; ++j)
	{
		std::vector<int> p_factors;
		int target = j;
		int i = 0;

		while (target > 1)
		{
			if (target % primes[i] == 0)
			{
				target /= primes[i];
				p_factors.push_back(primes[i]);
			}
			else
				++i;
		}

		if (p_factors.size() > 1)
		{
			std::unordered_set<int> unique_p_factors;

			for (int p : p_factors)
				unique_p_factors.insert(p);

			if (unique_p_factors.size() == 1)
				powers[j] = p_factors.size();
			else if (EulerUtility::isPerfectSquare(j))
				powers[j] = 2;
		}
	}

	return powers;
}

int Euler::DistinctPowers()
{
	int ceiling = 100;
	std::vector<int> powers = getPowers(ceiling);

	int sum = 0;

	for (int i = 2; i <= ceiling; ++i)
	{
		if (powers[i] == 0)
			sum += ceiling - 1;
		else
		{
			for (int j = 2; j <= ceiling; ++j)
			{
				bool unique = true;

				for (int k = 1; k < powers[i]; ++k)
				{
					if (((powers[i] * j) % k == 0) && ((powers[i] * j) / k <= ceiling))
					{
						unique = false;
						break;
					}
				}

				if (unique)
					++sum;
			}
		}
	}

	return sum;
}
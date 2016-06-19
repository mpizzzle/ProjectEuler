#include <numeric>

#include "Euler.h"

int Euler::ConsecutivePrimeSum()
{
	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(1000000);
	std::vector<int> primes2 = EulerUtility::getPrimesUnderCeilingIndexed(1000000);

	int highestPotential = 0;

	for (int i = 0; i < 600; ++i)
	{
		int potentialPrime = std::accumulate(primes.begin(), primes.begin() + 600 - i, 0);

		if (potentialPrime < 1000000)
		{
			if (potentialPrime == primes2[potentialPrime])
			{
				highestPotential = potentialPrime;
				int greatestLength = 600 - i;

				for (int j = 1; ; ++j)
				{
					bool firstPass = true;

					for (int k = 1; ; ++k)
					{
						potentialPrime = std::accumulate(primes.begin() + j, primes.begin() + 600 - i + j + k, 0);

						if (potentialPrime < 1000000)
						{
							if ((potentialPrime == primes2[potentialPrime]) && (600 - i + k > greatestLength))
							{
								highestPotential = potentialPrime;
								greatestLength = 600 - i + k;
							}

							firstPass = false;
						}
						else
						{
							if (firstPass)
								return highestPotential;

							break;
						}
					}
				}
			}
		}
	}

	return 0;
}
#include "Euler.h"

int getPentagonal(int n)
{
	return (n * ((3 * n) - 1)) / 2;
}

int Euler::MinimizedPentagonalDifference()
{
	std::vector<int> pentaNos(1, 1);
	std::vector<int> potential_D;

	for (;;)
	{
		pentaNos.push_back(getPentagonal(pentaNos.size() + 1));

		for (int j = 0; j < pentaNos.size() - 1; ++j)
			if (EulerUtility::isPentagonal(pentaNos[pentaNos.size() - 1] + pentaNos[j]) && EulerUtility::isPentagonal(pentaNos[pentaNos.size() - 1] - pentaNos[j]))
				return pentaNos[pentaNos.size() - 1] - pentaNos[j];
	}

	return 0;
}
#include "Euler.h"

int Euler::MaximumRightAngledTriangles()
{
	int perimeter = 120;
	int maximum = 3;

	for (int p = 121; p <= 1000; ++p)
	{
		int solutions = 0;

		for (int i = 1; i < p / 2 + 1; ++i)
			for (int j = 1; j <= i; ++ j)
				if (EulerUtility::isPerfectSquare(pow(i, 2) + pow(j, 2)))
					if ((i + j + sqrt(pow(i, 2) + pow(j, 2))) == p)
						++solutions;

		if (solutions > maximum)
		{
			maximum = solutions;
			perimeter = p;
		}
	}

	return perimeter;
}
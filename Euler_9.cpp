#include <sstream>

#include "Euler.h"

int Euler::SpecialPythagoreanTriplet()
{
	for (int a = 1; a < 1000; ++a)
		for (int b = 1; b < 1000; ++b)
		{
			double c = sqrt(a * a + b * b);

			if ((a + b + c) == 1000)
				return a * b * (int)c;
		}

	return 0;
}
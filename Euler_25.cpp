#include "Euler.h"

int Euler::ThousandDigitFibonacciNumber()
{
	std::vector<int> fib1(1, 1);
	std::vector<int> fib2(1, 1);

	int count = 2;

	while (fib1.size() < 1e3)
	{
		for (unsigned i = 0; i < fib1.size(); ++i)
			fib1[i] += fib2[i];

		for (unsigned i = 0; i < fib1.size(); ++i)
		{
			if (fib1[i] >= 10)
			{
				fib1[i] = fib1[i] % 10;

				if (i == fib1.size() - 1)
				{
					fib1.push_back(1);
					fib2.push_back(0);
				}
				else
					fib1[i + 1] += 1;
			}
		}

		fib1.swap(fib2);

		++count;
	}

	return count;
}
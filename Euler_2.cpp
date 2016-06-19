#include "Euler.h"

int Euler::SumOfEvenFibonacciNumbersCeiling4m()
{
	int sumOfEvenFibNumbers = 0;

	for (int i = 1, j = 2; j < 4000000;)
	{
		if (j % 2 == 0)
			sumOfEvenFibNumbers += j;

		int temp = j;
		j += i;
		i = temp;
	}

	return sumOfEvenFibNumbers;
}
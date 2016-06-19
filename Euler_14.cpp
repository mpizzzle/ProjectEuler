#include "Euler.h"

int lengthOfChain(llui number)
{
	int length = 0;

	while (number > 1)
	{
		if (number % 2 == 0)
		{
			number /= 2;
		}
		else
		{
			number = (number * 3) + 1;
		}

		length += 1;
	}

	return length;
}

llui Euler::CollatzConjecture()
{
	int longestChain = 0;
	int idx = 0;

	for (int i = 0; i < 1000000; ++i)
	{
		int length = lengthOfChain(i);

		if (length > longestChain)
		{
			longestChain = length;
			idx = i;
		}
	}

	return idx;
}
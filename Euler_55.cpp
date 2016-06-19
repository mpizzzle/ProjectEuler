#include <sstream>

#include "Euler.h"

bool isPalindrome(BigInteger i)
{
	std::ostringstream oss;
	oss << i;

	std::string temp = oss.str();

	for (unsigned int j = 0; j < temp.length() / 2 + 1; ++j)
		if (temp.at(j) != temp.at(temp.length() - 1 - j))
			return false;

	return true;
}

BigInteger reverse(BigInteger i)
{
	BigInteger reverse = 0;

	while(i > 0)
	{
		reverse = reverse * 10 + (i % 10);
		i /= 10;
	}

	return reverse;
}

BigInteger Euler::LychrelNumbers()
{
	int lychel = 9999;

	for (int i = 1; i < 10000; ++i)
	{
		BigInteger current(i);

		for (int j = 0; j < 50; ++j)
		{
			current = current + reverse(current);

			if (isPalindrome(current))
			{
				--lychel;
				break;
			}
		}
	}

	return lychel;
}
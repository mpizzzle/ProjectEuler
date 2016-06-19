#include <algorithm>
#include <sstream>

#include "Euler.h"

bool isPalindrome(int i)
{
	std::ostringstream oss;
	oss << i;

	std::string temp = oss.str();

	for (unsigned int i = 0; i < temp.length(); ++i)
		if (temp.at(i) != temp.at(temp.length() - 1 - i))
			return false;

	return true;
}

int Euler::LargestPalindromeFrom3DigitProduct()
{
	std::vector<int> products;

	for (int i = 999; i > 99; --i)
	{
		for (int j = 999; j >= i; --j)
		{
			if (isPalindrome(i * j)) {
				products.push_back(i * j);
				break;
			}
		}
	}

	std::sort(products.begin(), products.end());

	return products.back();
}
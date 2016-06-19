#include <fstream>
#include <sstream>

#include "Euler.h"

std::vector<int> getIndividualDigits(int number)
{
	std::vector<int> digits;

	std::string s = std::to_string(number);

	for (int i = s.length() - 1; i >= 0 ; --i)
		digits.push_back(atoi(s.substr(i, 1).c_str()));

	return digits;
}

std::string getSum(std::vector<int> digits)
{
	std::string s;

	for (int i = digits.size() - 1; i >= 0; --i)
	{
		s += std::to_string(digits[i]);
	}

	return s;
}

std::string Euler::LargeSum() {
	std::ifstream fin;
	std::vector<std::string> numbers;

	fin.open("E:\\Euler Resources\\Euler 13.txt");

	std::string temp;
	while(std::getline(fin, temp))
		numbers.push_back(temp);

	fin.close();

	std::vector<int> sumDigits;

	for (int i = numbers[0].size() - 1; i >= 0; --i)
	{
		int exp = 0;

		for (unsigned j = 0; j < numbers.size(); ++j)
		{
			std::stringstream strValue;
			strValue << numbers[j].at(i);

			unsigned int sumDigit;
			strValue >> sumDigit;

			exp += sumDigit;
		}

		sumDigits.push_back(exp);
	}

	std::vector<int> digits = getIndividualDigits(sumDigits[0]);

	for (unsigned i = 1; i < sumDigits.size(); ++i)
	{
		std::vector<int> temp = getIndividualDigits(sumDigits[i]);

		digits[i] += temp[0];
		digits[i + 1] += temp[1];
		digits.push_back(temp[2]);
	}

	for (unsigned i = 0; i < digits.size(); ++i)
	{
		if (digits[i] >= 20)
		{
			digits[i] -= 20;
			digits[i + 1] += 2;
		}
		else if (digits[i] >= 10)
		{
			digits[i] -= 10;
			digits[i + 1] += 1;
		}
	}

	return getSum(digits).substr(0, 10);
}
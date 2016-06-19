#include <algorithm>
#include <set>

#include "Euler.h"

int recurseChain(llui head, std::set<llui> &chain, int factorials[], int size)
{	
	llui tempHead = head;
	llui newHead = 0;
	
	while (tempHead != 0)
	{
		newHead += factorials[tempHead % 10];
		tempHead /= 10;
	}

	//found in problem 34
	if (newHead == 1 || newHead == 2 || newHead == 145 || newHead == 40585)
		return size + 1;

	//cycles given in the problem
	if (newHead == 871 || newHead == 872 || newHead == 45361 || newHead == 45362)
		return size + 2;
	if (newHead == 169 || newHead == 1454 || newHead == 363601)
		return size + 3;

	chain.insert(newHead);

	if (chain.size() == size || chain.size() > 60)
	{
		return chain.size();
	}

	return recurseChain(newHead, chain, factorials, chain.size());
}

int Euler::DigitFactorialChains()
{
	int total = 0;
	int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

	std::vector<std::vector<int>> solutions;

	for (int i = 1; i < 1e6; ++i)
	{
		bool ordered = true;
	
		for (int temp = i; temp != 0; temp /= 10)
		{
			if (((temp % 10) < ((temp / 10) % 10)) && ((temp % 10) != 0))
			{
				ordered = false;
				break;
			}
		}

		//we only check ascending values, e.g. 1243 has the same chain as 1234.
		//zero is a wild card, therfore 1034 counts as ascending.
		if (ordered)
		{
			std::set<llui> chain;

			chain.insert(i);

			if (recurseChain(i, chain, factorials, chain.size()) == 60)
			{
				//this uniqueness check is necessary because solutions containing zero break the ascending rule
				std::vector<int> digits = EulerUtility::intToDigits(i);
				bool unique = true;

				for (std::vector<int> s : solutions)
					if (std::is_permutation(digits.begin(), digits.end(), s.begin()))
						unique = false;

				if (unique)
				{
					solutions.push_back(digits);

					int sum = EulerUtility::factorial(digits.size()) / EulerUtility::factorial(digits.size() - std::set<int>(digits.begin(), digits.end()).size() + 1);

					int zeroCount = std::count(digits.begin(), digits.end(), 0);

					if (zeroCount > 0)
						sum = ((sum / digits.size()) * (digits.size() - 1)) / EulerUtility::factorial(zeroCount);

					total += sum;
				}
			}
		}
	}

	return total;
}
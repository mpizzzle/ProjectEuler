#include <algorithm>
#include <numeric>
#include <unordered_set>

#include "Euler.h"

int getSubInt(unsigned it1, unsigned it2, std::vector<int> &sub_lex)
{
	int integer = 0;

	for (unsigned i = it1; i < it2; ++i)
	{
		integer *= 10;
		integer += sub_lex[i];
	}

	return integer;
}

int Euler::PanDigitalProducts()
{
	int lexicon[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> lex(std::begin(lexicon), std::end(lexicon));

	std::unordered_set<int> products;

	for (int i = 0; i < EulerUtility::factorial(9); ++i)
	{
		for (unsigned it1 = 1; it1 < 5; ++ it1)
			for (unsigned it2 = it1 + 1; it2 < lex.size() - 3; ++it2)
			{
				int multiplicand = getSubInt(0, it1, lex);
				int multiplier = getSubInt(it1, it2, lex);
				int product = getSubInt(it2, lex.size(), lex);

				if (multiplicand * multiplier == product)
					products.insert(product);
			}

		std::next_permutation(lex.begin(), lex.end());
	}

	return std::accumulate(products.begin(), products.end(), 0);
}
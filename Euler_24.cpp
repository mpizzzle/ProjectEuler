#include <algorithm>
#include "Euler.h"

std::string Euler::LexicographicPermutations()
{
	std::string lexicon = "0123456789";

	for (int i = 1; i < 1e6; ++i)
		std::next_permutation(lexicon.begin(), lexicon.end());

	return lexicon;
}
#include "Euler.h"

int product(std::string champ, int pos)
{
	if (pos == 1)
		return 1;

	return (champ[pos - 1] - 48) * product (champ, pos / 10);
}

int Euler::ChampernowneConstant()
{
	std::string champernowne;

	for (int i = 1; i <= 1e6; ++i)
	{
		champernowne += std::to_string(i);

		if (champernowne.size() >= 1e6)
			break;
	}

	return product(champernowne, 1e6);
}
#include <algorithm>
#include <map>

#include "Euler.h"

llui Euler::CubicPermutations()
{
	std::map<std::string, std::vector<llui>> cubicGroups;

	for (llui i = 346;; ++i)
	{
		std::vector<int> cubeDigits = EulerUtility::lluiToDigits(i * i * i);
		std::sort(cubeDigits.begin(), cubeDigits.end());

		std::string key;

		for (int j : cubeDigits)
			key.push_back(j + '0');

		std::map<std::string, std::vector<llui>>::iterator it = cubicGroups.find(key);

		if (it == cubicGroups.end())
		{
			std::vector<llui> newGroup;
			newGroup.push_back(i * i * i);
			cubicGroups.insert(std::pair<std::string, std::vector<llui>>(key, newGroup));
		}
		else
		{
			it->second.push_back(i * i * i);

			if (it->second.size() == 5)
			{
				return it->second[0];
			}
		}
	}

	return 0;
}
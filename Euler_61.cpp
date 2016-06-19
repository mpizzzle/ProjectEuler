#include <numeric>

#include "Euler.h"

bool match(int a, int b)
{
	std::vector<int> digits_a = EulerUtility::intToDigits(a);
	std::vector<int> digits_b = EulerUtility::intToDigits(b);

	return (digits_a[2] == digits_b[0] && digits_a[3] == digits_b[1]);
}

int recurseFigurates(std::vector<int> cycle, std::vector<std::vector<int>> &figurates, std::vector<int> indices, int index)
{
	for (int swap_index = index + 1; swap_index < 7; ++swap_index)
	{
		for (int i : figurates[indices[index]])
		{
			if (match(cycle[cycle.size() - 1], i))
			{
				cycle.push_back(i);

				int answer = ((cycle.size() == 6) && (match(cycle[cycle.size() - 1], cycle[0]))) ?
					std::accumulate(cycle.begin(), cycle.end(), 0) : ((cycle.size() == 6) || (index >= 5)) ? 0 :
					recurseFigurates(cycle, figurates, indices, index + 1);

				if (answer != 0)
				{
					return answer;
				}

				cycle.pop_back();
			}
		}

		if (swap_index < 6)
		{
			int temp = indices[swap_index];
			indices.erase(indices.begin() + swap_index);
			indices.insert(indices.begin() + index, temp);
		}
	}

	return 0;
}

int Euler::CyclicFigurateNumbers()
{
	std::vector<std::vector<int>> figurates;
	std::vector<int> indices;
	std::vector<int> cycle;

	for (int i = 0; i < 6; ++i)
	{
		indices.push_back(i);
		figurates.push_back(EulerUtility::getFigurates(i + 3, 1000, 10000));
	}

	for (int i : figurates[0])
	{
		cycle.push_back(i);

		int answer = recurseFigurates(cycle, figurates, indices, 1);

		if (answer != 0)
		{
			return answer;
		}

		cycle.pop_back();
	}

	return 0;
}
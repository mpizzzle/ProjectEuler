#include "Euler.h"

int Euler::CodedTriangleNumbers()
{
	std::vector<std::string> names = EulerUtility::openWordFile("E:\\Euler Resources\\Euler 42.txt");

	int count = 0;

	for (std::string name : names)
	{
		int total = 0;

		for (char n : name)
			total += n - 64;

		if (EulerUtility::isTriangle(total))
			++count;
	}

	return count;
}
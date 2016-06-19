#include "Euler.h"

llui getTriangular(llui n)
{
	return (n * (n + 1)) / 2;
}

llui Euler::TriangularPentagonalHexagonal()
{
	for (int i = 286;; ++i)
	{
		llui tri = getTriangular(i);

		if ((i & 1) && EulerUtility::isPentagonal(tri))
			return tri;
	}

	return 0;
}
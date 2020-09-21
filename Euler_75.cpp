#include <algorithm>

#include "Euler.h"

int Euler::UniquePerimeterRightAngledTriangles()
{
    llui ceiling = 1500000;
    double sqrtCeiling = sqrt(ceiling);
    std::vector<int> perimeters(ceiling + 1, 0);

    for (llui m = 2; m <= sqrtCeiling; ++m)
    {
        for (llui n = 1; n < m; ++n)
        {
            if (((m - n) & 1) && (EulerUtility::gcd(m,n) == 1))
            {
                llui m2 = pow(m, 2);
                llui n2 = pow(n, 2);

                if (m2 + n2 >= ceiling)
                {
                    continue;
                }

                llui perimeter = (m2 - n2) + (2 * m * n) + (m2 + n2);

                int k = 1;

                while (perimeter * k <= ceiling)
                {
                    ++perimeters[perimeter * k];
                    ++k;
                }
            }
        }
    }

    return std::count(perimeters.begin(), perimeters.end(), 1);
}

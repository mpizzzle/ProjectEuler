#include "Euler.h"

bool valueOfDiophantine(cpp_int x, cpp_int y, cpp_int n)
{
    return EulerUtility::power(x, 2) - (n * EulerUtility::power(y, 2)) == cpp_int(1);
}

std::vector<cpp_int> recurseFraction(std::vector<cpp_int> period, cpp_int n, std::vector<cpp_int> fraction)
{
    if (n > period.size() - 1)
        return fraction;

    std::swap(fraction[0], fraction[1]);

    fraction[0] = (fraction[1] * period[period.size() - n.toInt() - 1]) + fraction[0];

    return recurseFraction(period, n + 1, fraction);
}

std::vector<cpp_int> recurseFraction(std::vector<cpp_int> period, cpp_int n)
{
    std::vector<cpp_int> fraction;

    fraction.push_back(period[period.size() - 1]);
    fraction.push_back(1);

    return recurseFraction(period, 1, fraction);
}

cpp_int valueOfX(cpp_int n)
{
    double n2 = std::sqrtl(n.toInt());
    cpp_int a = (int)n2, p = 0, q = 1;

    std::vector<cpp_int> period;
    std::vector<cpp_int> approx;

    period.push_back(a);

    do
    {
        p = a * q - p;
        q = ( n - p * p ) / q;
        a = (long)(( p.toLong() + n2 ) /q.toLong());
        
        period.push_back(a);
        approx = recurseFraction(period, 0);

    } while (valueOfDiophantine(approx[0], approx[1], n) != 1);

    return approx[0];
}

int Euler::Diophantine()
{
    cpp_int currentMax = 0;
    int valueOfD = 0;

    for (int i = 2; i <= 1000; ++i)
    {
        if (!EulerUtility::isPerfectSquare(i))
        {
            cpp_int x = valueOfX(i);

            if (x > currentMax)
            {
                currentMax = x;
                valueOfD = i;
            }
        }
    }

    return valueOfD;
}

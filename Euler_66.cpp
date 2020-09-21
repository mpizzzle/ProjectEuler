#include "Euler.h"

bool valueOfDiophantine(BigInteger x, BigInteger y, BigInteger n)
{
    return EulerUtility::power(x, 2) - (n * EulerUtility::power(y, 2)) == BigInteger(1);
}

std::vector<BigInteger> recurseFraction(std::vector<BigInteger> period, BigInteger n, std::vector<BigInteger> fraction)
{
    if (n > period.size() - 1)
        return fraction;

    std::swap(fraction[0], fraction[1]);

    fraction[0] = (fraction[1] * period[period.size() - n.toInt() - 1]) + fraction[0];

    return recurseFraction(period, n + 1, fraction);
}

std::vector<BigInteger> recurseFraction(std::vector<BigInteger> period, BigInteger n)
{
    std::vector<BigInteger> fraction;

    fraction.push_back(period[period.size() - 1]);
    fraction.push_back(1);

    return recurseFraction(period, 1, fraction);
}

BigInteger valueOfX(BigInteger n)
{
    double n2 = std::sqrtl(n.toInt());
    BigInteger a = (int)n2, p = 0, q = 1;

    std::vector<BigInteger> period;
    std::vector<BigInteger> approx;

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
    BigInteger currentMax = 0;
    int valueOfD = 0;

    for (int i = 2; i <= 1000; ++i)
    {
        if (!EulerUtility::isPerfectSquare(i))
        {
            BigInteger x = valueOfX(i);

            if (x > currentMax)
            {
                currentMax = x;
                valueOfD = i;
            }
        }
    }

    return valueOfD;
}

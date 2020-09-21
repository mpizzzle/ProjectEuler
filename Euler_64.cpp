//#include <boost/multiprecision/cpp_dec_float.hpp>

#include "Euler.h"

//namespace mp = boost::multiprecision;
//
//typedef mp::number<mp::cpp_dec_float<500>> cpp_dec_float_500;
//
//int Euler::OddPeriodSquareRoots()
//{
//    int count = 0;
//
//    for (cpp_dec_float_500 i = 1; i <= 10000; ++i)
//    {
//        int sequenceLength = 0;
//
//        cpp_dec_float_500 value = mp::sqrt(i);
//        cpp_dec_float_500 floor = mp::floor(value);
//
//        if (!EulerUtility::isPerfectSquare(i.convert_to<int>()))
//        {
//            bool sequenceDetermined = false;
//            bool sequenceIsOdd = false;
//
//            while (!sequenceDetermined)
//            {
//                value = 1.0 / (value - mp::floor(value));
//
//                if (mp::floor(value) == 2 * floor)
//                {
//                    sequenceDetermined = true;
//                    sequenceIsOdd = sequenceLength + 1 & 1;
//                }
//                else
//                {
//                    ++sequenceLength;
//                }
//            }
//
//            if (sequenceIsOdd)
//            {
//                ++count;
//            }
//        }
//    }
//
//    return count;
//}

int period(int n)
{
    double n2 = sqrtl(n);
    int a = n2, p = 0, q = 1, length = 0;

    do
    {
        length++;
        p = a * q - p;
        q = ( n - p * p ) / q;
        a = ( p + n2 ) /q;
    } while ( q != 1 );

    return length;
}

int Euler::OddPeriodSquareRoots()
{
    int odds = 0;

    for (int n = 1; n <= 10000; n++)
    {
        int n2 = sqrt(n);

        if (n2 * n2 != n)
        {
            if (period(n) & 1)
            {
                odds++;
            }
        }
    }

    return odds;
}

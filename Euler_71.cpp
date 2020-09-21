#include "Euler.h"

int Euler::OrderedFractions()
{
    //I did this problem by with pen + paper, but here was my thought process.
    //For me, this was the most obvious starting point for denominator d <= 1,000,000

    EulerUtility::gcd(299999, 700000); //gcd = 7

    //Ok, they aren't relatively prime; Divide them down.

    EulerUtility::gcd(42857, 100000);

    //At this point I noticed that this numerator was similar to the repeating decimal of 3/7 (0.(428571)*...).
    //I remembered that you can represent a repeating pattern as a fraction by taking the sequence and dividing it by nines
    //luckily the sequence allows for d <=1,000,000 (though in hindsight, the problem was most likely designed with
    //this property in mind).

    EulerUtility::gcd(428571, 999999); //equal to 3/7

    EulerUtility::gcd(428570, 999999); //Removed 1, noticed that gcd = 1. Therefore relatively prime, and since there is
                                       //no value of d larger except 1,000,000 itself (which seems very unlikely) then
                                       //it is probably the answer. If it wasn't, then it would narrow the answer down to
                                       //d = 1,000,000 which would be trivial to work out from there.

    int xmax = 0, xmaxd = 2;

    for (int d = 2; d <= 1000000; ++d)
    {
        int x = 3 * d / 7;

        if ((d % 7) == 0)
        {
            --x;
        }
        if (x * xmaxd > xmax * d)
        {
            xmax = x, xmaxd = d;
        }
    }

    return xmax; //As it happens, it was correct.
}
#include "Euler.h"

//def farey( n, asc=True ):
//    """Python function to print the nth Farey sequence, either ascending or descending."""
//    if asc: 
//        a, b, c, d = 0, 1,  1 , n     # (*)
//    else:
//        a, b, c, d = 1, 1, n-1, n     # (*)
//    print "%d/%d" % (a,b)
//    while (asc and c <= n) or (not asc and a > 0):
//        k = int((n + b)/d)
//        a, b, c, d = c, d, k*c - a, k*d - b
//        print "%d/%d" % (a,b)



llui Euler::CountingRangedFractions()
{
    llui count = 0;
    bool counting = false;

    int n = 12000;
    int a = 0;
    int b = 1;
    int c = 1;
    int d = n;
    int x = 0;

    while (c <= n && !(a == 1 && b == 2))
    {
        int k = 0;

        if (d != 0)
            k = int((n + b)/d);
        else
            ++x;

        int temp_a = a;
        int temp_b = b;

        a = c;
        b = d;
        c = k * c - temp_a;
        d = k * d - temp_b;

        if (counting)
            ++count;

        if (a == 1 && b == 3)
            counting = true;
    }

    return count - 1;
}
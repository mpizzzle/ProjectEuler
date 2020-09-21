#include "Euler.h"

llui Euler::SumOfPrimesUnder2m()
{
    bool is_prime;

    llui count = 2; //includes 2 & 3

    for(int i = 3; i < 2000000; i += 2)
    {
        is_prime = true;

        for(int j = 3; j * j <= i && is_prime; j += 2)
            if(i % j == 0) is_prime = false;

        if(is_prime) {
            count += i;
        }
    }

    return count;
}

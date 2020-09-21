#include "Euler.h"

int Euler::Get10001stPrime()
{
    bool is_prime;

    int count = 2; //includes 2 & 3
    int my_prime = 2; //set to first prime

    for(int i = 5; count < 1000000; i += 2)
    {
        is_prime = true;

        for(int j = 3; j * j <= i && is_prime; j += 2)
            if(i % j == 0) is_prime = false;

        if(is_prime) {
            ++count;
            my_prime = i;

            if (count == 10001)
                return i;
        }
    }

    return 0;
}

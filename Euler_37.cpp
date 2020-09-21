#include "Euler.h"

bool isTruncPrime(std::string &p, std::vector<int> &primes, bool left)
{
    bool isPrime = primes[atoi(p.c_str())] != -1;

    if (p.size() == 1)
        return isPrime;

    return (isPrime) ? isTruncPrime(p.substr(left, p.size() - 1), primes, left) : false;
}

llui Euler::TruncatablePrimes()
{
    std::vector<int> primes = EulerUtility::getPrimesUnderCeilingIndexed(1000000);
    llui sum = -17; //offset, since this algo does not exclude 2, 3, 5 and 7 of which the sum is 17

    for (int prime : primes)
        if (prime != -1)
        {
            std::string p = std::to_string(prime);
            if (isTruncPrime(p, primes, true) && isTruncPrime(p, primes, false))
                sum += prime;
        }

    return sum;
}
#include <algorithm>

#include "Euler.h"

int determinePanPrime(std::string lexicon)
{
    for (int i = 0; i < EulerUtility::factorial(lexicon.size()); ++i)
    {
        int potentialPanPrime = atoi(lexicon.c_str());
        int mod = potentialPanPrime % 10;

        if ((mod % 2 != 0) && (mod != 5))
            if (EulerUtility::isPrime(potentialPanPrime, 5))
                return potentialPanPrime;

        std::prev_permutation(lexicon.begin(), lexicon.end());
    }


    return determinePanPrime(lexicon.substr(1, lexicon.size() - 1));
}

int Euler::PanDigitalPrime()
{
    return determinePanPrime("987654321");
}
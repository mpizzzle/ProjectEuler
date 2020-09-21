#include "Euler.h"

long Euler::DigitFifthPowers()
{
    long sum = 0;

    for (int j = 0 ; j < 500000; ++j)
    {
        long currentPowerTotal = 0;

        std::string current = std::to_string(j);

        for (unsigned i = 0; i < current.length(); i++)
            currentPowerTotal += (int)pow(current.at(i) - 48, 5);

        if (j == currentPowerTotal)
            sum += currentPowerTotal;
    }

    return sum - 1;
}

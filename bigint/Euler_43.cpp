#include <algorithm>
#include <numeric>

#include "Euler.h"

void recursePermutations(std::string &current, std::vector<llui> &dps, std::vector<std::vector<std::string>> &psl, int pos)
{
    for (std::string s : psl[pos])
        if (s.substr(1, 2) == current.substr(0, 2))
        {
            if (current.find(s.substr(0, 1)) == std::string::npos)
            {
                std::string concat = s.substr(0, 1) + current;

                if (pos == 0)
                    dps.push_back(EulerUtility::digitsTollui(concat));
                else
                    recursePermutations(concat, dps, psl, pos - 1);
            }
        }
}

void findDivisiblePermutations(std::vector<llui> &dps, std::vector<std::vector<std::string>> &psl, int pos)
{
    for (std::string s : psl[pos])
        recursePermutations(s, dps, psl, pos - 1);

    for (unsigned i = 0; i < dps.size(); ++i)
        for (int j = 0; j <= 9; ++j)
            if (std::to_string(dps[i]).find(std::to_string(j)) == std::string::npos)
                dps[i] = EulerUtility::digitsTollui(std::to_string(j) + std::to_string(dps[i]));
}

BigInteger Euler::SubStringDivisibility()
{
    std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(18);
    std::vector<std::vector<std::string>> potentialSubLex(7, std::vector<std::string>());
    std::vector<llui> divisiblePermutations;

    for (int i = 0; i < 7; ++i)
        for (int j = 12; j <= 987; ++j)
            if ((j % primes[i] == 0) && (EulerUtility::hasUniqueDigits(j, true)))
                    potentialSubLex[i].push_back(((j < 100) ? "0" : "") + std::to_string(j));

    findDivisiblePermutations(divisiblePermutations, potentialSubLex, 6);

    BigInteger i = 0;

    for (unsigned long ul : divisiblePermutations)
        i += ul;

    return i;
}
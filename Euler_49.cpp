#include <algorithm>

#include "Euler.h"

std::string Euler::PrimePermutations()
{
    std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(10000);
    std::vector<std::vector<std::string>> primePermutations;

    for (int p : primes)
    {
        if (p >= 1000)
        {
            bool isUniquePermutation = true;
            std::string s = std::to_string(p);

            for (int i = 0; i < primePermutations.size(); ++i)
            {
                if (std::is_permutation(primePermutations[i][0].begin(), primePermutations[i][0].end(), s.begin()))
                {
                    isUniquePermutation = false;
                    primePermutations[i].push_back(s);
                }
            }

            if (isUniquePermutation)
                primePermutations.push_back(std::vector<std::string>(1, s));
        }
    }

    primePermutations[48] = std::vector<std::string>();

    for (std::vector<std::string> pp : primePermutations)
        if (pp.size() > 2)
            for (int i = 0; i < pp.size() - 2; ++i)
                for (int j = i + 1; j < pp.size() - 1; ++j)
                    for (int k = j + 1; k < pp.size(); ++k)
                        if ((atoi(pp[j].c_str()) * 2) - atoi(pp[i].c_str()) == atoi(pp[k].c_str()))
                            return pp[i] + pp[j] + pp[k];

    return nullptr;
}
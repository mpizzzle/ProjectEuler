#include <iostream>
#include <unordered_set>

#include "Euler.h"

uint64_t Euler::PrimePowerTriples()
{
    //what is the upper bound?
    //bc <<< "84^4 < 50000000"
    //bc <<< "368^3 < 50000000"
    //bc <<< "7071^2 < 50000000"

    std::vector<int> primes = EulerUtility::getPrimesUnderCeilingIndexed(7072);
    std::vector<uint64_t> cubes;
    std::vector<uint64_t> fourths;
    std::unordered_set<uint64_t> solutions;

    for (uint64_t i = 0; i < 369; ++i) {
          cubes.push_back(i * i * i);
          if (i < 85) {
              fourths.push_back(i * i * i * i);
          }
    }

    for (uint64_t i = 0; i < 7072; ++i) {
        if (primes[i] != -1) {
            for (uint64_t j = 0; j < 369; ++j) {
                if (primes[j] != -1) {
                    for (uint64_t k = 0; k < 85; ++k) {
                        if (primes[k] != -1) {
                            uint64_t candidate = (i * i) + cubes[j] + fourths[k];

                            if (candidate < 50000000) {
                                solutions.insert(candidate);
                            }
                        }
                    }
                }
            }
        }
    }

    return solutions.size();
}

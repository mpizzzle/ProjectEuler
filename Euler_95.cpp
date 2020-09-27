#include "Euler.h"

int sumProperDivisors(int n)
{
    int sum = 0;

    for(int k = 1; k <= n / 2; ++k)
    {
        if(n % k == 0)
        {
            sum += k;
        }
    }

    return sum;
}

int Euler::AmicableChains()
{
    int one_million = 1000000;
    int longest = 0;
    int solution = 0;

    std::vector<int> cache(one_million + 1, 0);

    for (int i = 0; i <= one_million; ++i) {
        cache[i] = sumProperDivisors(i);
        std::cout << i << std::endl;
    }

    std::cout << std::endl << "precalc done." << std::endl;

    for (int n = 1; n <= one_million; ++n) {
        int length = 0;
        int candidate = one_million;
        int slow_ptr = n;
        int fast_ptr = n;
        std::cout << n << ": ";

        while(true) {
            fast_ptr = cache[fast_ptr];

            if (fast_ptr <= 1 || fast_ptr > one_million) {
                std::cout << "no bueno." << std::endl;
                break;
            }

            if (slow_ptr == fast_ptr) {
                while (true) {
                    std::cout << slow_ptr << " -> ";
                    length++;
                    fast_ptr = cache[fast_ptr];

                    if (slow_ptr < candidate) {
                        candidate = slow_ptr;
                    }

                    if (slow_ptr == fast_ptr) {
                        if (length > longest) {
                            solution = candidate;
                            longest = length;
                            std::cout << "chicken dinner!" << std::endl;
                            std::cout << "current solution: " << solution << std::endl;
                            std::cout << std::endl << "current length: " << length << std::endl;
                        }
                        else {
                            std::cout << "not a winner." << std::endl;
                        }

                        cache[solution] = 0;
                        break;
                    }

                    slow_ptr = cache[slow_ptr];
                    fast_ptr = cache[fast_ptr];
                }

                break;
            }

            slow_ptr = cache[slow_ptr];
            fast_ptr = cache[fast_ptr];

            if (fast_ptr <= 1 || slow_ptr > one_million || fast_ptr > one_million) {
                std::cout << "no bueno." << std::endl;
                break;
            }
        }
    }

    return solution;
}

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
    int one_million = 200000;
    int longest = 0;
    int solution = 0;
    std::vector<int> divisors(one_million + 1, 0);

    for (int n = 0; n <= one_million; ++n) {
	std::cout << n << std::endl;
        divisors[n] = sumProperDivisors(n);
    }

    std::cout << std::endl << "precalc done." << std::endl;

    for (int n = 1; n <= one_million; ++n) {
        int length = 0;
        int candidate = one_million;
        int slow_ptr = n;
        int fast_ptr = n;
        std::cout << n << ": ";

        while(true) {
            length += 1;

            if (fast_ptr <= 1 || slow_ptr > one_million || fast_ptr > one_million) {
                std::cout << "no bueno." << std::endl;
                break;
            }

            fast_ptr = divisors[fast_ptr];

            if (slow_ptr < candidate) {
                candidate = slow_ptr;
            }

            if (slow_ptr == fast_ptr) {
                if (length > longest) {
                    solution = candidate;
                    longest = length;
                    std::cout << "chicken dinner!" << std::endl;
                    std::cout << "current solution: " << solution << std::endl;

                    int blerp = n;
                    int fast_blerp = divisors[n];

                    std::cout << n << " -> ";// << std::endl;
                    while (blerp != fast_blerp) {
                        blerp = divisors[blerp];
                        fast_blerp = divisors[divisors[fast_blerp]];
                        std::cout << blerp << " -> ";// << std::endl;
                    }

                    std::cout << std::endl << "current length: " << length << std::endl;
                }
                else {
                    std::cout << "not a winner." << std::endl;
                }

		divisors[solution] = 1;
                break;
            }

            slow_ptr = divisors[slow_ptr];
            fast_ptr = divisors[fast_ptr];
        }
    }

    return (int)solution;
}

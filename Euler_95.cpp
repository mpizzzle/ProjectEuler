#include "Euler.h"

int Euler::AmicableChains()
{
    int one_million = 1000000;
    int longest = 0;
    int solution = 0;
    double root = floor(sqrt(one_million)) + 1;

    std::vector<int> divisors(one_million + 1, 1);

    for (int i = 2; i < root; ++i) {
        for (int j = 2; i * j <= one_million; ++j) {
            divisors[i * j] += i + ((j >= root) ? j : 0);
	}
    }

    for (int n = 1; n <= one_million; ++n) {
        int length = 0;
        int candidate = one_million;
        int slow_ptr = n;
        int fast_ptr = n;

        while(true) {
            fast_ptr = divisors[fast_ptr];

            if (fast_ptr <= 1 || fast_ptr > one_million) {
                break;
            }

            if (slow_ptr == fast_ptr) {
                while (true) {
                    length++;
                    fast_ptr = divisors[fast_ptr];

                    if (slow_ptr < candidate) {
                        candidate = slow_ptr;
                    }

                    if (slow_ptr == fast_ptr) {
                        if (length > longest) {
                            solution = candidate;
                            longest = length;
                        }

			divisors[candidate] = 1;
                        break;
                    }

                    slow_ptr = divisors[slow_ptr];
                    fast_ptr = divisors[fast_ptr];
                }

                break;
            }

            slow_ptr = divisors[slow_ptr];
            fast_ptr = divisors[fast_ptr];

            if (fast_ptr <= 1 || slow_ptr > one_million || fast_ptr > one_million) {
                break;
            }
        }
    }

    return solution;
}

#include "Euler.h"

uint64_t Euler::CuboidRoute()
{
    for (int M = 100;; ++M) { 
        uint64_t solutions = 0;

        for (int sp = 1; sp < sqrt(pow(M + M, 2) + pow(M, 2)); ++sp) {
            for (int i = 1; i < sp; ++i) {
                double c = sqrt((sp * sp) - (i * i));

                if (c == (int)c && (int)c <= M) {
                   for (int j = 1; j <= i / 2; ++ j) {
                       if (j <= M && (i - j) <= M && (i - j) <= c) {
                            //std::cout << "(" << j << " + " << i - j << ")² + " << (int)c << "² = " << sp << "²" << std::endl;
                            solutions += 1;
                       }
                    }
                }
            }
        }

        if (solutions > 1000000) {
            return M;
        }
    }

    return 0;
}

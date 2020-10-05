#include "Euler.h" 

int Euler::ArithmeticExpressions() {
    int a = 1, b = 2, c = 3, d = 4;
 
    for (a = 1; a < b; ++a) {
        for (b = a + 1; b < c; ++b) {
            for (c = b + 1; c < d; ++c) {
                for (d = c + 1; d < 10; ++d) {
                        std::cout << a << b << c << d << std::endl;
                }
            }
        }
    }
    return 0;
}

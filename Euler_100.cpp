#include "Euler.h"

// (15 / 21) * (14 / 20) = 1 / 2
// (5 / 7) * (7 / 10) = 1 / 2
// x = 3, y = 2, a = 5, b = 7 all primes?
// (a / b) * (b / 2a) = 1 / 2
//
// solution = min(x * a) where x * b > 10^12
// and x * b = (y * 2a) + 1
// and (a / b) * (b / 2a) = 1 / 2
// or bx = 2ay + 1
//
// ((a * x) / (b * x)) * ((b * y) / (2 * a * y)) = 1 / 2
// (a * x) / (b * x)  = 1 / (2 * ((b * y) / (2 * a * y)))
// b * x = (a * x) / (1 / (2 * ((b * y) / (2 * a * y))))

// sub x * b = (y * 2a) + 1
// (y * 2 * a) + 1 = (a * x) / (1 / (2 * ((b * y) / (2 * a * y))))
// (y * 2 * a) + 1 = (a * x) / (1 / (2 * (b / (2 * a))))
// (y * 2 * a) + 1 = (a * x) / (1 / (b / a))
// (y * 2 * a) + 1 = (a * x) / (a / b))
// (y * 2 * a) + 1 = b * x // lol, ok different approach

// ((a * x) / (b * x)) * (((a * x) - 1) / ((b * x) - 1)) = 1 / 2
// (a / b) * (((a * x) - 1) / ((b * x) - 1)) = 1 / 2
// ((a * ((a * x) - 1)) / (b * ((b * x) - 1))) = 1 / 2
// ((((a ^ 2) * x) - a) / (((b ^ 2) * x) - b)) = 1 / 2

// a < b
//
// (85 / 120) * (84 / 119) = 1 / 2
// (17 / 24) * (12 / 17) = 1 / 2
// (a / 2b) * (b / a) = 1 / 2
// x = 5, y = 7, a = 17, b = 12 (x and y always prime? co-prime?)
//
// a > b
//
// solution = min(x * a) where x * 2b > 10^12
// and x * 2b = (y * a) + 1
// or 2bx = ay + 1
//
// can I derive x * a in terms of anything?
// I doubt it unless we make some assumptions about the relationship between x and y
// (e.g. assume they are always contiguous primes)
//
// lets say
// x = 11, y = 13 
// there may be a solution for either
// 11b = 26a + 1
// 22b = 13a + 1
// b = (26a + 1) / 11 e.g. if 26a + 1 % 11 == 0 then we have a, plug back in a to get b
// found a solution a = 8, b = 19
// therefore 11 * 8 / 11 * 19 is a valid solution? apparently not.
// found a solution a = 690, b = 1631
// is 11 * 690 / 11 * 1631 a valid solution? nope. lets try the other equation
// b = (13a + 1) / 22 e.g. if (13a + 1) % 22 == 0 then we have a, plug back in a to get b
// found a solution a = 5, b = 6
// is (11 * 5) / (2 * 11 * 6) a solution? I can already see it's going to be less than 1/2.
// found a solution a = 995, b = 1176
// "((11 * 995) / (2 * 11 * 1176)) * (((11 * 995) - 1) / ((2 * 11 * 1176) - 1))" = .17895697570126191251
//
// this doesn't seem to be a good way of identifying solutions without more constraints.
// time for wikipedia

uint64_t Euler::ArrangedProbability()
{
    std::vector<int> a;
    std::vector<int> b;

    for (int i = 0; i < 1000; ++i) {
        if (((13 * i) + 1) % 22 == 0) {
            a.push_back(i);
            b.push_back(((13 * i) + 1) / 22);
        }
    }

    return 0;
}

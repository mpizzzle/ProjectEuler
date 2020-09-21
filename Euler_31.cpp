#include "Euler.h"

int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};

int coinSumRecurse(int money, int maxcoin)
{
    int sum = 0;

    if(maxcoin == 7)
        return 1;

    for(int i = maxcoin; i < 8; i++)
    {
        if (money - coins[i] == 0)
            ++sum;
        if (money - coins[i] > 0)
            sum += coinSumRecurse(money - coins[i], i);
    }

    return sum;     
}

int Euler::CoinSums()
{
    return coinSumRecurse(200, 0);   
}

//int Euler::CoinSums() //original solution
//{
//    int sum = 0;
//
//    for (int a = 0; a <= 200; ++a)
//        for (int b = 0; b <= 100; ++b)
//            for (int c = 0; c <= 40; ++c)
//                for (int d = 0; d <= 20; ++d)
//                    for (int e = 0; e <= 10; ++e)
//                        for (int f = 0; f <= 5; ++f)
//                            for (int g = 0; g <= 2; ++g)
//                                if (a + b * 2 + c * 5 + d * 10 + e * 20 + f * 50 + g * 100 == 200)
//                                    ++sum;
//
//    return sum + 1;
//}
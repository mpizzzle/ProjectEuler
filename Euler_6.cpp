#include "Euler.h"

int Euler::DifferenceSumOfSquaresSquareOfSum100()
{
    int sumOfSquares = 0;
    int squareOfSum = 0;

    for (int i = 1; i <= 100; ++i) {
        squareOfSum += i;
        sumOfSquares += (int)pow(i, 2);
    }

    squareOfSum = (int)pow(squareOfSum, 2);
    return squareOfSum - sumOfSquares;
}
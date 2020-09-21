#include <fstream>

#include "Euler.h"

void SumDigits(std::vector<int> &digits, int &greatestProduct)
{
    int temp = digits[0];

    for(unsigned int j = 1; j < digits.size(); ++j)
        temp *= digits[j];

    if (temp > greatestProduct)
        greatestProduct = temp;
}

int Euler::LargestProductInGrid()
{
    std::ifstream fin;
    fin.open("files/p11_grid.txt");
    std::string grid;
    std::getline(fin, grid);
    fin.close();

    std::vector<int> numGrid = EulerUtility::tokenizer(grid, ' ');

    int greatestProduct = 0;

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j <= 20 - 4; ++j)
        {
            std::vector<int> digits;

            for (int k = 0; k < 4; ++k)
                digits.push_back(numGrid[i * 20 + j + k]);

            SumDigits(digits, greatestProduct);
        }
    }

    for (int i = 0; i <= 20 - 4; ++i){
        for (int j = 0; j < 20; ++j)
        {
            std::vector<int> digits;

            for (int k = 0; k < 4; ++k)
                digits.push_back(numGrid[i + j * 20 + k]);

            SumDigits(digits, greatestProduct);
        }
    }

    for (int i = 0; i < 20 - 4; ++i) {
        for (int j = 0; j <= 20 - 4; ++j)
        {
            std::vector<int> digits;

            for (int k = 0; k < 4; ++k)
                digits.push_back(numGrid[(i + k) * 20 + j + k]);

            SumDigits(digits, greatestProduct);
        }
    }

    for (int i = 0; i < 20 - 4; ++i) {
        for (int j = 19; j >= 3; --j)
        {
            std::vector<int> digits;

            for (int k = 0; k < 4; ++k)
                digits.push_back(numGrid[(i + k) * 20 + j - k]);

            SumDigits(digits, greatestProduct);
        }
    }

    return greatestProduct;
}

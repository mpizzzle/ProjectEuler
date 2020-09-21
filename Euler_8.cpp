#include <fstream>

#include "Euler.h"

llui Euler::FindGreatestProductOf13AdjacentDigits()
{
    std::ifstream fin;
    fin.open("files/p8_digits.txt");

    std::string number;

    std::getline(fin, number);

    fin.close();

    llui greatestProduct = 0;

    for (unsigned i = 0; i < number.length() - 13; ++i)
    {
        std::vector<int> digits;

        llui temp = 1;

        for (unsigned j = i; j < i + 13; ++j)
            temp *= (number.at(j) - 48);

        if (temp > greatestProduct) {
            greatestProduct = temp;
        }
    }

    return greatestProduct;
}

#include "Euler.h"

int digit(std::string digits[], std::string teens[], int j, int k)
{
    return (k > 0) ? ((j == 1) ? teens[k - 1].length() : digits[k - 1].length()) : 0;
}

int tenz(int ten, int j, int k)
{
    return (j == 1) ? ((k == 0) ? ten : 0) : ten;
}

int _and(int count)
{
    return ((count >= 100) && (count % 100 != 0)) ? std::string("and").length() : 0;
}

int x_hundred(std::string digits[], int i)
{
    return (i > 0) ? digits[i - 1].length() + std::string("hundred").length() : 0; //x hundred
}

int Euler::LetterCounter()
{
    std::string digits[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string teens[] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string tens[] = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int sum = digits[0].length() + std::string("thousand").length(); //one thousand

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k)
                sum += x_hundred(digits, i) + _and(i * 100 + j * 10 + k) + tenz(tens[j].length(), j, k) + digit(digits, teens, j, k);

    return sum;
}

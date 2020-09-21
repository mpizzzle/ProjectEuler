#include <sstream>

#include "Euler.h"

bool isPalindrome(cpp_int i)
{
    std::ostringstream oss;
    oss << i;

    std::string temp = oss.str();

    for (unsigned int j = 0; j < temp.length() / 2 + 1; ++j)
        if (temp.at(j) != temp.at(temp.length() - 1 - j))
            return false;

    return true;
}

cpp_int reverse(cpp_int i)
{
    cpp_int reverse = 0;

    while(i > 0)
    {
        reverse = reverse * 10 + (i % 10);
        i /= 10;
    }

    return reverse;
}

cpp_int Euler::LychrelNumbers()
{
    int lychel = 9999;

    for (int i = 1; i < 10000; ++i)
    {
        cpp_int current(i);

        for (int j = 0; j < 50; ++j)
        {
            current = current + reverse(current);

            if (isPalindrome(current))
            {
                --lychel;
                break;
            }
        }
    }

    return lychel;
}
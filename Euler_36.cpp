#include <bitset>
#include <sstream>

#include "Euler.h"

bool isPalindrome(std::string &n)
{
    for (unsigned int i = 0; i < n.length(); ++i)
        if (n.at(i) != n.at(n.length() - 1 - i))
            return false;

    return true;
}

bool isPalindromeInTwoBases(int i)
{
    std::ostringstream oss;
    oss << i;

    std::string b10 = oss.str();

    if (!isPalindrome(b10))
        return false;

    std::string b2 = std::bitset<32>(i).to_string();
    b2 = b2.substr(b2.find('1'));

    return isPalindrome(b2);
}

llui Euler::DoubleBasedPalindromes()
{
    llui sum = 0;

    for (int i = 1; i < 1e6; ++i)
        if (isPalindromeInTwoBases(i))
            sum += i;

    return sum;
}
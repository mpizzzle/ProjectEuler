#include <algorithm>
#include <fstream>
#include <set>

#include "Euler.h"

std::string Euler::PasscodeDerivation()
{
    std::ifstream fin;
    std::vector<std::string> numbers;

    fin.open("E:\\Euler Resources\\Euler 79.txt");

    std::string temp;
    while(std::getline(fin, temp))
        numbers.push_back(temp);

    fin.close();
    
    std::set<char> tokens;

    for (std::string n : numbers)
        for (char c : n)
            tokens.insert(c);

    std::string passcode(tokens.begin(),tokens.end());

    for (std::string n : numbers)
    {
        int i = std::find(passcode.begin(), passcode.end(), n[0]) - passcode.begin();
        int j = std::find(passcode.begin(), passcode.end(), n[1]) - passcode.begin();    
        int k = std::find(passcode.begin(), passcode.end(), n[2]) - passcode.begin();

        if (i > j)
            std::swap(passcode[i], passcode[j]);

        if (j > k)
            std::swap(passcode[j], passcode[k]);
    }

    return passcode;
}

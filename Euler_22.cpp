#include <algorithm>

#include "Euler.h"

llui Euler::NameScores()
{
    std::vector<std::string> names = EulerUtility::openWordFile("files/p022_names.txt");
    std::sort(names.begin(), names.end());

    llui sum = 0;
    int count = 0;

    for (std::string name : names)
    {
        int namesum = 0;

        for (char n : name)
            namesum += n - 64;

        sum += namesum * ++count;
    }

    return sum;
}

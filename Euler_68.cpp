#include <algorithm>
#include <set>
#include "Euler.h"

std::string magicString(std::vector<int**> rows)
{
    int lowestIndex = 0;
    int lowestVal = 11;

    for (int i = 0; i < 5; ++i)
    {
        if (*rows[i][0] < lowestVal)
        {
            lowestVal = *rows[i][0];
            lowestIndex = i;
        }
    }

    std::string magic5;

    for (int i = 0; i < 5; ++i)
    {
        int index = (i + lowestIndex) % 5;

        if ( *rows[index][0] == 10)
        {
            magic5.push_back('1');
            magic5.push_back('0');
        }
        else
        {
            magic5.push_back(*rows[index][0] + '0');
        }

        magic5.push_back(*rows[index][1] + '0');
        magic5.push_back(*rows[index][2] + '0');
    }

    return magic5;
}

int sumRow(int* row[])
{
    return *row[0] + *row[1] + *row[2];
}

std::string Euler::Magic5GonRing()
{
    std::vector<int> nodes;
    std::set<std::string> magicStrings;

    for (int i = 1; i <= 10; ++i)
        nodes.push_back(i);

    int* row1[] = { &nodes[0], &nodes[1], &nodes[2] };
    int* row2[] = { &nodes[3], &nodes[2], &nodes[4] };
    int* row3[] = { &nodes[5], &nodes[4], &nodes[6] };
    int* row4[] = { &nodes[7], &nodes[6], &nodes[8] };
    int* row5[] = { &nodes[9], &nodes[8], &nodes[1] };

    std::vector<int**> rows;

    rows.push_back(row1);
    rows.push_back(row2);
    rows.push_back(row3);
    rows.push_back(row4);
    rows.push_back(row5);

    for (int i = 1; i < EulerUtility::factorial(10); ++i)
    {
        std::next_permutation(nodes.begin(), nodes.end());

        int val = sumRow(row1);

        if ((*row1[0] == 10 || *row2[0] == 10 || *row3[0] == 10 || *row4[0] == 10 || *row5[0] == 10)
            && ((sumRow(row2) == val) && (sumRow(row3) == val) && (sumRow(row4) == val) && (sumRow(row5) == val)))
            magicStrings.insert(magicString(rows));
    }

    std::set<std::string>::iterator it;
    std::string last;

    for (it = magicStrings.begin(); it != magicStrings.end(); ++it)
        last = *it;

    return last;
}
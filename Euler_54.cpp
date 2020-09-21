#include <algorithm>
#include <fstream>
#include <functional>
#include <unordered_set>

#include "Euler.h"

struct hand
{
    int handValue;
    std::vector<int> cardValues;
};

struct game
{
    hand hands[2];
};

char order[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

bool isFlush(std::vector<std::string>& hand)
{
    char c = hand[0][1];

    for (int i = 1; i < hand.size(); ++i)
        if (hand[i][1] != c)
            return false;

    return true;
}

bool isStraight(std::vector<int> indices)
{
    for (int i = 1; i < indices.size(); ++i)
        if (indices[i] != indices[i - 1] - 1)
            return false;

    return true;
}

std::vector<int> getCardValues(std::vector<std::string>& hand)
{
    std::vector<int> indices;

    for (int i = 0; i < hand.size(); ++i)
        for (int j = 0; j < 13; ++j)
        {
            char c = hand[i][0];
            if (c == order[j])
            {
                indices.push_back(j);
                break;
            }
        }

        std::sort(indices.begin(), indices.end(), std::greater<int>());

        return indices;
}

int determineNoOfRepeats(std::unordered_set<int>& us, std::vector<int>& cardValues, int t, int def, int high)
{
    for (int j : us)
    {
        int total = 0;

        for (int k = 0; k < cardValues.size(); ++k)
            if (j == cardValues[k])
                ++total;

        if (total == t)
            return high;
    }

    return def;
}

int determineRepeat(std::unordered_set<int>& us, std::vector<int>& cardValues, int rep, bool skip)
{
    for (int j : us)
    {
        int total = 0;

        for (int k = 0; k < cardValues.size(); ++k)
            if (j == cardValues[k])
                ++total;

        if (total == rep)
        {
            if (skip)
                skip = false;
            else
                return j;
        }
    }

    return -1;
}

void determinePriorityOrder(hand& h, std::unordered_set<int>& us)
{
    if (h.handValue == 4 || h.handValue == 0)
        return;

    std::vector<int> values(h.cardValues);
    int rep1, rep2, no = 0;

    switch(h.handValue)
    {
    case 1:
        rep1 = determineRepeat(us, h.cardValues, 2, false);

        for (int i = 0; i < h.cardValues.size(); ++i)
            if (h.cardValues[i] == rep1)
                std::swap(h.cardValues[no++], h.cardValues[i]);

        std::sort(h.cardValues.begin() + 2, h.cardValues.end(), std::greater<int>());
        break;
    case 2:
        rep1 = determineRepeat(us, h.cardValues, 2, true);
        rep2 = determineRepeat(us, h.cardValues, 2, false);

        if (rep2 > rep1)
            std::swap(rep1, rep2);

        for (int i = 0; i < h.cardValues.size(); ++i)
        {
            if (h.cardValues[i] == rep1)
                std::swap(h.cardValues[no++], h.cardValues[i]);
        }

        for (int i = 0; i < h.cardValues.size(); ++i)
            if (h.cardValues[i] == rep2)
                std::swap(h.cardValues[no++], h.cardValues[i]);
        break;
    case 3:
        rep1 = determineRepeat(us, h.cardValues, 3, false);

        for (int i = 0; i < h.cardValues.size(); ++i)
            if (h.cardValues[i] == rep1)
                std::swap(h.cardValues[no++], h.cardValues[i]);

        std::sort(h.cardValues.begin() + 3, h.cardValues.end(), std::greater<int>());
        break;
    case 6:
        rep1 = determineRepeat(us, h.cardValues, 3, false);
        for (int i = 0; i < h.cardValues.size(); ++i)
            if (h.cardValues[i] == rep1)
                std::swap(h.cardValues[no++], h.cardValues[i]);

        break;
    case 7:
        rep1 = determineRepeat(us, h.cardValues, 4, false);

        for (int i = 0; i < h.cardValues.size(); ++i)
            if (h.cardValues[i] == rep1)
                std::swap(h.cardValues[no++], h.cardValues[i]);
        break;
    }
}

game determineHands(std::vector<std::string>& cards)
{
    game g;

    std::vector<std::string> hands[2];

    hands[0] = std::vector<std::string>(cards.begin(), cards.begin() + 5);
    hands[1] = std::vector<std::string>(cards.begin() + 5, cards.end());

    for (int i = 0; i < 2; ++i)
    {
        g.hands[i].cardValues = getCardValues(hands[i]);

        if (isFlush(hands[i]))
        {
            g.hands[i].handValue = isStraight(g.hands[i].cardValues) ? (g.hands[i].cardValues[4] == 12 ? 9 : 8) : 5;
        }
        else
        {
            std::unordered_set<int> us;

            for (int j : g.hands[i].cardValues)
                us.insert(j);

            switch(us.size())
            {
            case 2:
                g.hands[i].handValue = determineNoOfRepeats(us, g.hands[i].cardValues, 4, 6, 7);
                break;
            case 3:
                g.hands[i].handValue = determineNoOfRepeats(us, g.hands[i].cardValues, 3, 2, 3);
                break;
            case 4:
                g.hands[i].handValue = 1;
                break;
            case 5:
                g.hands[i].handValue = isStraight(g.hands[i].cardValues) ? 4 : 0;
                break;
            }

            determinePriorityOrder(g.hands[i], us);
        }


    }

    return g;
}

bool determineWinner(game g) //assumes no draws
{
    if (g.hands[0].handValue > g.hands[1].handValue)
        return false;

    if (g.hands[1].handValue > g.hands[0].handValue)
        return true;

    for (int i = 0; i < g.hands[0].cardValues.size(); ++i)
    {
        if (g.hands[0].cardValues[i] > g.hands[1].cardValues[i])
            return false;

        if (g.hands[1].cardValues[i] > g.hands[0].cardValues[i])
            return true;
    }

    return true;
}

int Euler::PokerHands()
{
    int scores[2] = {0, 0};

    std::ifstream fin;
    fin.open("E:\\Euler Resources\\Euler 54.txt");
    int idx = 0;

    for (std::string line; std::getline(fin, line);)
        ++scores[determineWinner(determineHands(EulerUtility::strTokenizer(line, ' ')))];

    fin.close();

    return scores[0];
}
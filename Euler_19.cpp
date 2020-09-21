#include "Euler.h"

int daysInFebruary(int year)
{
    return (year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? 29 : 28) : 29) : 28;
}

int Euler::SundayCount()
{
    int weekday = 1;
    int sundays = 0;

    for (int year = 1900; year <= 2000; ++year)
    {
        int months[] = {31, daysInFebruary(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (int month : months)
        {
            for (int day = 0; day < month; ++day)
            {
                if ((weekday == 0) && (day == 0) && (year > 1900))
                    ++sundays;

                ++weekday %= 7;
            }
        }
    }

    return sundays;
}
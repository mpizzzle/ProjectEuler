#include "Euler.h"

int Euler::PanDigitalMultiples()
{
    int greatestPanDigitalMultiple = 918273645;

    for (int i = 9182; i < 9876; ++i) //9182 is the first 4 digits of the above no, 9876 is the int with unique digits < 10000
    {
        if (EulerUtility::hasUniqueDigits(i, false))
        {
            if (EulerUtility::hasUniqueDigits(i * 2, false))
            {
                int potentialPanDigital = atoi((std::to_string(i) + std::to_string(i * 2)).c_str());

                if ((EulerUtility::hasUniqueDigits(potentialPanDigital, false)) && (potentialPanDigital > greatestPanDigitalMultiple))
                    greatestPanDigitalMultiple = potentialPanDigital;
            }
        }
    }

    return greatestPanDigitalMultiple;
}
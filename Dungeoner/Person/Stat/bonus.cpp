#include "bonus.h"

Bonus::Bonus(int value, bool isPercentage)
{
    this->value = value;
    this->isPercentage = isPercentage;
}

Bonus::Bonus()
{
    value = 0;
    isPercentage = false;
}

int Bonus::getValue() const
{
    return value;
}

void Bonus::setValue(int newValue)
{
    value = newValue;

    if(value > 9999999)
        value = 9999999;
    else if(value < -9999999)
        value = -9999999;
}

bool operator ==(const Bonus& bonus1, const Bonus& bonus2)
{
    return (bonus1.value==bonus2.value)&&(bonus1.isPercentage==bonus2.isPercentage);
}

bool operator !=(const Bonus& bonus1, const Bonus& bonus2)
{
    return !((bonus1.value==bonus2.value)&&(bonus1.isPercentage==bonus2.isPercentage));
}

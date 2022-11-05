#include "magicdefensebonus.h"

MagicDefenseBonus::MagicDefenseBonus(DynamicPosition dynamicPosition, int value, bool isPercentage)
{
    this->dynamicPosition = dynamicPosition;
    setValue(value);
    this->isPercentage = isPercentage;

    isDynamic = true;
    isBonusChunk = false;
}

MagicDefenseBonus::MagicDefenseBonus(int staticPosition, int value, bool isPercentage)
{
    setValue(value);
    this->isPercentage = isPercentage;
    this->staticPosition = staticPosition;

    isDynamic = false;
    isBonusChunk = false;
}

MagicDefenseBonus::MagicDefenseBonus(QVector<int> bonusChunksMaxVales)
{
    this->bonusChunksMaxVales = bonusChunksMaxVales;

    isBonusChunk = true;
}

int MagicDefenseBonus::getValue() const
{
    return value;
}

void MagicDefenseBonus::setValue(int newValue)
{
    value = newValue;

    if(value>10000)
        value = 10000;
    else if(value<-10000)
        value = -10000;
}

QVector<int> MagicDefenseBonus::getBonusChunksMaxVales() const
{
    return bonusChunksMaxVales;
}

void MagicDefenseBonus::setBonusChunksMaxVales(const QVector<int> &newBonusChunksMaxVales)
{
    bonusChunksMaxVales = newBonusChunksMaxVales;
}

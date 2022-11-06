#include "magicdefensebonus.h"
#include "qdebug.h"

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

bool operator == (const MagicDefenseBonus& bonus1, const MagicDefenseBonus& bonus2){
        bool dynamicPositionMatch;
        if(bonus1.isDynamic == false && bonus2.isDynamic == false)
            dynamicPositionMatch = true;
        else
            dynamicPositionMatch = bonus1.dynamicPosition == bonus2.dynamicPosition;
    return (bonus1.isDynamic == bonus2.isDynamic && bonus1.isPercentage == bonus2.isPercentage &&
                bonus1.isBonusChunk == bonus2.isBonusChunk && dynamicPositionMatch &&
                bonus1.staticPosition == bonus2.staticPosition && bonus1.value == bonus2.getValue() &&
                bonus1.bonusChunksMaxVales == bonus2.bonusChunksMaxVales);
}

bool operator != (const MagicDefenseBonus& bonus1, const MagicDefenseBonus& bonus2){
        bool dynamicPositionMatch;
        if(bonus1.isDynamic == false && bonus2.isDynamic == false)
            dynamicPositionMatch = true;
        else
            dynamicPositionMatch = bonus1.dynamicPosition == bonus2.dynamicPosition;
    return !(bonus1.isDynamic == bonus2.isDynamic && bonus1.isPercentage == bonus2.isPercentage &&
                bonus1.isBonusChunk == bonus2.isBonusChunk && dynamicPositionMatch &&
                bonus1.staticPosition == bonus2.staticPosition && bonus1.value == bonus2.getValue() &&
                bonus1.bonusChunksMaxVales == bonus2.bonusChunksMaxVales);
}

/***********************************************************************************
 *Данный класс является бонусом для магической защиты. Есть 3 типа бонусов:
 *
 *1)Бонус на динамической позиции. Есть 4 таких позиции: первый, последний,
 *центральный и все. Такой бонус прибавляет своё значение (процентное или
 *абсолютное) к указанному РОДНОМУ чанку магической защиты.
 *
 *2)Бонус на статической позиции. В него передаётся конкретный индекс
 *(начиная с 1) чанка магической защиты. Такой бонус прибавляет своё значение
 *(процентное или абсолютное) к указанному РОДНОМУ чанку магической защиты.
 *Если чанка с указанным индексом несуществует не происходит ничего.
 *
 *3)Бонусные чанки. В конструктор передаётся вектор максимальных значений новых
 *чанков. Такие чанки дабавляются после всех остальных, и на них нельзя повесить
 *другие бонусы.
 *
 *Также в классе реализованы операторы сравнения. Не смотря на название
 *может быть и отрицательным, а не только положительным.
 ***********************************************************************************/

#include "magicdefensebonus.h"

//Конструктор для бонуса на динамической позиции
MagicDefenseBonus::MagicDefenseBonus(DynamicPosition dynamicPosition, int value, bool isPercentage)
{
    this->dynamicPosition = dynamicPosition;
    setValue(value);
    this->isPercentage = isPercentage;

    isDynamic = true;
    isBonusChunk = false;
}

//Конструктор для бонуса на статической позиции
MagicDefenseBonus::MagicDefenseBonus(int staticPosition, int value, bool isPercentage)
{
    setValue(value);
    this->isPercentage = isPercentage;
    this->staticPosition = staticPosition;

    isDynamic = false;
    isBonusChunk = false;
}

//Конструктор для бонусных чанков
MagicDefenseBonus::MagicDefenseBonus(QVector<int> bonusChunksMaxVales)
{
    this->bonusChunksMaxVales = bonusChunksMaxVales;

    isDynamic = false;
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
    /*Если бонусы сатические, то совпадение динамической позиции неважно, оно
     *указывается как true, ведь этих позиций по факту нет у обоих бонусов*/
    if(bonus1.isDynamic == false && bonus2.isDynamic == false)
        dynamicPositionMatch = true;
    else
        dynamicPositionMatch = bonus1.dynamicPosition == bonus2.dynamicPosition;

    bool staticPositionMatch;
    /*Если бонусы динамические, то совпадение статической позиции неважно, оно
     * указывается как true, ведь этих позиций по факту нет у обоих бонусов*/
    if(bonus1.isDynamic == true && bonus2.isDynamic == true)
        staticPositionMatch = true;
    else
        staticPositionMatch = bonus1.staticPosition == bonus2.staticPosition;

    /*Если у обоих бонусов не пуст вектор бонусных чанков, то значит, что статические
     *и динамические позиции неважны, ведь этих позиций по факту нет у обоих бонусов*/
    if(!bonus1.bonusChunksMaxVales.isEmpty() && !bonus1.bonusChunksMaxVales.isEmpty())
        if(bonus1.bonusChunksMaxVales == bonus1.bonusChunksMaxVales){
            dynamicPositionMatch = true;
            staticPositionMatch = true;
        }

    return (bonus1.isDynamic == bonus2.isDynamic && bonus1.isPercentage == bonus2.isPercentage &&
            bonus1.isBonusChunk == bonus2.isBonusChunk && dynamicPositionMatch &&
            staticPositionMatch && bonus1.value == bonus2.getValue() &&
            bonus1.bonusChunksMaxVales == bonus2.bonusChunksMaxVales);
}

bool operator != (const MagicDefenseBonus& bonus1, const MagicDefenseBonus& bonus2){
    bool dynamicPositionMatch;
    /*Если бонусы сатические, то совпадение динамической позиции неважно, оно
     *указывается как true, ведь этих позиций по факту нет у обоих бонусов*/
    if(bonus1.isDynamic == false && bonus2.isDynamic == false)
        dynamicPositionMatch = true;
    else
        dynamicPositionMatch = bonus1.dynamicPosition == bonus2.dynamicPosition;

    bool staticPositionMatch;
    /*Если бонусы динамические, то совпадение статической позиции неважно, оно
     * указывается как true, ведь этих позиций по факту нет у обоих бонусов*/
    if(bonus1.isDynamic == true && bonus2.isDynamic == true)
        staticPositionMatch = true;
    else
        staticPositionMatch = bonus1.staticPosition == bonus2.staticPosition;

    /*Если у обоих бонусов не пуст вектор бонусных чанков, то значит, что статические
     *и динамические позиции неважны, ведь этих позиций по факту нет у обоих бонусов*/
    if(!bonus1.bonusChunksMaxVales.isEmpty() && !bonus1.bonusChunksMaxVales.isEmpty())
        if(bonus1.bonusChunksMaxVales == bonus1.bonusChunksMaxVales){
            dynamicPositionMatch = true;
            staticPositionMatch = true;
        }

    return !(bonus1.isDynamic == bonus2.isDynamic && bonus1.isPercentage == bonus2.isPercentage &&
            bonus1.isBonusChunk == bonus2.isBonusChunk && dynamicPositionMatch &&
            staticPositionMatch && bonus1.value == bonus2.getValue() &&
            bonus1.bonusChunksMaxVales == bonus2.bonusChunksMaxVales);
}

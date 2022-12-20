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
MagicDefenseBonus::MagicDefenseBonus(DynamicPosition dynamicPosition, int value, bool isPercentage, QString bonusName,
                                     int durationDays, int durationHours, int durationMinutes, int durationSeconds)
{
    this->dynamicPosition = dynamicPosition;
    setValue(value);
    this->isPercentage = isPercentage;
    this->bonusName = bonusName;

    isDynamic = true;
    isBonusChunk = false;

    this->durationDays = durationDays;
    this->durationHours = durationHours;
    this->durationMinutes = durationMinutes;
    this->durationSeconds = durationSeconds;

    if(!isPercentage)
        finalValue = value;
}

//Конструктор для бонуса на статической позиции
MagicDefenseBonus::MagicDefenseBonus(int staticPosition, int value, bool isPercentage, QString bonusName,
                                     int durationDays, int durationHours, int durationMinutes, int durationSeconds)
{
    setValue(value);
    this->isPercentage = isPercentage;
    this->staticPosition = staticPosition;
    this->bonusName = bonusName;

    isDynamic = false;
    isBonusChunk = false;

    this->durationDays = durationDays;
    this->durationHours = durationHours;
    this->durationMinutes = durationMinutes;
    this->durationSeconds = durationSeconds;

    if(!isPercentage)
        finalValue = value;
}

//Конструктор для бонусных чанков
MagicDefenseBonus::MagicDefenseBonus(QVector<int> bonusChunksMaxVales, QString bonusName, int durationDays, int durationHours, int durationMinutes, int durationSeconds)
{
    this->bonusChunksMaxVales = bonusChunksMaxVales;
    this->bonusName = bonusName;

    this->durationDays = durationDays;
    this->durationHours = durationHours;
    this->durationMinutes = durationMinutes;
    this->durationSeconds = durationSeconds;

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

int MagicDefenseBonus::getFinalValue() const
{
    return finalValue;
}

void MagicDefenseBonus::setFinalValue(int newFinalValue)
{
    finalValue = newFinalValue;
}

int MagicDefenseBonus::getNumberOfChunksChanged() const
{
    return numberOfChunksChanged;
}

void MagicDefenseBonus::setNumberOfChunksChanged(int newNumberOfChunksChanged)
{
    //Значение не может опускаться ниже 1, даже если бонус фактически не затронул ни одного чанка
    if(newNumberOfChunksChanged<1)
        newNumberOfChunksChanged = 1;
    numberOfChunksChanged = newNumberOfChunksChanged;
}

int MagicDefenseBonus::getDurationDays() const
{
    return durationDays;
}

void MagicDefenseBonus::setDurationDays(int newDurationDays)
{
    durationDays = newDurationDays;
}

int MagicDefenseBonus::getDurationHours() const
{
    return durationHours;
}

void MagicDefenseBonus::setDurationHours(int newDurationHours)
{
    durationHours = newDurationHours;
}

int MagicDefenseBonus::getDurationMinutes() const
{
    return durationMinutes;
}

void MagicDefenseBonus::setDurationMinutes(int newDurationMinutes)
{
    durationMinutes = newDurationMinutes;
}

int MagicDefenseBonus::getDurationSeconds() const
{
    return durationSeconds;
}

void MagicDefenseBonus::setDurationSeconds(int newDurationSeconds)
{
    durationSeconds = newDurationSeconds;
}

/*Операторы отношения сделаны для сортировки подсказок, которая производится по степени воздействия. Следовательно
 *сравнение производится по модулю. Бонус на новые чанки всегда считается большим чем любой другой. Процентный
 *бонус считается большим, чем такой же по итоговому значению непроцентный.*/
bool MagicDefenseBonus::operator <(const MagicDefenseBonus& bonus2)
{
    //Бонус на новые чанки всегда считается большим чем любой другой
    if(isBonusChunk && !bonus2.isBonusChunk){
        return false;
    }else if(!isBonusChunk && bonus2.isBonusChunk){
        return true;
    //Если оба бонуса на новые чанки, большим считатется тот, у кого больше суммарный размер всех новых чанков
    }else if(isBonusChunk && bonus2.isBonusChunk){
        int bonus1TotalValue = 0;
        int bonus2TotalValue = 0;
        for(int num : bonusChunksMaxVales){
            bonus1TotalValue+=num;
        }
        for(int num : bonus2.getBonusChunksMaxVales()){
            bonus2TotalValue+=num;
        }
        return bonus1TotalValue < bonus2TotalValue;
    /*Все значения умножены на numberOfChunksChanged, который показывает сколько чанков
     *затронул бонус. Так бонусы, применяемые ко всем чанкам будут считаться по фактическому
     *воздействию, а не по значению, применяемому только к одному чанку.*/
    }else
        if((finalValue == 0) && (bonus2.getFinalValue() == 0))
            //Если финальное значение обоих бонусов равно нулю, сравнивается их потенциальное воздействие на чанк
            return std::abs(value * numberOfChunksChanged) < std::abs(bonus2.getValue() * bonus2.getNumberOfChunksChanged());
        else
            return std::abs(finalValue * numberOfChunksChanged) < std::abs(bonus2.getFinalValue() * bonus2.getNumberOfChunksChanged());
}
bool MagicDefenseBonus::operator >(const MagicDefenseBonus& bonus2)
{
    //Бонус на новые чанки всегда считается большим чем любой другой
    if(isBonusChunk && !bonus2.isBonusChunk){
        return true;
    }else if(!isBonusChunk && bonus2.isBonusChunk){
        return false;
    //Если оба бонуса на новые чанки, большим считатется тот, у кого больше суммарный размер всех новых чанков
    }else if(isBonusChunk && bonus2.isBonusChunk){
        int bonus1TotalValue = 0;
        int bonus2TotalValue = 0;
        for(int num : bonusChunksMaxVales){
            bonus1TotalValue+=num;
        }
        for(int num : bonus2.getBonusChunksMaxVales()){
            bonus2TotalValue+=num;
        }
        return bonus1TotalValue > bonus2TotalValue;
    /*Если один из бонусов процентный, а второй нет, то у процентного берётся finalValue,
     *а у другого value, при этом если эти значения равны большим посчитается процентный.
     *Все значения умножены на numberOfChunksChanged, который показывает сколько чанков
     *затронул бонус. Так бонусы, применяемые ко всем чанкам будут считаться по фактическому
     *воздействию, а не по значению, применяемому только к одному чанку.*/
    }else
        if((finalValue == 0) && (bonus2.getFinalValue() == 0))
            //Если финальное значение обоих бонусов равно нулю, сравнивается их потенциальное воздействие на чанк
            return std::abs(value * numberOfChunksChanged) > std::abs(bonus2.getValue() * bonus2.getNumberOfChunksChanged());
        else
            return std::abs(finalValue * numberOfChunksChanged) > std::abs(bonus2.getFinalValue() * bonus2.getNumberOfChunksChanged());
}

/**************************************************************************
 *Данный класс является бонусом для всех статов кроме магической защиты.
 *Он хранит значение бонуса и информацию о том процентный ли бонус.
 *Также в классе реализованы операторы сравнения. Не смотря на название
 *может быть и отрицательным, а не только положительным.
 **************************************************************************/

#ifndef BONUS_H
#define BONUS_H

#include <qstring.h>


class Bonus
{
public:
    enum StatName{
        STRENGTH,
        AGILITY,
        INTELLIGENCE,
        MAGIC,
        BODYTYPE,
        WILL,
        MAGIC_DAMAGE,
        RESIST_PHYSICAL_DAMAGE,
        RESIST_MAGIC_DAMAGE,
        RESIST_PHYSICAL_EFFECTS,
        RESIST_MAGIC_EFFECTS,
        STRENGTHENING_PHYSICAL_EFFECTS,
        STRENGTHENING_MAGICAL_EFFECTS,
        MELEE_ACCURACY,
        RANGED_ACCURACY,
        MAGIC_ACCURACY,
        EVASION,
        STEALTH,
        ATTENTIVENESS,
        LOAD_CAPACITY,
        INITIATIVE,
        MAGIC_CAST_CHANCE,
        CHANCE_OF_USING_COMBAT_TECHNIQUE,
        MOVE_RANGE,
        HEALTH,
        ENDURANCE,
        MANA
    };

    Bonus(StatName statName, int value, bool isPercentage, QString bonusName);
    Bonus();
    int getValue() const;
    void setValue(int newValue);

    //Определяет тип бонуса: абсолютный или процентный
    bool isPercentage = false;
    StatName statName;
    QString bonusName;

    friend bool operator == (const Bonus& bonus1, const Bonus& bonus2);
    friend bool operator != (const Bonus& bonus1, const Bonus& bonus2);

    //Операторы сравнения сделаны для сортировки подсказок, которая производится по степени воздействия. Следовательно сравнение производится по модулю
    bool operator > (const Bonus& bonus2);
    bool operator < (const Bonus& bonus2);

    int getFinalValue() const;
    void setFinalValue(int newFinalValue);

private:
    //Финальное значеие с учётом процента. Хранится для подсказки
    int finalValue = 0;
    int value = 0;
};

#endif // BONUS_H

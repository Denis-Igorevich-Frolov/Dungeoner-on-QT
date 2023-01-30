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
    Bonus(QString statName, int value, bool isPercentage, QString bonusName, int durationDays, int durationHours, int durationMinutes, int durationSeconds);
    Bonus();
    int getValue() const;
    void setValue(int newValue);

    //Определяет тип бонуса: абсолютный или процентный
    bool isPercentage = false;
    //Бонус должен знать, к какому стату он может быть применим
    QString statName;
    QString bonusName;

    friend bool operator == (const Bonus& bonus1, const Bonus& bonus2);
    friend bool operator != (const Bonus& bonus1, const Bonus& bonus2);

    //Операторы отношения сделаны для сортировки подсказок, которая производится по степени воздействия. Следовательно сравнение производится по модулю
    bool operator > (const Bonus& bonus2);
    bool operator < (const Bonus& bonus2);

    int getFinalValue() const;
    void setFinalValue(int newFinalValue);

    int getDurationDays() const;
    void setDurationDays(int newDurationDays);

    int getDurationHours() const;
    void setDurationHours(int newDurationHours);

    int getDurationMinutes() const;
    void setDurationMinutes(int newDurationMinutes);

    int getDurationSeconds() const;
    void setDurationSeconds(int newDurationSeconds);

private:
    //Финальное значеие с учётом процента, если таковой имеется. Хранится для выведения подсказки
    int finalValue = 0;
    int value = 0;

    int durationDays = 0;
    int durationHours = 0;
    int durationMinutes = 0;
    int durationSeconds = 0;
};

#endif // BONUS_H

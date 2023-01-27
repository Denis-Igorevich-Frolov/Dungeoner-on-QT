/**********************************************************************
 *Данный класс является структурой для всех статов кроме магической
 *защиты с реализацией геттеров и сеттеров с ограничителями.
 **********************************************************************/

#ifndef STAT_H
#define STAT_H

#include "Person/Stat/bonus.h"
#include "qobject.h"

#include <QVector>

class Stat: public QObject
{
    Q_OBJECT
public:
    /*Разные группы статов имеют разные максимальные значения. Так для первичных навыков -
     *это 999999,а для вторичных - 9999999. Чтобы корректно работали ограничители на
     *сеттерах это максимальное значение задаётся при инициализации*/
    Stat(int maximum);
    ~Stat();

    int getValue() const;
    void setValue(int newValue);

    void addBonus(Bonus* bonus);

    /*Удаление бонуса. В метод передаётся указатель на бонус, который должен быть удалён. При этом
     *удаляется первый подошедший с конца бонус, а не конкретно тот, который инициировал удаление.
     *Если метод не смог обнаружить переданный на удаление бонус, он выводит предупреждение и
     *возвращает false, после чего следует запросить полный перерасчёт бонусов.*/
    bool removeBonus(Bonus* bonus);

    int getFinalValue() const;

    int getProgressBarCurrentValue() const;
    //Задание текущего значения прогрессбара, при этом просто value, в таком случае, является максимальным значением
    void setProgressBarCurrentValue(int newProgressBarCurrentValue);

    QVector<Bonus *> getBonuses();

    /*Очистка вектора бонусов. Метод не обновляет отображение бонусов в виджетах. Память указателей на
     *бонусы не высвобождается, так как это должно происходить только в классе предмета или эффекта*/
    void removeAllBonuses();

    //Так как класс Stat унаследован от QObject, его оператор присваивания явным образом удалён, соответственно его следует переопределить самому
    Stat& operator= (const Stat &stat);
    int getMaximum() const;

signals:
    void statChanged();
private:
    bool isProgressBar;
    int value = 0;
    //Текущее значение прогрессбара. Используется только в статах с прогрессбаром.
    int progressBarCurrentValue = 0;

    //Максимальное значение стата
    int maximum = 0;

    QVector<Bonus*> bonuses;

    //Вычисление финального максимального значения стата с учётом всех бонусов
    void calculateFinalValue();
protected:
    //Значение с учётом всех бонусов
    int finalValue = 0;
};

/*Данный подкласс является классом всех вторичных навыков и имеет
 *функционал перерачёта своего значения на основе первичных навыков.
 *
 *Первичные навыки задаются в виде вектора стов и их не может быть меньше,
 *чем изначальные 6. Не всем вторичным навыкам нужны все первичные, но
 *передача всех статов в виде вектора упрощает наследование и полиморфизм.
 *К тому же при изменении формулы не придётся добавлять или удалять первичные
 *навыки так как все они всегда доступны.*/
class RecalculatebleStat : public Stat{
public:
    RecalculatebleStat(int maximum, QVector<Stat*> primaryStats);
    virtual int recalculate();
protected:
    Stat* Strength;
    Stat* Agility;
    Stat* Intelligence;
    Stat* Magic;
    Stat* BodyType;
    Stat* Will;

    int numberOfPrimaryStat = 6;
};

class MagicDamageStat : public RecalculatebleStat{
public:
    MagicDamageStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class ResistPhysicalDamageStat : public RecalculatebleStat{
public:
    ResistPhysicalDamageStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class ResistMagicDamageStat : public RecalculatebleStat{
public:
    ResistMagicDamageStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class ResistPhysicalEffectsStat : public RecalculatebleStat{
public:
    ResistPhysicalEffectsStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class ResistMagicEffectsStat : public RecalculatebleStat{
public:
    ResistMagicEffectsStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class StrengtheningPhysicalEffectsStat : public RecalculatebleStat{
public:
    StrengtheningPhysicalEffectsStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class StrengtheningMagicalEffectsStat : public RecalculatebleStat{
public:
    StrengtheningMagicalEffectsStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class MeleeAccuracyStat : public RecalculatebleStat{
public:
    MeleeAccuracyStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class RangedAccuracyStat : public RecalculatebleStat{
public:
    RangedAccuracyStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class MagicAccuracyStat : public RecalculatebleStat{
public:
    MagicAccuracyStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class EvasionStat : public RecalculatebleStat{
public:
    EvasionStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class StealthStat : public RecalculatebleStat{
public:
    StealthStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class AttentivenessStat : public RecalculatebleStat{
public:
    AttentivenessStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class LoadCapacityStat : public RecalculatebleStat{
public:
    LoadCapacityStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class InitiativeStat : public RecalculatebleStat{
public:
    InitiativeStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class MagicCastChanceStat : public RecalculatebleStat{
public:
    MagicCastChanceStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class ChanceOfUsingCombatTechniqueStat : public RecalculatebleStat{
public:
    ChanceOfUsingCombatTechniqueStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class MoveRangeStat : public RecalculatebleStat{
public:
    MoveRangeStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class HealthStat : public RecalculatebleStat{
public:
    HealthStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class EnduranceStat : public RecalculatebleStat{
public:
    EnduranceStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

class ManaStat : public RecalculatebleStat{
public:
    ManaStat(int maximum, QVector<Stat*> primaryStats);
    int recalculate();
};

#endif // STAT_H

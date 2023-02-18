#ifndef SECONDARYSTAT_H
#define SECONDARYSTAT_H

#include "Person/Stat/stat.h"

struct PrimaryStatsStruct;
class MagicDefense;

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
    RecalculatebleStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats);
    RecalculatebleStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats);
    bool saveStat(bool createBackup);
    bool fastSave();
    bool loadStat();
    bool fastLoad();
    virtual int recalculate(){return -1;}
protected:
    PrimaryStatsStruct* primaryStats;
};

//Данный класс является классом стата, к которому относится прогрессбар
class ProgressBarStat : public RecalculatebleStat{
public:
    ProgressBarStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    ProgressBarStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int getProgressBarCurrentValue() const;
    //Задание текущего значения прогрессбара, при этом finalValue, в таком случае, является максимальным значением прогрессбара
    void setProgressBarCurrentValue(int newProgressBarCurrentValue);
    void setValue(int newValue);
    bool saveStat(bool createBackup);
    bool fastSave();
    bool loadStat(bool loadBonuses, bool loadProgressBarCurrentValue);
    bool fastLoad();
    bool removeBonus(Bonus *bonus);

private:
    int progressBarCurrentValue = 0;
};

class MagicDamageStat : public RecalculatebleStat{
public:
    MagicDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    MagicDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class ResistPhysicalDamageStat : public RecalculatebleStat{
public:
    ResistPhysicalDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    ResistPhysicalDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class ResistMagicDamageStat : public RecalculatebleStat{
public:
    ResistMagicDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    ResistMagicDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class ResistPhysicalEffectsStat : public RecalculatebleStat{
public:
    ResistPhysicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    ResistPhysicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class ResistMagicEffectsStat : public RecalculatebleStat{
public:
    ResistMagicEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    ResistMagicEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class StrengtheningPhysicalEffectsStat : public RecalculatebleStat{
public:
    StrengtheningPhysicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    StrengtheningPhysicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class StrengtheningMagicalEffectsStat : public RecalculatebleStat{
public:
    StrengtheningMagicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    StrengtheningMagicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class MeleeAccuracyStat : public RecalculatebleStat{
public:
    MeleeAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    MeleeAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class RangedAccuracyStat : public RecalculatebleStat{
public:
    RangedAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    RangedAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class MagicAccuracyStat : public RecalculatebleStat{
public:
    MagicAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    MagicAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class EvasionStat : public RecalculatebleStat{
public:
    EvasionStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    EvasionStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class StealthStat : public RecalculatebleStat{
public:
    StealthStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    StealthStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class AttentivenessStat : public RecalculatebleStat{
public:
    AttentivenessStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    AttentivenessStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class LoadCapacityStat : public RecalculatebleStat{
public:
    LoadCapacityStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    LoadCapacityStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class InitiativeStat : public RecalculatebleStat{
public:
    InitiativeStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    InitiativeStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class MagicCastChanceStat : public RecalculatebleStat{
public:
    MagicCastChanceStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    MagicCastChanceStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class ChanceOfUsingCombatTechniqueStat : public RecalculatebleStat{
public:
    ChanceOfUsingCombatTechniqueStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    ChanceOfUsingCombatTechniqueStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class MoveRangeStat : public RecalculatebleStat{
public:
    MoveRangeStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    MoveRangeStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class HealthStat : public ProgressBarStat{
public:
    HealthStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    HealthStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class EnduranceStat : public ProgressBarStat{
public:
    EnduranceStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    EnduranceStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

class ManaStat : public ProgressBarStat{
public:
    ManaStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats);
    ManaStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *>& stats);
    int recalculate();
};

struct PrimaryStatsStruct
{
public:
    PrimaryStatsStruct(QString personName, QVector<Stat *>& primaryStats);
    ~PrimaryStatsStruct();

    Stat* Strength;
    Stat* Agility;
    Stat* Intelligence;
    Stat* Magic;
    Stat* BodyType;
    Stat* Will;
};

struct SecondaryStatsStruct
{
public:
    SecondaryStatsStruct(QString personName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat*>& secondaryStats);
    ~SecondaryStatsStruct();

    MagicDamageStat* MagicDamage;
    ResistPhysicalDamageStat* ResistPhysicalDamage;
    ResistMagicDamageStat* ResistMagicDamage;
    ResistPhysicalEffectsStat* ResistPhysicalEffects;
    ResistMagicEffectsStat* ResistMagicEffects;
    StrengtheningPhysicalEffectsStat* StrengtheningPhysicalEffects;
    StrengtheningMagicalEffectsStat* StrengtheningMagicalEffects ;
    MeleeAccuracyStat* MeleeAccuracy;
    RangedAccuracyStat* RangedAccuracy;
    MagicAccuracyStat* MagicAccuracy;
    EvasionStat* Evasion;
    StealthStat* Stealth;
    AttentivenessStat* Attentiveness;
    LoadCapacityStat* LoadCapacity;
    InitiativeStat* Initiative;
    MagicCastChanceStat* MagicCastChance;
    ChanceOfUsingCombatTechniqueStat* ChanceOfUsingCombatTechnique;
    MoveRangeStat* MoveRange;
    HealthStat* Health;
    EnduranceStat* Endurance;
    ManaStat* Mana;
    MagicDefense* magicDefense;
};

struct StatsStruct
{
public:
    StatsStruct(QString personName, QVector<Stat*>& primaryStatsVector, QVector<RecalculatebleStat*>& secondaryStatsVector);
    ~StatsStruct();

    PrimaryStatsStruct* primaryStats;
    SecondaryStatsStruct* secondaryStats;
};

#endif // SECONDARYSTAT_H

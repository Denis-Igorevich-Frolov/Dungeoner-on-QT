/********************************************************************************************************************
 *Данный класс является классом вычисления, хранения, управления, сохранения и загрузки всех данных о персонаже.
 ********************************************************************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include "Person/Stat/stat.h"

#include <Global/global.h>
#include <Person/MagicDefense/magicdefense.h>

#include <qspinbox.h>

class Person : public QObject
{
    Q_OBJECT
public:
    void addBonusToStat(Bonus* bonus);
    //Добавление бонуса на магическую защиту
    void addBonusToStat(MagicDefenseBonus* bonus);

    bool removeBonusFromStat(Bonus* bonus);
    //Удаление бонуса с магической защиты
    bool removeBonusFromStat(MagicDefenseBonus* bonus);

    //Перерасчёт вторичных навыков
    void recalculateStats();

    //Перерасчёт количества родных чанков магической защиты
    void recalculateMagicDefense();

    Stat* getStrength();
    Stat* getAgility();
    Stat* getIntelligence();
    Stat* getMagic();
    Stat* getBodyType();
    Stat* getWill();

    RecalculatebleStat* getMagicDamage();
    RecalculatebleStat* getResistPhysicalDamage();
    RecalculatebleStat* getResistMagicDamage();
    RecalculatebleStat* getResistPhysicalEffects();
    RecalculatebleStat* getResistMagicEffects();
    RecalculatebleStat* getStrengtheningPhysicalEffects();
    RecalculatebleStat* getStrengtheningMagicalEffects();
    RecalculatebleStat* getMeleeAccuracy();
    RecalculatebleStat* getRangedAccuracy();
    RecalculatebleStat* getMagicAccuracy();
    RecalculatebleStat* getEvasion();
    RecalculatebleStat* getStealth();
    RecalculatebleStat* getAttentiveness();
    RecalculatebleStat* getLoadCapacity();
    RecalculatebleStat* getInitiative();
    RecalculatebleStat* getMagicCastChance();
    RecalculatebleStat* getChanceOfUsingCombatTechnique();
    RecalculatebleStat* getMoveRange();
    ProgressBarStat *getHealth();
    ProgressBarStat *getEndurance();
    ProgressBarStat *getMana();
    MagicDefense* getMagicDefense();

    //Значение воли которого недостаёт до получения ещё одного фрагмента магической защиты. Хранится для вывода подсказки
    int willUntilNextChunk = 0;
    QString getPersonName() const;
    void setPersonName(const QString &newPersonName);

signals:
    //Запрос на полную переинициализацию виджетов статов
    void FullReinitializationRequest();
public slots:
    /*Слот полной переинициализации. Каждый раз когда операции с бонусами проваливаются
     *запрашивается их полная переинциализация для избежания последующих проблем.*/
    void fullReinitialization();

    bool saveAllStats(bool createBackup);
    bool loadAllStats();

    /*Ниже идут методы сохранения и загрузки ко всем статам. Почти все из них вызывают универсальные методы
     *сохранения и загрузки, и только магическая защита имеет свои уникальные функции. У первичных навыков
     *можно выбрать сохранять/загружать ли значения и бонусы, а также у загрузки - посылать ли сигнал,
     *говорящий о том, что стат был изменён. У всех методов сохранения есть возможность выбрать сгенерирует
     *ли запрос бекап. У всех вторичных навыков не сохраняется значение, ведь оно просто генерируется заного
     *при любом обновлении первичных, и смысла хранить его нет. У них сохраняются только бонусы, а у навыков
     *имеющих прогресбар, сохраняется текущее значение прогресбара.
     *
     *Важно отметить, что загрузка статов по отдельности из окна персонажа имеет непредсказуемый эффект в
     *плане отображения значений на виджетах. Если появится надобность загружать статы по одному от туда,
     *то следует явным образом запустить переинициализацию всех задействованых виджетов. loadAllStats же
     *автоматически посылает запрос на полную переинициализацию и настоятельно рекомендуется использовать
     *именно эту функцию для загрузки.*/
    bool loadStrength(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool loadAgility(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool loadIntelligence(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool loadMagic(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool loadBodyType(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool loadWill(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool loadMagicDamage();

    bool loadResistPhysicalDamage();

    bool loadResistMagicDamage();

    bool loadResistPhysicalEffects();

    bool loadResistMagicEffects();

    bool loadStrengtheningPhysicalEffects();

    bool loadStrengtheningMagicalEffects();

    bool loadMeleeAccuracy();

    bool loadRangedAccuracy();

    bool loadMagicAccuracy();

    bool loadEvasion();

    bool loadStealth();

    bool loadAttentiveness();

    bool loadLoadCapacity();

    bool loadInitiative();

    bool loadMagicCastChance();

    bool loadChanceOfUsingCombatTechnique();

    bool loadMoveRange();

    bool loadHealth();

    bool loadEndurance();

    bool loadMana();

    bool saveMagicDefense(bool createBackup);
    bool loadMagicDefense();

private:
    /*Универсальный метод загрузки стата. В нём представлены все возможные варианты того, что у
     *стата можно загрузить. Если у стата, который необходимо загрузить некоторых полей нет, то
     *указвается false в переменных, говорящих что загружать. В поле statName следует передать
     *имя стата так, как его переменная названа в этом классе. В перемннею statIndex следует
     *передать соответствующее стату значение enum'а StatName из Bonus*/
    bool loadStat(QString statName, Bonus::StatName statIndex, Stat &stat, bool loadValue, bool loadProgressBarCurrentValue, bool loadBonuses);
    //Создание бекапа сохранений в отдельной папке в той же директории, что и текущее сохранение
    void createBackup();

    QString personName = "new hero";

    Stat Strength = Stat(999999, personName, "Strength");
    Stat Agility = Stat(999999, personName, "Agility");
    Stat Intelligence = Stat(999999, personName, "Intelligence");
    Stat Magic = Stat(999999, personName, "Magic");
    Stat BodyType = Stat(999999, personName, "BodyType");
    Stat Will = Stat(999999, personName, "Will");

    QVector<Stat*> primaryStats {&Strength, &Agility, &Intelligence, &Magic, &BodyType, &Will};

    MagicDamageStat MagicDamage = MagicDamageStat(9999999, personName, "MagicDamage", primaryStats);
    ResistPhysicalDamageStat ResistPhysicalDamage = ResistPhysicalDamageStat(9999999, personName, "ResistPhysicalDamage", primaryStats);
    ResistMagicDamageStat ResistMagicDamage = ResistMagicDamageStat(9999999, personName, "ResistMagicDamage", primaryStats);
    ResistPhysicalEffectsStat ResistPhysicalEffects = ResistPhysicalEffectsStat(9999999, personName, "ResistPhysicalEffects", primaryStats);
    ResistMagicEffectsStat ResistMagicEffects = ResistMagicEffectsStat(9999999, personName, "ResistMagicEffects", primaryStats);
    StrengtheningPhysicalEffectsStat StrengtheningPhysicalEffects = StrengtheningPhysicalEffectsStat(9999999, personName, "StrengtheningPhysicalEffects", primaryStats);
    StrengtheningMagicalEffectsStat StrengtheningMagicalEffects = StrengtheningMagicalEffectsStat(9999999, personName, "StrengtheningMagicalEffects", primaryStats);
    MeleeAccuracyStat MeleeAccuracy = MeleeAccuracyStat(9999999, personName, "MeleeAccuracy", primaryStats);
    RangedAccuracyStat RangedAccuracy = RangedAccuracyStat(9999999, personName, "RangedAccuracy", primaryStats);
    MagicAccuracyStat MagicAccuracy = MagicAccuracyStat(9999999, personName, "MagicAccuracy", primaryStats);
    EvasionStat Evasion = EvasionStat(9999999, personName, "Evasion", primaryStats);
    StealthStat Stealth = StealthStat(9999999, personName, "Stealth", primaryStats);
    AttentivenessStat Attentiveness = AttentivenessStat(9999999, personName, "Attentiveness", primaryStats);
    LoadCapacityStat LoadCapacity = LoadCapacityStat(9999999, personName, "LoadCapacity", primaryStats);
    InitiativeStat Initiative = InitiativeStat(9999999, personName, "Initiative", primaryStats);
    MagicCastChanceStat MagicCastChance = MagicCastChanceStat(9999999, personName, "MagicCastChance", primaryStats);
    ChanceOfUsingCombatTechniqueStat ChanceOfUsingCombatTechnique = ChanceOfUsingCombatTechniqueStat(9999999, personName, "ChanceOfUsingCombatTechnique", primaryStats);
    MoveRangeStat MoveRange = MoveRangeStat(9999999, personName, "MoveRange", primaryStats);
    HealthStat Health = HealthStat(9999999, personName, "Health", primaryStats);
    EnduranceStat Endurance = EnduranceStat(9999999, personName, "Endurance", primaryStats);
    ManaStat Mana = ManaStat(9999999, personName, "Mana", primaryStats);
    MagicDefense magicDefense;

    QVector<RecalculatebleStat*> secondaryStats {&MagicDamage, &ResistPhysicalDamage, &ResistMagicDamage, &ResistPhysicalEffects,
                                                &ResistMagicEffects, &StrengtheningPhysicalEffects, &StrengtheningMagicalEffects,
                                                &MeleeAccuracy, &RangedAccuracy, &MagicAccuracy, &Evasion, &Stealth, &Attentiveness,
                                                &LoadCapacity, &Initiative, &MagicCastChance, &ChanceOfUsingCombatTechnique,
                                                &MoveRange, &Health, &Endurance, &Mana};

};

#endif // PERSON_H

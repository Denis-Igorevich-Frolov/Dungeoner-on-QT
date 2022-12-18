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

    void recalculateMagicDamage();
    void recalculateResistPhysicalDamage();
    void recalculateResistMagicDamage();
    void recalculateResistPhysicalEffects();
    void recalculateResistMagicEffects();
    void recalculateStrengtheningPhysicalEffects();
    void recalculateStrengtheningMagicalEffects();
    void recalculateMeleeAccuracy();
    void recalculateRangedAccuracy();
    void recalculateMagicAccuracy();
    void recalculateEvasion();
    void recalculateStealth();
    void recalculateAttentiveness();
    void recalculateLoadCapacity();
    void recalculateInitiative();
    void recalculateMagicCastChance();
    void recalculateChanceOfUsingCombatTechnique();
    void recalculateMoveRange();
    void recalculateHealth();
    void recalculateEndurance();
    void recalculateMana();
    //Перерасчёт количества родных чанков магической защиты
    void recalculateMagicDefense();

    Stat* getStrength();
    void setStrength(Stat &newStrength);
    Stat* getAgility();
    void setAgility(Stat &newAgility);
    Stat* getIntelligence();
    void setIntelligence(Stat &newIntelligence);
    Stat* getMagic();
    void setMagic(Stat &newMagic);
    Stat* getBodyType();
    void setBodyType(Stat &newBodyType);
    Stat* getWill();
    void setWill(Stat &newWill);

    Stat* getMagicDamage();
    void setMagicDamage(Stat &newMagicDamage);
    Stat* getResistPhysicalDamage();
    void setResistPhysicalDamage(Stat &newResistPhysicalDamage);
    Stat* getResistMagicDamage();
    void setResistMagicDamage(Stat &newResistMagicDamage);
    Stat* getResistPhysicalEffects();
    void setResistPhysicalEffects(Stat &newResistPhysicalEffects);
    Stat* getResistMagicEffects();
    void setResistMagicEffects(Stat &newResistMagicEffects);
    Stat* getStrengtheningPhysicalEffects();
    void setStrengtheningPhysicalEffects(Stat &newStrengtheningPhysicalEffects);
    Stat* getStrengtheningMagicalEffects();
    void setStrengtheningMagicalEffects(Stat &newStrengtheningMagicalEffects);
    Stat* getMeleeAccuracy();
    void setMeleeAccuracy(Stat &newMeleeAccuracy);
    Stat* getRangedAccuracy();
    void setRangedAccuracy(Stat &newRangedAccuracy);
    Stat* getMagicAccuracy();
    void setMagicAccuracy(Stat &newMagicAccuracy);
    Stat* getEvasion();
    void setEvasion(Stat &newEvasion);
    Stat* getStealth();
    void setStealth(Stat &newStealth);
    Stat* getAttentiveness();
    void setAttentiveness(Stat &newAttentiveness);
    Stat* getLoadCapacity();
    void setLoadCapacity(Stat &newLoadCapacity);
    Stat* getInitiative();
    void setInitiative(Stat &newInitiative);
    Stat* getMagicCastChance();
    void setMagicCastChance(Stat &newMagicCastChance);
    Stat* getChanceOfUsingCombatTechnique();
    void setChanceOfUsingCombatTechnique(Stat &newChanceOfUsingCombatTechnique);
    Stat* getMoveRange();
    void setMoveRange(Stat &newMoveRange);
    Stat* getHealth();
    void setHealth(Stat &newHealth);
    Stat* getEndurance();
    void setEndurance(Stat &newEndurance);
    Stat* getMana();
    void setMana(Stat &newMana);
    MagicDefense* getMagicDefense();
    void setMagicDefense(MagicDefense &newMagicDefense);

    //Значение воли которого недостаёт до получения ещё одного фрагмента магической защиты. Хранится для вывода подсказки
    int willUntilNextChunk = 0;
    QString getPersonName() const;
    void setPersonName(const QString &newPersonName);

signals:
    void StrengthChanged();
    void AgilityChanged();
    void IntelligenceChanged();
    void MagicChanged();
    void BodyTypeChanged();
    void WillChanged();

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
    bool saveStrength(bool saveValues, bool saveBonuses, bool createBackup);
    bool loadStrength(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool saveAgility(bool saveValues, bool saveBonuses, bool createBackup);
    bool loadAgility(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool saveIntelligence(bool saveValues, bool saveBonuses, bool createBackup);
    bool loadIntelligence(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool saveMagic(bool saveValues, bool saveBonuses, bool createBackup);
    bool loadMagic(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool saveBodyType(bool saveValues, bool saveBonuses, bool createBackup);
    bool loadBodyType(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool saveWill(bool saveValues, bool saveBonuses, bool createBackup);
    bool loadWill(bool loadValues, bool loadBonuses, bool emittedChanged);

    bool saveMagicDamage(bool createBackup);
    bool loadMagicDamage();

    bool saveResistPhysicalDamage(bool createBackup);
    bool loadResistPhysicalDamage();

    bool saveResistMagicDamage(bool createBackup);
    bool loadResistMagicDamage();

    bool saveResistPhysicalEffects(bool createBackup);
    bool loadResistPhysicalEffects();

    bool saveResistMagicEffects(bool createBackup);
    bool loadResistMagicEffects();

    bool saveStrengtheningPhysicalEffects(bool createBackup);
    bool loadStrengtheningPhysicalEffects();

    bool saveStrengtheningMagicalEffects(bool createBackup);
    bool loadStrengtheningMagicalEffects();

    bool saveMeleeAccuracy(bool createBackup);
    bool loadMeleeAccuracy();

    bool saveRangedAccuracy(bool createBackup);
    bool loadRangedAccuracy();

    bool saveMagicAccuracy(bool createBackup);
    bool loadMagicAccuracy();

    bool saveEvasion(bool createBackup);
    bool loadEvasion();

    bool saveStealth(bool createBackup);
    bool loadStealth();

    bool saveAttentiveness(bool createBackup);
    bool loadAttentiveness();

    bool saveLoadCapacity(bool createBackup);
    bool loadLoadCapacity();

    bool saveInitiative(bool createBackup);
    bool loadInitiative();

    bool saveMagicCastChance(bool createBackup);
    bool loadMagicCastChance();

    bool saveChanceOfUsingCombatTechnique(bool createBackup);
    bool loadChanceOfUsingCombatTechnique();

    bool saveMoveRange(bool createBackup);
    bool loadMoveRange();

    bool saveHealth(bool createBackup);
    bool loadHealth();

    bool saveEndurance(bool createBackup);
    bool loadEndurance();

    bool saveMana(bool createBackup);
    bool loadMana();

    bool saveMagicDefense(bool createBackup);
    bool loadMagicDefense();

private:
    /*Универсальный метод сохранения стата. В нём представлены все возможные поля статов. Если у
     *стата, который необходимо сохранить некоторых полей нет, то в них передаётся просто 0 и
     *указывается false в переменных, говорящих что сохранять. В поле statName следует передать
     *имя стата так, как его переменная названа в этом классе.*/
    bool saveStat(QString statName, int value, int maximum, int progressBarCurrentValue, QVector<Bonus*> bonuses,
                  bool saveValues, bool saveProgressBarCurrentValue, bool saveBonuses, bool createBackup);
    /*Универсальный метод загрузки стата. В нём представлены все возможные варианты того, что у
     *стата можно загрузить. Если у стата, который необходимо загрузить некоторых полей нет, то
     *указвается false в переменных, говорящих что загружать. В поле statName следует передать
     *имя стата так, как его переменная названа в этом классе. В перемннею statIndex следует
     *передать соответствующее стату значение enum'а StatName из Bonus*/
    bool loadStat(QString statName, Bonus::StatName statIndex, Stat &stat, bool loadValue, bool loadProgressBarCurrentValue, bool loadBonuses);
    //Создание бекапа сохранений в отдельной папке в той же директории, что и текущее сохранение
    void createBackup();

    Stat Strength = Stat(999999);
    Stat Agility = Stat(999999);
    Stat Intelligence = Stat(999999);
    Stat Magic = Stat(999999);
    Stat BodyType = Stat(999999);
    Stat Will = Stat(999999);

    Stat MagicDamage = Stat(9999999);
    Stat ResistPhysicalDamage = Stat(9999999);
    Stat ResistMagicDamage = Stat(9999999);
    Stat ResistPhysicalEffects = Stat(9999999);
    Stat ResistMagicEffects = Stat(9999999);
    Stat StrengtheningPhysicalEffects = Stat(9999999);
    Stat StrengtheningMagicalEffects = Stat(9999999);
    Stat MeleeAccuracy = Stat(9999999);
    Stat RangedAccuracy = Stat(9999999);
    Stat MagicAccuracy = Stat(9999999);
    Stat Evasion = Stat(9999999);
    Stat Stealth = Stat(9999999);
    Stat Attentiveness = Stat(9999999);
    Stat LoadCapacity = Stat(9999999);
    Stat Initiative = Stat(9999999);
    Stat MagicCastChance = Stat(9999999);
    Stat ChanceOfUsingCombatTechnique = Stat(9999999);
    Stat MoveRange = Stat(9999999);
    Stat Health = Stat(9999999);
    Stat Endurance = Stat(9999999);
    Stat Mana = Stat(9999999);
    MagicDefense magicDefense;

    QString personName = "new hero";
};

#endif // PERSON_H

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
    Person();
    ~Person();

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

    MagicDefense* getMagicDefense();

    //Значение воли которого недостаёт до получения ещё одного фрагмента магической защиты. Хранится для вывода подсказки
    int willUntilNextChunk = 0;
    QString getPersonName() const;
    void setPersonName(const QString &newPersonName);

    StatsStruct* getStats();

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
//    bool loadStrength(bool loadValues, bool loadBonuses, bool emittedChanged);

//    bool loadAgility(bool loadValues, bool loadBonuses, bool emittedChanged);

//    bool loadIntelligence(bool loadValues, bool loadBonuses, bool emittedChanged);

//    bool loadMagic(bool loadValues, bool loadBonuses, bool emittedChanged);

//    bool loadBodyType(bool loadValues, bool loadBonuses, bool emittedChanged);

//    bool loadWill(bool loadValues, bool loadBonuses, bool emittedChanged);

//    bool loadMagicDamage();

//    bool loadResistPhysicalDamage();

//    bool loadResistMagicDamage();

//    bool loadResistPhysicalEffects();

//    bool loadResistMagicEffects();

//    bool loadStrengtheningPhysicalEffects();

//    bool loadStrengtheningMagicalEffects();

//    bool loadMeleeAccuracy();

//    bool loadRangedAccuracy();

//    bool loadMagicAccuracy();

//    bool loadEvasion();

//    bool loadStealth();

//    bool loadAttentiveness();

//    bool loadLoadCapacity();

//    bool loadInitiative();

//    bool loadMagicCastChance();

//    bool loadChanceOfUsingCombatTechnique();

//    bool loadMoveRange();

//    bool loadHealth();

//    bool loadEndurance();

//    bool loadMana();

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

    QVector<Stat *> primaryStatsVector;
    QVector<RecalculatebleStat *> secondaryStatsVector;
    StatsStruct* stats;
    MagicDefense magicDefense;
};

#endif // PERSON_H

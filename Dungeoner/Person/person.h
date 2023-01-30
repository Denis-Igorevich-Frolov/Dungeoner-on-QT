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

    bool addBonusToStat(Bonus* bonus);
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

    bool saveMagicDefense(bool createBackup);
    bool loadMagicDefense();

private:
    //Создание бекапа сохранений в отдельной папке в той же директории, что и текущее сохранение
    void createBackup();

    QString personName = "new hero";

    QVector<Stat *> primaryStatsVector;
    QVector<RecalculatebleStat *> secondaryStatsVector;
    QVector<Stat*> allStats;
    StatsStruct* stats;
    MagicDefense magicDefense;
};

#endif // PERSON_H

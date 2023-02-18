/********************************************************************************************************************
 *Данный класс является классом вычисления, хранения, управления, сохранения и загрузки всех данных о персонаже.
 ********************************************************************************************************************/

#include "person.h"
#include "Global/global.h"
#include "Person/MagicDefense/magicdefense.h"

#include <QDate>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

Person::Person()
{
    stats = new StatsStruct(personName, primaryStatsVector, secondaryStatsVector);
    allStats.append(primaryStatsVector);
    for(RecalculatebleStat* stat : secondaryStatsVector)
        allStats.append(stat);
}

Person::~Person()
{
    delete stats;
}

bool Person::addBonusToStat(Bonus *bonus)
{
    for(Stat* stat : allStats){
        if(stat->statName == bonus->statName){
            stat->addBonus(bonus);
            return true;
        }
    }
    return false;
}

//Добавление бонуса на магическую защиту
void Person::addBonusToStat(MagicDefenseBonus *bonus)
{
    stats->secondaryStats->magicDefense->addBonus(bonus);
}

bool Person::removeBonusFromStat(Bonus *bonus)
{
    //Переменная, говорящая о том было ли успешным удаление бонуса
    bool successful;
    for(Stat* stat : allStats){
        if(stat->statName == bonus->statName){
            stat->removeBonus(bonus);
            return true;
        }
    }
    return false;
}

//Удаление бонуса с магической защиты
bool Person::removeBonusFromStat(MagicDefenseBonus *bonus)
{
    //Переменная, говорящая о том было ли успешным удаление бонуса
    bool successful = stats->secondaryStats->magicDefense->removeBonus(bonus);

    if (!successful)
        fullReinitialization();
    return successful;
}

//Перерасчёт вторичных навыков
void Person::recalculateStats()
{
    for(RecalculatebleStat* stat : secondaryStatsVector)
        stat->recalculate();
}

/*Слот полной переинициализации. Каждый раз когда операции с бонусами проваливаются
 *запрашивается их полная переинциализация для избежания последующих проблем.*/
void Person::fullReinitialization()
{
    qDebug()<<"!!!Полная переинициализация всех бонусов!!!";

    //!!!Здесь должны быть запросы на пересчёты инвенторя и активных эффектов!!!

    recalculateStats();

    emit FullReinitializationRequest();
}

bool Person::saveAllStats(bool createBackup)
{
    if(createBackup){
        this->createBackup();
    }

    bool saveSuccess = true;
    for(Stat* stat : allStats){
        bool success = stat->fastSave();
        if(saveSuccess)
            saveSuccess = success;
    }

    return saveSuccess;
}

bool Person::loadAllStats()
{
    bool loadSuccess = true;
    for(Stat* stat : allStats){
        bool success = stat->fastLoad();
        if(loadSuccess)
            loadSuccess = success;
    }

    return loadSuccess;
}

//Создание бекапа сохранений в отдельной папке в той же директории, что и текущее сохранение
void Person::createBackup()
{
    //Создаётся директория, если её небыло
    QDir dir;
    if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups"))
        dir.mkpath("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups");
    dir = QDir("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups");

    //Из директории берутся файлы и сортируются по дате изменения
    QStringList files = dir.entryList(QDir::Files, QDir::Time);

    //В папке может храниться только такое число бекапов, какое узазано в Global::numberOfBackups. Новые бекапы вытесняют старые.
    for (int i = Global::numberOfBackups - 1; i < files.size(); i++)
    {
        dir.remove(files.at(i));
    }

    QDateTime dt = QDateTime::currentDateTime();

    //Создаётся новый бекап с указанием даты и времени создания
    QFile::copy("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite",
                "Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/backups/save "
                + dt.toString("dd-MM-yyyy hh.mm.ss") + ".sqlite");
}

StatsStruct *Person::getStats()
{
    return stats;
}

QString Person::getPersonName() const
{
    return personName;
}

void Person::setPersonName(const QString &newPersonName)
{
    personName = newPersonName;
}

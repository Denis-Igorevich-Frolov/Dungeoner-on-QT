/*******************************************************************
 *В этом файле хранятся все подклассы Stat, кроме MagicDefense
 *******************************************************************/

#include "secondarystat.h"
#include "Person/MagicDefense/magicdefense.h"
#include "qdir.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"

#include <Global/global.h>

RecalculatebleStat::RecalculatebleStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    : Stat(maximum, personName, statName)
{
    this->primaryStats = primaryStats;
}

/*Дополнительный конструктор с передоваемой ссылкой на вектор указателей на стат. При
 *использовании этого конструктора, полученный стат автоматически добавится в коллекцию.*/
RecalculatebleStat::RecalculatebleStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats):
    RecalculatebleStat(maximum, personName, statName, primaryStats)
{
    stats.append(this);
}

bool RecalculatebleStat::saveStat(bool createBackup)
{
    return Stat::saveStat(false, true, createBackup);
}

bool RecalculatebleStat::loadStat()
{
    return Stat::loadStat(false, true);
}

bool RecalculatebleStat::fastLoad()
{
    return loadStat();
}

/*Очистка вектора бонусов. Память указателей на бонусы не высвобождается,
 *так как это должно происходить только в классе предмета или эффекта*/
void RecalculatebleStat::removeAllBonuses()
{
    bonuses.clear();
    recalculate();
    calculateFinalValue();
    emit statChanged();
}

bool RecalculatebleStat::fastSave()
{
    return saveStat(false);
}

MagicDamageStat::MagicDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
MagicDamageStat::MagicDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int MagicDamageStat::recalculate()
{
    setValue(floor(1.5 * primaryStats->Magic->getFinalValue()) + floor(1.5 * primaryStats->Intelligence->getFinalValue()) + floor(0.5 * primaryStats->Will->getFinalValue()));

    return finalValue;
}

ResistPhysicalDamageStat::ResistPhysicalDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
ResistPhysicalDamageStat::ResistPhysicalDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int ResistPhysicalDamageStat::recalculate()
{
    setValue(floor(1.5 * primaryStats->Will->getFinalValue()) + floor(0.5 * primaryStats->Magic->getFinalValue()) + primaryStats->BodyType->getFinalValue());

    return finalValue;
}

ResistMagicDamageStat::ResistMagicDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
ResistMagicDamageStat::ResistMagicDamageStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int ResistMagicDamageStat::recalculate()
{
    setValue(floor(1.5 * primaryStats->Will->getFinalValue()) + floor(0.5 * primaryStats->BodyType->getFinalValue()) + primaryStats->Magic->getFinalValue());

    return finalValue;
}

ResistPhysicalEffectsStat::ResistPhysicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
ResistPhysicalEffectsStat::ResistPhysicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int ResistPhysicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * primaryStats->Will->getFinalValue()) + 10);

    return finalValue;
}

ResistMagicEffectsStat::ResistMagicEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
ResistMagicEffectsStat::ResistMagicEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int ResistMagicEffectsStat::recalculate()
{
    setValue(floor(0.1 * primaryStats->Will->getFinalValue()) + floor(0.1 * primaryStats->Magic->getFinalValue()) + 5);

    return finalValue;
}

StrengtheningPhysicalEffectsStat::StrengtheningPhysicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
StrengtheningPhysicalEffectsStat::StrengtheningPhysicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int StrengtheningPhysicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * primaryStats->Strength->getFinalValue()));

    return finalValue;
}

StrengtheningMagicalEffectsStat::StrengtheningMagicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
StrengtheningMagicalEffectsStat::StrengtheningMagicalEffectsStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int StrengtheningMagicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * primaryStats->Intelligence->getFinalValue()));

    return finalValue;
}

MeleeAccuracyStat::MeleeAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}

MeleeAccuracyStat::MeleeAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int MeleeAccuracyStat::recalculate()
{
    setValue(floor(0.1 * primaryStats->Agility->getFinalValue()) + 20);

    return finalValue;
}

RangedAccuracyStat::RangedAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
RangedAccuracyStat::RangedAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int RangedAccuracyStat::recalculate()
{
    setValue(floor(0.1 * primaryStats->Agility->getFinalValue()) + 15);

    return finalValue;
}

MagicAccuracyStat::MagicAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
MagicAccuracyStat::MagicAccuracyStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int MagicAccuracyStat::recalculate()
{
    setValue(floor(0.1 * primaryStats->Intelligence->getFinalValue()) + 15);

    return finalValue;
}

EvasionStat::EvasionStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
EvasionStat::EvasionStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int EvasionStat::recalculate()
{
    setValue(floor(0.5 * primaryStats->Agility->getFinalValue()) + floor(0.1 * primaryStats->BodyType->getFinalValue()));

    return finalValue;
}

StealthStat::StealthStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
StealthStat::StealthStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int StealthStat::recalculate()
{
    setValue(primaryStats->Intelligence->getFinalValue() + primaryStats->Agility->getFinalValue());

    return finalValue;
}

AttentivenessStat::AttentivenessStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
AttentivenessStat::AttentivenessStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int AttentivenessStat::recalculate()
{
    setValue(primaryStats->Intelligence->getFinalValue() + primaryStats->Agility->getFinalValue() + primaryStats->Will->getFinalValue());

    return finalValue;
}

LoadCapacityStat::LoadCapacityStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
LoadCapacityStat::LoadCapacityStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int LoadCapacityStat::recalculate()
{
    setValue(floor(0.5 * primaryStats->Strength->getFinalValue()) + floor(0.5 * primaryStats->BodyType->getFinalValue()));

    return finalValue;
}

InitiativeStat::InitiativeStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
InitiativeStat::InitiativeStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int InitiativeStat::recalculate()
{
    setValue(floor(5 * primaryStats->Agility->getFinalValue()) + primaryStats->Intelligence->getFinalValue() + primaryStats->Will->getFinalValue());

    return finalValue;
}

MagicCastChanceStat::MagicCastChanceStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
MagicCastChanceStat::MagicCastChanceStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int MagicCastChanceStat::recalculate()
{
    setValue(floor(0.3 * primaryStats->Intelligence->getFinalValue()) + floor(0.2 * primaryStats->Magic->getFinalValue()));

    return finalValue;
}

ChanceOfUsingCombatTechniqueStat::ChanceOfUsingCombatTechniqueStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
ChanceOfUsingCombatTechniqueStat::ChanceOfUsingCombatTechniqueStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int ChanceOfUsingCombatTechniqueStat::recalculate()
{
    setValue(floor(0.2 * primaryStats->Agility->getFinalValue()) + 20);

    return finalValue;
}

MoveRangeStat::MoveRangeStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}
MoveRangeStat::MoveRangeStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}
int MoveRangeStat::recalculate()
{
    setValue(floor(0.75 * primaryStats->Agility->getFinalValue()) + floor(0.5 * primaryStats->Strength->getFinalValue()) + primaryStats->BodyType->getFinalValue());

    return finalValue;
}

HealthStat::HealthStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :ProgressBarStat(maximum, personName, statName, primaryStats)
{}
HealthStat::HealthStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :ProgressBarStat(maximum, personName, statName, primaryStats, stats)
{}
int HealthStat::recalculate()
{
    setValue(primaryStats->Strength->getFinalValue() * 2 + primaryStats->BodyType->getFinalValue() * 10 + primaryStats->Will->getFinalValue() * 5 + primaryStats->Magic->getFinalValue());

    return finalValue;
}

EnduranceStat::EnduranceStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :ProgressBarStat(maximum, personName, statName, primaryStats)
{}
EnduranceStat::EnduranceStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :ProgressBarStat(maximum, personName, statName, primaryStats, stats)
{}
int EnduranceStat::recalculate()
{
    setValue(primaryStats->Agility->getFinalValue() * 10 + primaryStats->BodyType->getFinalValue());

    return finalValue;
}

ManaStat::ManaStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :ProgressBarStat(maximum, personName, statName, primaryStats)
{}
ManaStat::ManaStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :ProgressBarStat(maximum, personName, statName, primaryStats, stats)
{}
int ManaStat::recalculate()
{
    setValue(primaryStats->Magic->getFinalValue() * 10 + primaryStats->Intelligence->getFinalValue() * 2 + primaryStats->Will->getFinalValue());

    return finalValue;
}

ProgressBarStat::ProgressBarStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats)
{}

/*Дополнительный конструктор с передоваемой ссылкой на вектор указателей на стат. При
 *использовании этого конструктора, полученный стат автоматически добавится в коллекцию.*/
ProgressBarStat::ProgressBarStat(int maximum, QString personName, QString statName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *>& stats)
    :RecalculatebleStat(maximum, personName, statName, primaryStats, stats)
{}

int ProgressBarStat::getProgressBarCurrentValue() const
{
    return progressBarCurrentValue;
}

//Задание текущего значения прогрессбара, при этом finalValue, в таком случае, является максимальным значением прогрессбара
void ProgressBarStat::setProgressBarCurrentValue(int newProgressBarCurrentValue)
{
    if(newProgressBarCurrentValue>finalValue)
        newProgressBarCurrentValue = finalValue;
    if(newProgressBarCurrentValue<0)
        newProgressBarCurrentValue = 0;

    progressBarCurrentValue = newProgressBarCurrentValue;
}

void ProgressBarStat::setValue(int newValue)
{
    Stat::setValue(newValue);

    //Если текущее значение прогрессбара превышает максимальное значение, то оно усекается
    if(progressBarCurrentValue>finalValue)
        progressBarCurrentValue = finalValue;
}

bool ProgressBarStat::saveStat(bool createBackup)
{
    bool saveSuccess = Stat::saveStat(false, true, true);
    {
        //Создаётся директория, если её небыло
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName))
            dir.mkpath("Game Saves/"+Global::DungeonName+"/Heroes/"+personName);

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "save");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite");

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "ProgressBarStat выдал ошибку в методе saveStat.\n"
            "Файл Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite не удалось открыть.\n\n";
            qDebug()<<error;

            QFile errorFile("error log.txt");
            if (!errorFile.open(QIODevice::Append))
            {
                qDebug() << "Ошибка при открытии файла логов";
            }else{
                errorFile.open(QIODevice::Append  | QIODevice::Text);
                QTextStream writeStream(&errorFile);
                writeStream<<error;
                errorFile.close();
            }

            return false;
        }

        //Инициация транзакции
        database.transaction();

        QSqlQuery query(database);
        if(!query.exec("select progress_bar_current_value from Stats limit 1;")){
            if(!query.exec("ALTER TABLE Stats ADD COLUMN progress_bar_current_value INTEGER NOT NULL DEFAULT 0;")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось добавить столбец в таблицу\n"
                        "ProgressBarStat выдал ошибку в методе saveStat.\n"
                        "Не удалось добавить столбец progress_bar_current_value\n"
                        "в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
                qDebug()<<error;

                QFile errorFile("error log.txt");
                if (!errorFile.open(QIODevice::Append))
                {
                    qDebug() << "Ошибка при открытии файла логов";
                }else{
                    errorFile.open(QIODevice::Append  | QIODevice::Text);
                    QTextStream writeStream(&errorFile);
                    writeStream<<error;
                    errorFile.close();
                }

                database.close();
                return false;
            }
        }
        if(!query.exec("REPLACE INTO Stats (stat_name, progress_bar_current_value) VALUES ('" + statName + "', " + QString::number(progressBarCurrentValue) + ");")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось записать данные в таблицу\n"
                    "ProgressBarStat выдал ошибку в методе saveStat.\n"
                    "Не удалось записать данные в таблицу базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
            qDebug()<<error;

            QFile errorFile("error log.txt");
            if (!errorFile.open(QIODevice::Append))
            {
                qDebug() << "Ошибка при открытии файла логов";
            }else{
                errorFile.open(QIODevice::Append  | QIODevice::Text);
                QTextStream writeStream(&errorFile);
                writeStream<<error;
                errorFile.close();
            }

            database.close();
            return false;
        }
        //Если всё выполнилось успешно, то транзакция комитится
        if(!query.exec()){
           database.rollback();
           //Вывод предупреждения в консоль и файл
           QDate cd = QDate::currentDate();
           QTime ct = QTime::currentTime();

           QString error =
                   cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                   "\nОШИБКА: Ошибка транзакции при сохранении базы данных\n"
                   "ProgressBarStat выдал ошибку в методе saveStat.\n"
                   "Транзакция прошла неудачно в таблице базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
           qDebug()<<error;

           QFile errorFile("error log.txt");
           if (!errorFile.open(QIODevice::Append))
           {
               qDebug() << "Ошибка при открытии файла логов";
           }else{
               errorFile.open(QIODevice::Append  | QIODevice::Text);
               QTextStream writeStream(&errorFile);
               writeStream<<error;
               errorFile.close();
           }
        }
        else{
           database.commit();
        }
        database.close();
    }
    QSqlDatabase::removeDatabase("save");

    return saveSuccess;
}

bool ProgressBarStat::fastSave()
{
    return saveStat(false);
}

bool ProgressBarStat::loadStat(bool loadBonuses, bool loadProgressBarCurrentValue)
{
    bool loadSuccess = Stat::loadStat(false, loadBonuses);
    {
        //Создаётся директория, если её небыло
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "ProgressBarStat выдал ошибку в методе loadStat.\n"
            "Директории Game Saves/"+Global::DungeonName+"/Heroes/"+personName + " не существует.\n\n";
            qDebug()<<error;

            QFile errorFile("error log.txt");
            if (!errorFile.open(QIODevice::Append))
            {
                qDebug() << "Ошибка при открытии файла логов";
            }else{
                errorFile.open(QIODevice::Append  | QIODevice::Text);
                QTextStream writeStream(&errorFile);
                writeStream<<error;
                errorFile.close();
            }

            return false;
        }

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "load");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite");

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "ProgressBarStat выдал ошибку в методе loadStat.\n"
            "Файл Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite не удалось открыть.\n\n";
            qDebug()<<error;

            QFile errorFile("error log.txt");
            if (!errorFile.open(QIODevice::Append))
            {
                qDebug() << "Ошибка при открытии файла логов";
            }else{
                errorFile.open(QIODevice::Append  | QIODevice::Text);
                QTextStream writeStream(&errorFile);
                writeStream<<error;
                errorFile.close();
            }

            return false;
        }

        QSqlQuery query(database);
        if(loadProgressBarCurrentValue){
            if( !query.exec( "SELECT progress_bar_current_value FROM Stats WHERE stat_name IS '" + statName + "';")) {
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось считать данные из таблицы\n"
                        "ProgressBarStat выдал ошибку в методе loadStat.\n"
                        "Не удалось считать данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
                qDebug()<<error;

                QFile errorFile("error log.txt");
                if (!errorFile.open(QIODevice::Append))
                {
                    qDebug() << "Ошибка при открытии файла логов";
                }else{
                    errorFile.open(QIODevice::Append  | QIODevice::Text);
                    QTextStream writeStream(&errorFile);
                    writeStream<<error;
                    errorFile.close();
                }

                database.close();
                return false;
            }

            query.first();
            setProgressBarCurrentValue(query.value(0).toInt());

            query.clear();
        }

        database.close();
    }

    QSqlDatabase::removeDatabase("load");
    emit statChanged();
    return loadSuccess;
}

bool ProgressBarStat::fastLoad()
{
    return loadStat(true, true);
}

//Переопределение удаления бонуса, поддерживающее усекание текущего значения прогрессбара при уменьшении максимального значения
bool ProgressBarStat::removeBonus(Bonus *bonus)
{
    QMutableVectorIterator<Bonus*> iterator(bonuses);
    iterator.toBack();
    Bonus* BNS;
    while(iterator.hasPrevious()){
        BNS = iterator.previous();
        if(*BNS==*bonus){
            delete BNS;
            iterator.remove();

            calculateFinalValue();
            if(progressBarCurrentValue>finalValue)
                progressBarCurrentValue=finalValue;
            emit statChanged();
            return true;
        }
    }
    /*Если ничего найдено небыло, то выводится предупреждение. Вызывающему классу следует
     *запросить полный пересчёт всех векторов чанков и провести их полную переинициализацию.*/

    //Вывод предупреждения в консоль и файл
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    QString error =
    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
    "\nПРЕДУПРЕЖДЕНИЕ: не найден MagicDefenseBonus\n"
    "MagicDefense выдал предупреждение в методе removeBonus.\n"
    "При попытке удалить MagicDefenseBonus, он не был обнаружен.\n\n";
    qDebug()<<error;

    QFile errorFile("error log.txt");
    if (!errorFile.open(QIODevice::Append))
    {
        qDebug() << "Ошибка при открытии файла логов";
    }else{
        errorFile.open(QIODevice::Append  | QIODevice::Text);
        QTextStream writeStream(&errorFile);
        writeStream<<error;
        errorFile.close();
    }
    return false;
}

//Все полученные навыки передадутся в вектор primaryStats
PrimaryStatsStruct::PrimaryStatsStruct(QString personName, QVector<Stat *>& primaryStats)
{
    Strength = new Stat(999999, personName, "Strength", primaryStats);
    Agility = new Stat(999999, personName, "Agility", primaryStats);
    Intelligence = new Stat(999999, personName, "Intelligence", primaryStats);
    Magic = new Stat(999999, personName, "Magic", primaryStats);
    BodyType = new Stat(999999, personName, "BodyType", primaryStats);
    Will = new Stat(999999, personName, "Will", primaryStats);
}

PrimaryStatsStruct::~PrimaryStatsStruct()
{
    delete Strength;
    delete Agility;
    delete Intelligence;
    delete Magic;
    delete BodyType;
    delete Will;
}

//Все полученные навыки передадутся в вектор secondaryStats
SecondaryStatsStruct::SecondaryStatsStruct(QString personName, PrimaryStatsStruct* primaryStats, QVector<RecalculatebleStat *> &secondaryStats)
{
    MagicDamage = new MagicDamageStat(9999999, personName, "MagicDamage", primaryStats, secondaryStats);
    ResistPhysicalDamage = new ResistPhysicalDamageStat(9999999, personName, "ResistPhysicalDamage", primaryStats, secondaryStats);
    ResistMagicDamage = new ResistMagicDamageStat(9999999, personName, "ResistMagicDamage", primaryStats, secondaryStats);
    ResistPhysicalEffects = new ResistPhysicalEffectsStat(9999999, personName, "ResistPhysicalEffects", primaryStats, secondaryStats);
    ResistMagicEffects = new ResistMagicEffectsStat(9999999, personName, "ResistMagicEffects", primaryStats, secondaryStats);
    StrengtheningPhysicalEffects = new StrengtheningPhysicalEffectsStat(9999999, personName, "StrengtheningPhysicalEffects", primaryStats, secondaryStats);
    StrengtheningMagicalEffects = new StrengtheningMagicalEffectsStat(9999999, personName, "StrengtheningMagicalEffects", primaryStats, secondaryStats);
    MeleeAccuracy = new MeleeAccuracyStat(9999999, personName, "MeleeAccuracy", primaryStats, secondaryStats);
    RangedAccuracy = new RangedAccuracyStat(9999999, personName, "RangedAccuracy", primaryStats, secondaryStats);
    MagicAccuracy = new MagicAccuracyStat(9999999, personName, "MagicAccuracy", primaryStats, secondaryStats);
    Evasion = new EvasionStat(9999999, personName, "Evasion", primaryStats, secondaryStats);
    Stealth = new StealthStat(9999999, personName, "Stealth", primaryStats, secondaryStats);
    Attentiveness = new AttentivenessStat(9999999, personName, "Attentiveness", primaryStats, secondaryStats);
    LoadCapacity = new LoadCapacityStat(9999999, personName, "LoadCapacity", primaryStats, secondaryStats);
    Initiative = new InitiativeStat(9999999, personName, "Initiative", primaryStats, secondaryStats);
    MagicCastChance = new MagicCastChanceStat(9999999, personName, "MagicCastChance", primaryStats, secondaryStats);
    ChanceOfUsingCombatTechnique = new ChanceOfUsingCombatTechniqueStat(9999999, personName, "ChanceOfUsingCombatTechnique", primaryStats, secondaryStats);
    MoveRange = new MoveRangeStat(9999999, personName, "MoveRange", primaryStats, secondaryStats);
    Health = new HealthStat(9999999, personName, "Health", primaryStats, secondaryStats);
    Endurance = new EnduranceStat(9999999, personName, "Endurance", primaryStats, secondaryStats);
    Mana = new ManaStat(9999999, personName, "Mana", primaryStats, secondaryStats);
    magicDefense = new MagicDefense(personName, primaryStats, secondaryStats);
}

SecondaryStatsStruct::~SecondaryStatsStruct()
{
    delete MagicDamage;
    delete ResistPhysicalDamage;
    delete ResistMagicDamage;
    delete ResistPhysicalEffects;
    delete ResistMagicEffects;
    delete StrengtheningPhysicalEffects;
    delete StrengtheningMagicalEffects;
    delete MeleeAccuracy;
    delete RangedAccuracy;
    delete MagicAccuracy;
    delete Evasion;
    delete Stealth;
    delete Attentiveness;
    delete LoadCapacity;
    delete Initiative;
    delete MagicCastChance;
    delete ChanceOfUsingCombatTechnique;
    delete MoveRange;
    delete Health;
    delete Endurance;
    delete Mana;
    delete magicDefense;
}

StatsStruct::StatsStruct(QString personName, QVector<Stat *>& primaryStatsVector, QVector<RecalculatebleStat*>& secondaryStatsVector)
{
    primaryStats = new PrimaryStatsStruct(personName, primaryStatsVector);
    secondaryStats = new SecondaryStatsStruct(personName, primaryStats, secondaryStatsVector);
}

StatsStruct::~StatsStruct()
{
    delete primaryStats;
    delete secondaryStats;
}

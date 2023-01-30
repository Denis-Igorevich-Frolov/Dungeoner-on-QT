/**********************************************************************
 *Данный класс является структурой для всех статов кроме магической
 *защиты с реализацией геттеров и сеттеров с ограничителями.
 **********************************************************************/

#include "stat.h"
#include "qdir.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"

#include <QDate>
#include <qfile.h>

#include <Global/global.h>

int Stat::getValue() const
{
    return value;
}

void Stat::setValue(int newValue)
{
    value = newValue;

    if(value > maximum)
        value = maximum;
    else if(value<0)
        value = 0;

    calculateFinalValue();
    emit statChanged();
}

void Stat::addBonus(Bonus *bonus)
{
    bonuses.append(bonus);
    //Сортировка по степени воздействия
    std::sort(bonuses.begin(), bonuses.end(), [](Bonus* a, Bonus* b) {
        return *a > *b;
    });
    calculateFinalValue();
    emit statChanged();
}

/*Удаление бонуса. В метод передаётся указатель на бонус, который должен быть удалён. При этом
 *удаляется первый подошедший с конца бонус, а не конкретно тот, который инициировал удаление.
 *Если метод не смог обнаружить переданный на удаление бонус, он выводит предупреждение и
 *возвращает false, после чего следует запросить полный перерасчёт бонусов.*/
bool Stat::removeBonus(Bonus *bonus)
{
    QMutableVectorIterator<Bonus*> iterator(bonuses);
    iterator.toBack();
    Bonus* MD;
    while(iterator.hasPrevious()){
        MD = iterator.previous();
        if(*MD==*bonus){
            delete MD;
            iterator.remove();

            calculateFinalValue();
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

int Stat::getFinalValue() const
{
    return finalValue;
}

QVector<Bonus *> Stat::getBonuses()
{
    return bonuses;
}

/*Очистка вектора бонусов. Метод не обновляет отображение бонусов в виджетах. Память указателей на
 *бонусы не высвобождается, так как это должно происходить только в классе предмета или эффекта*/
void Stat::removeAllBonuses()
{
    bonuses.clear();
}

//Вычисление финального максимального значения стата с учётом всех бонусов
void Stat::calculateFinalValue()
{
    finalValue = value;

    for(Bonus* bonus : bonuses){
        if(bonus != nullptr){
            if (bonus->isPercentage){
                int bonusFinalValue = ((double)value/100)*bonus->getValue();
                finalValue += bonusFinalValue;
                bonus->setFinalValue(bonusFinalValue);
            }else
                finalValue += bonus->getValue();
        }
    }

    if(finalValue > maximum)
        finalValue = maximum;
    else if(finalValue<0)
        finalValue = 0;

    //Сортировка бонусов по степени воздействия
    std::sort(bonuses.begin(), bonuses.end(), [](Bonus* a, Bonus* b) {
        return *a > *b;
    });
}

/*Разные группы статов имеют разные максимальные значения. Так для первичных навыков -
 *это 999999,а для вторичных - 9999999. Чтобы корректно работали ограничители на
 *сеттерах это максимальное значение задаётся при инициализации*/
Stat::Stat(int maximum, QString personName, QString statName) : maximum(maximum), personName(personName), statName(statName)
{}

Stat::Stat(int maximum, QString personName, QString statName, QVector<Stat *>& stats):Stat(maximum, personName, statName)
{
    stats.append(this);
}

Stat::~Stat()
{
    for(Bonus* bonus : bonuses)
        delete bonus;
}

//Так как класс Stat унаследован от QObject, его оператор присваивания явным образом удалён, соответственно его следует переопределить самому
Stat& Stat::operator= (const Stat &stat)
{
    value = stat.value;
    finalValue = stat.finalValue;
    maximum = stat.maximum;
    bonuses = stat.bonuses;

    return *this;
}

int Stat::getMaximum() const
{
    return maximum;
}

bool Stat::saveStat(bool saveValue, bool saveBonuses, bool createBackup)
{
    {
        //Создаётся директория, если её небыло
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName))
            dir.mkpath("Game Saves/"+Global::DungeonName+"/Heroes/"+personName);

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "save");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite");

        if(createBackup)
            this->createBackup();

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Stat выдал ошибку в методе saveStat.\n"
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

        //Создание таблицы стата
        QSqlQuery query(database);
        if(!query.exec("CREATE TABLE IF NOT EXISTS Stats("
                       "stat_name TEXT NOT NULL, "
                       "value INTEGER NOT NULL DEFAULT 0,"
                       "maximum INTEGER NOT NULL DEFAULT 0,"
                       "CONSTRAINT value_chek CHECK ((value >= 0) AND (value <= maximum)), "
                       "CONSTRAINT stat PRIMARY KEY (stat_name), "
                       "CONSTRAINT stat_name_chek CHECK (stat_name !=''));"
                       )){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Не удалось создать таблицу\n"
            "Stat выдал ошибку в методе saveStat.\n"
            "Не удалось создать таблицу в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

        //Создание таблицы бонусов стата
        if(!query.exec("CREATE TABLE IF NOT EXISTS Bonuses("
                       "stat_name TEXT NOT NULL, "
                       "value INTEGER NOT NULL DEFAULT 0, "
                       "is_percentage INTEGER NOT NULL DEFAULT 0, "
                       "bonus_name TEXT NOT NULL,"
                       "duration_days INTEGER NOT NULL DEFAULT 0, "
                       "duration_hours INTEGER NOT NULL DEFAULT 0, "
                       "duration_minutes INTEGER NOT NULL DEFAULT 0, "
                       "duration_seconds INTEGER NOT NULL DEFAULT 0, "
                       "CONSTRAINT bool_chek CHECK (is_percentage >= 0 AND is_percentage <= 1), "
                       "CONSTRAINT stat_name_chek CHECK (stat_name != ''), "
                       "CONSTRAINT bonus_name_chek CHECK (bonus_name != ''), "
                       "CONSTRAINT duration_days_chek CHECK (duration_days >= -1), "
                       "CONSTRAINT duration_hours_chek CHECK (duration_hours >= -1), "
                       "CONSTRAINT duration_minutes_chek CHECK (duration_minutes >= -1), "
                       "CONSTRAINT duration_seconds_chek CHECK (duration_seconds >= -1));"
                       )){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Не удалось создать таблицу\n"
            "Stat выдал ошибку в методе saveStat.\n"
            "Не удалось создать таблицу в базе данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

        if(saveValue){
            if(!query.exec("REPLACE INTO Stats (stat_name, value, maximum) VALUES ('" + statName + "', "
                           + QString::number(value) + ", " +  QString::number(maximum) +");")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось записать данные в таблицу\n"
                        "Stat выдал ошибку в методе saveStat.\n"
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
        }

        if(saveBonuses){
            if(!query.exec("DELETE FROM Bonuses WHERE stat_name = '" + statName + "';")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось удалить данные из таблицы\n"
                        "Stat выдал ошибку в методе saveStat.\n"
                        "Не удалось удалить данные из таблицы базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

            for(Bonus* bonus : bonuses){
                if(!query.exec("INSERT INTO Bonuses (stat_name, value, is_percentage, bonus_name, duration_days, "
                               "duration_hours, duration_minutes, duration_seconds) VALUES ('" + statName + "', " +
                               QString::number(bonus->getValue())+ ", " + QString::number(bonus->isPercentage) +
                               ", '" + bonus->bonusName + "', " + QString::number(bonus->getDurationDays()) + ", " +
                               QString::number(bonus->getDurationHours()) + ", " + QString::number(bonus->getDurationMinutes())
                               + ", " + QString::number(bonus->getDurationSeconds()) + ");")){

                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nОШИБКА: Не удалось записать данные в таблицу\n"
                            "Stat выдал ошибку в методе saveStat.\n"
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
            }
        }

        database.close();
    }
    QSqlDatabase::removeDatabase("save");

    return true;
}

bool Stat::fastSave()
{
    return saveStat(true, true, false);
}

bool Stat::loadStat(bool loadValue, bool loadBonuses)
{
    {
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Stat выдал ошибку в методе loadStat.\n"
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
            "Stat выдал ошибку в методе loadStat.\n"
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
        if(loadValue){
            if( !query.exec( "SELECT value FROM Stats WHERE stat_name IS '" + statName + "';")) {
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось считать данные из таблицы\n"
                        "Stat выдал ошибку в методе loadStat.\n"
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
            setValue(query.value(0).toInt());

            query.clear();
        }

        if(loadBonuses){
            if( !query.exec( "SELECT * FROM Bonuses WHERE stat_name = '" + statName + "';")) {
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось считать данные из таблицы\n"
                        "Stat выдал ошибку в методе loadStat.\n"
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

            removeAllBonuses();
            while (query.next())
                addBonus(new Bonus(statName, query.value(1).toInt(), query.value(2).toBool(), query.value(3).toString(),
                                   query.value(4).toInt(), query.value(5).toInt(), query.value(6).toInt(), query.value(7).toInt()));
        }

        database.close();
    }

    QSqlDatabase::removeDatabase("load");
    return true;
}

bool Stat::fastLoad()
{
    return loadStat(true, true);
}

//Создание бекапа сохранений в отдельной папке в той же директории, что и текущее сохранение
void Stat::createBackup()
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

RecalculatebleStat::RecalculatebleStat(int maximum, QString personName, QString statName, PrimaryStatsStruct* primaryStats)
    : Stat(maximum, personName, statName)
{
    this->primaryStats = primaryStats;
}

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
    if(progressBarCurrentValue>value)
        progressBarCurrentValue = value;
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

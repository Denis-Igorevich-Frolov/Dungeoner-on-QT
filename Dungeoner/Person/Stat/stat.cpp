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

bool Stat::saveStat(bool saveValues, bool saveBonuses, bool createBackup)
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

        if(saveValues){
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

RecalculatebleStat::RecalculatebleStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                       Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    : Stat(maximum, personName, statName)
{
    this->Strength = Strength;
    this->Agility = Agility;
    this->Intelligence = Intelligence;
    this->Magic = Magic;
    this->BodyType = BodyType;
    this->Will = Will;
}

bool RecalculatebleStat::saveStat(bool createBackup)
{
    return Stat::saveStat(false, true, createBackup);
}

bool RecalculatebleStat::fastSave()
{
    return saveStat(false);
}

MagicDamageStat::MagicDamageStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                 Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int MagicDamageStat::recalculate()
{
    setValue(floor(1.5 * Magic->getFinalValue()) + floor(1.5 * Intelligence->getFinalValue()) + floor(0.5 * Will->getFinalValue()));

    return finalValue;

}

ResistPhysicalDamageStat::ResistPhysicalDamageStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                                   Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int ResistPhysicalDamageStat::recalculate()
{
    setValue(floor(1.5 * Will->getFinalValue()) + floor(0.5 * Magic->getFinalValue()) + BodyType->getFinalValue());

    return finalValue;
}

ResistMagicDamageStat::ResistMagicDamageStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                             Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int ResistMagicDamageStat::recalculate()
{
    setValue(floor(1.5 * Will->getFinalValue()) + floor(0.5 * BodyType->getFinalValue()) + Magic->getFinalValue());

    return finalValue;
}

ResistPhysicalEffectsStat::ResistPhysicalEffectsStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                                     Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int ResistPhysicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * Will->getFinalValue()) + 10);

    return finalValue;
}

ResistMagicEffectsStat::ResistMagicEffectsStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                               Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int ResistMagicEffectsStat::recalculate()
{
    setValue(floor(0.1 * Will->getFinalValue()) + floor(0.1 * Magic->getFinalValue()) + 5);

    return finalValue;
}

StrengtheningPhysicalEffectsStat::StrengtheningPhysicalEffectsStat(int maximum, QString personName, QString statName, Stat* Strength,
                                                                   Stat* Agility, Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int StrengtheningPhysicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * Strength->getFinalValue()));

    return finalValue;
}

StrengtheningMagicalEffectsStat::StrengtheningMagicalEffectsStat(int maximum, QString personName, QString statName, Stat* Strength,
                                                                 Stat* Agility, Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int StrengtheningMagicalEffectsStat::recalculate()
{
    setValue(floor(0.1 * Intelligence->getFinalValue()));

    return finalValue;
}

MeleeAccuracyStat::MeleeAccuracyStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                     Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int MeleeAccuracyStat::recalculate()
{
    setValue(floor(0.1 * Agility->getFinalValue()) + 20);

    return finalValue;
}

RangedAccuracyStat::RangedAccuracyStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                       Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int RangedAccuracyStat::recalculate()
{
    setValue(floor(0.1 * Agility->getFinalValue()) + 15);

    return finalValue;
}

MagicAccuracyStat::MagicAccuracyStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                     Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int MagicAccuracyStat::recalculate()
{
    setValue(floor(0.1 * Intelligence->getFinalValue()) + 15);

    return finalValue;
}

EvasionStat::EvasionStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                         Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int EvasionStat::recalculate()
{
    setValue(floor(0.5 * Agility->getFinalValue()) + floor(0.1 * BodyType->getFinalValue()));

    return finalValue;
}

StealthStat::StealthStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                         Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int StealthStat::recalculate()
{
    setValue(Intelligence->getFinalValue() + Agility->getFinalValue());

    return finalValue;
}

AttentivenessStat::AttentivenessStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                     Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int AttentivenessStat::recalculate()
{
    setValue(Intelligence->getFinalValue() + Agility->getFinalValue() + Will->getFinalValue());

    return finalValue;
}

LoadCapacityStat::LoadCapacityStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                   Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int LoadCapacityStat::recalculate()
{
    setValue(floor(0.5 * Strength->getFinalValue()) + floor(0.5 * BodyType->getFinalValue()));

    return finalValue;
}

InitiativeStat::InitiativeStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                               Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int InitiativeStat::recalculate()
{
    setValue(floor(5 * Agility->getFinalValue()) + Intelligence->getFinalValue() + Will->getFinalValue());

    return finalValue;
}

MagicCastChanceStat::MagicCastChanceStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                         Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int MagicCastChanceStat::recalculate()
{
    setValue(floor(0.3 * Intelligence->getFinalValue()) + floor(0.2 * Magic->getFinalValue()));

    return finalValue;
}

ChanceOfUsingCombatTechniqueStat::ChanceOfUsingCombatTechniqueStat(int maximum, QString personName, QString statName, Stat* Strength,
                                                                   Stat* Agility, Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int ChanceOfUsingCombatTechniqueStat::recalculate()
{
    setValue(floor(0.2 * Agility->getFinalValue()) + 20);

    return finalValue;
}

MoveRangeStat::MoveRangeStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                             Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int MoveRangeStat::recalculate()
{
    setValue(floor(0.75 * Agility->getFinalValue()) + floor(0.5 * Strength->getFinalValue()) + BodyType->getFinalValue());

    return finalValue;
}

HealthStat::HealthStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                       Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :ProgressBarStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int HealthStat::recalculate()
{
    setValue(Strength->getFinalValue() * 2 + BodyType->getFinalValue() * 10 + Will->getFinalValue() * 5 + Magic->getFinalValue());

    return finalValue;
}

EnduranceStat::EnduranceStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                             Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :ProgressBarStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int EnduranceStat::recalculate()
{
    setValue(Agility->getFinalValue() * 10 + BodyType->getFinalValue());

    return finalValue;
}

ManaStat::ManaStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                   Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :ProgressBarStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}
int ManaStat::recalculate()
{
    setValue(Magic->getFinalValue() * 10 + Intelligence->getFinalValue() * 2 + Will->getFinalValue());

    return finalValue;
}

ProgressBarStat::ProgressBarStat(int maximum, QString personName, QString statName, Stat* Strength, Stat* Agility,
                                 Stat* Intelligence, Stat* Magic, Stat* BodyType, Stat* Will)
    :RecalculatebleStat(maximum, personName, statName, Strength, Agility, Intelligence, Magic, BodyType,  Will)
{}

int ProgressBarStat::getProgressBarCurrentValue() const
{
    return progressBarCurrentValue;
}

//Задание текущего значения прогрессбара, при этом finalValue, в таком случае, является максимальным значением прогрессбара
void ProgressBarStat::setProgressBarCurrentValue(int newProgressBarCurrentValue)
{
    if(newProgressBarCurrentValue>value)
        newProgressBarCurrentValue = value;
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

ProgressBarStat &ProgressBarStat::operator=(const ProgressBarStat &stat)
{
    Stat::operator=(stat);
    progressBarCurrentValue = stat.progressBarCurrentValue;

    return *this;
}

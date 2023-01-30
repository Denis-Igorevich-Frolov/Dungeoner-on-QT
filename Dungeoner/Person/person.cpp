/********************************************************************************************************************
 *Данный класс является классом вычисления, хранения, управления, сохранения и загрузки всех данных о персонаже.
 ********************************************************************************************************************/

#include "person.h"
#include "QtSql/qsqldatabase.h"

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
    magicDefense.addBonus(bonus);
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
    bool successful = magicDefense.removeBonus(bonus);

    if (!successful)
        fullReinitialization();
    return successful;
}

//Перерасчёт вторичных навыков
void Person::recalculateStats()
{
    for(RecalculatebleStat* stat : secondaryStatsVector)
        stat->recalculate();
    recalculateMagicDefense();
}

//Перерасчёт количества родных чанков магической защиты
void Person::recalculateMagicDefense()
{
    int numberOfChunks = 0;
    //Требование для появления нового чанка магической защиты
    int requirementOfChunk = 5;
    int will = stats->primaryStats->Will->getFinalValue();
    /*Общая сумма требований воли до получения ещё одного чанка. Служит для передачи
     *подсказке информации о том сколько ещё нужно воли до появления нового чанка*/
    int amountOfRequirements = requirementOfChunk;

    //Если воли достаточно для получения хотябы одного чанка
    if(will>=requirementOfChunk){
        /*Вычисляется сколько остаётся воли после заполнения первого чанка.
         *Единица 1 раз вычитается из требований чтобы последующий цикл каждый
         *раз толкался на одну дополнительную итерацию, заполняя количество
         *чанков, и главное, заполняя требования для получения следующего чанка.*/
        will-=requirementOfChunk-1;
        while(true){
            numberOfChunks++;
            //Требования экспоненциально растут
            requirementOfChunk*=1.2;
            /*Вычисляется общая сумма требований, а из-за толкания на дополнительную
             *итерацию эти требования всегда для уже последующего чанка, а не текущего*/
            amountOfRequirements+=requirementOfChunk;
            //Вычисляется сколько остаётся воли после заполнения нового чанка
            will-=requirementOfChunk;
            /*Меньше или равным нулю воля может оказаться только если
             *требования на появления ещё одного чанка не соблюдены*/
            if(will<=0){
                break;
            }
        }
    }

    //Прогрессбару магической защиты передаётся значение недостающей воли до появления ещё одного чанка
    willUntilNextChunk = amountOfRequirements - stats->primaryStats->Will->getFinalValue();

    //Генерируется новый вектор чанков исходя из новых статов
    QVector<Chunk*> chunks;
    for(int i = 0; i<numberOfChunks; i++){
        int chunkValue = floor(stats->primaryStats->Magic->getFinalValue() * 0.7 + stats->primaryStats->BodyType->getFinalValue() * 0.3);
        chunks.append(new Chunk(chunkValue, 0));
    }

    magicDefense.setNativeChunks(chunks);
}

MagicDefense *Person::getMagicDefense()
{
    return &magicDefense;
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

    return true;
}

bool Person::saveMagicDefense(bool createBackup)
{
    //Сначала сохраняется текущее значение прогрессбара для магической защиты
    bool succesSaveValue = true/* saveStat("MagicDefense", 0, 0, magicDefense.getValue(), QVector<Bonus*>{}, false, true, false, false)*/;
    //Скобки нужны чтобы к моменту закрытия базы данных QSqlDatabase database вышел из своей зоны видимости и удалился
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
                    "Person выдал ошибку в методе saveMagicDefense.\n"
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

        /*Создаётся таблица бонусов магической защиты. У каждого такого бонуса в отличии от обычного бонуса
         *стата есть уникальный id, так как у магической защиты один бонус может вносить более одного изменения,
         *а именно добавлять неопределённое количество новых бонусных чанков, и надо точно знать какой бонус
         *добавил какие чанки.*/
        QSqlQuery query(database);
        if(!query.exec("CREATE TABLE IF NOT EXISTS MagicDefenseBonuses("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "value INTEGER NOT NULL DEFAULT 0, "
                       "static_position INTEGER NOT NULL DEFAULT 0, "
                       "dynamic_position INTEGER NOT NULL DEFAULT 0, "
                       "is_percentage INTEGER NOT NULL DEFAULT 0, "
                       "is_dynamic INTEGER NOT NULL DEFAULT 0, "
                       "is_bonus_chunk INTEGER NOT NULL DEFAULT 0, "
                       "bonus_name TEXT NOT NULL, "
                       "duration_days INTEGER NOT NULL DEFAULT 0, "
                       "duration_hours INTEGER NOT NULL DEFAULT 0, "
                       "duration_minutes INTEGER NOT NULL DEFAULT 0, "
                       "duration_seconds INTEGER NOT NULL DEFAULT 0, "
                       "CONSTRAINT static_position_chek CHECK (static_position >= 0), "
                       "CONSTRAINT dynamic_position_chek CHECK (dynamic_position >= 0 AND dynamic_position <= 3), "
                       "CONSTRAINT is_percentage_bool_chek CHECK (is_percentage >= 0 AND is_percentage <= 1), "
                       "CONSTRAINT is_dynamic_bool_chek CHECK (is_dynamic >= 0 AND is_dynamic <= 1), "
                       "CONSTRAINT is_bonus_chunk_bool_chek CHECK (is_bonus_chunk >= 0 AND is_bonus_chunk <= 1), "
                       "CONSTRAINT stat_name_chek CHECK (bonus_name != ''), "
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
                    "Person выдал ошибку в методе saveMagicDefense.\n"
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

        //Сброс автоинкремента id бонусов магической защиты. Всё-равно они сейчас будут полностью перезаписаны, и нет смысла копиться этому инкременту
        if(!query.exec("UPDATE sqlite_sequence SET seq = 0 WHERE name = 'MagicDefenseBonuses';")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось обновить данные в таблице\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
                    "Не удалось обновить данные в таблице базы данных Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite\n\n";
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

        //Полная очистка всех бонусов магической защиты. В старых значениях уже нет нужды, сейчас они заменятся атуальными
        if(!query.exec("DELETE FROM MagicDefenseBonuses;")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось удалить данные из таблицы\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
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

        //Создание таблицы бонусных чанков. Каждый чанк этой таблицы знает, путём передачи id, какой бонус породил его
        if(!query.exec("CREATE TABLE IF NOT EXISTS MagicDefenseBonusChunks("
                       "bonus_id INTEGER NOT NULL, "
                       "value INTEGER NOT NULL DEFAULT 0);"
                       )){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось создать таблицу\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
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

        //Полная очистка всех бонусных чанков магической защиты. В старых значениях уже нет нужды, сейчас они заменятся атуальными
        if(!query.exec("DELETE FROM MagicDefenseBonusChunks;")){

            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось удалить данные из таблицы\n"
                    "Person выдал ошибку в методе saveMagicDefense.\n"
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

        for(MagicDefenseBonus* bonus : magicDefense.getBonuses()){
            if(!query.exec("INSERT INTO MagicDefenseBonuses (value, static_position, dynamic_position, is_percentage, is_dynamic, is_bonus_chunk, bonus_name, "
                           "duration_days, duration_hours, duration_minutes, duration_seconds) VALUES (" + QString::number(bonus->getValue()) + ", " +
                           QString::number(bonus->staticPosition) + ", " + QString::number(bonus->dynamicPosition) + ", " + QString::number(bonus->isPercentage) +
                           ", " + QString::number(bonus->isDynamic) + ", " + QString::number(bonus->isBonusChunk) + ", '" + bonus->bonusName + "', " +
                           QString::number(bonus->getDurationDays()) + ", " + QString::number(bonus->getDurationHours()) + ", " + QString::number(bonus->getDurationMinutes())
                           + ", " + QString::number(bonus->getDurationSeconds()) + ");")){

                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось записать данные в таблицу\n"
                        "Person выдал ошибку в методе saveMagicDefense.\n"
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

            if(bonus->isBonusChunk){
                for(int i : bonus->getBonusChunksMaxVales()){
                    //Считывание id текущего бонуса
                    if( !query.exec("SELECT seq FROM sqlite_sequence WHERE name IS 'MagicDefenseBonuses';")) {
                        //Вывод предупреждения в консоль и файл
                        QDate cd = QDate::currentDate();
                        QTime ct = QTime::currentTime();

                        QString error =
                                cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                                "\nОШИБКА: Не удалось считать данные из таблицы\n"
                                "Person выдал ошибку в методе loadStat.\n"
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
                    int id = query.value(0).toInt();

                    //Если бонус на чанки, то значения всех новых чанков забиваются в таблицу бонусных чанков с указанием id бонуса породившего их
                    if(!query.exec("INSERT INTO MagicDefenseBonusChunks (bonus_id, value) VALUES (" +  QString::number(id) + ", " + QString::number(i) + ");")){
                        //Вывод предупреждения в консоль и файл
                        QDate cd = QDate::currentDate();
                        QTime ct = QTime::currentTime();

                        QString error =
                                cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                                "\nОШИБКА: Не удалось записать данные в таблицу\n"
                                "Person выдал ошибку в методе saveMagicDefense.\n"
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
        }
        database.close();
    }
    QSqlDatabase::removeDatabase("save");

    return succesSaveValue;
}
bool Person::loadMagicDefense()
{
    //Скобки нужны чтобы к моменту закрытия базы данных QSqlDatabase database вышел из своей зоны видимости и удалился
    {
        QDir dir;
        if(!dir.exists("Game Saves/"+Global::DungeonName+"/Heroes/"+personName)){
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе loadMagicDefense.\n"
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

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "save");
        database.setDatabaseName("Game Saves/"+Global::DungeonName+"/Heroes/"+personName+"/save.sqlite");

        if(!database.open()) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
            "\nОШИБКА: Ошибка открытия файла\n"
            "Person выдал ошибку в методе loadMagicDefense.\n"
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
        if( !query.exec( "SELECT * FROM MagicDefenseBonuses;")) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось считать данные из таблицы\n"
                    "Person выдал ошибку в методе loadMagicDefense.\n"
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

        //Удаление всех бонусов магической защиты, так как они сейчас будут переинициализированы данными из БД
        magicDefense.removeAllBonuses();
        while (query.next()){
            //Проверка является ли бонус бонусом на чанки
            if(query.value(6).toBool()){
                QSqlQuery chunksQuery(database);
                //Поиск всех бонусных чанков, созданых бонусом с текущим id
                if( !chunksQuery.exec( "SELECT value FROM MagicDefenseBonusChunks WHERE bonus_id IS " + query.value(0).toString() + ";")) {
                    //Вывод предупреждения в консоль и файл
                    QDate cd = QDate::currentDate();
                    QTime ct = QTime::currentTime();

                    QString error =
                            cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                            "\nОШИБКА: Не удалось считать данные из таблицы\n"
                            "Person выдал ошибку в методе loadMagicDefense.\n"
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

                //Создание и передача бонуса на чанки
                QVector<int> bonusChunksMaxVales;
                while(chunksQuery.next()){
                    bonusChunksMaxVales.append(chunksQuery.value(0).toInt());
                }
                magicDefense.addBonus(new MagicDefenseBonus(bonusChunksMaxVales, query.value(7).toString(), query.value(8).toInt(),
                                                            query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));

            //Проверка является ли бонус динамическим
            }else if(query.value(5).toBool())
                magicDefense.addBonus(new MagicDefenseBonus(MagicDefenseBonus::DynamicPosition(query.value(3).toInt()),
                                                            query.value(1).toInt(), query.value(4).toBool(), query.value(7).toString(),
                                                            query.value(8).toInt(), query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));
            //Иначе он статический
            else
                magicDefense.addBonus(new MagicDefenseBonus(query.value(2).toInt(), query.value(1).toInt(), query.value(4).toBool(), query.value(7).toString(),
                                                            query.value(8).toInt(), query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));
        }

        //Считывание из БД текущего значения прогрессбара магической защиты
        if( !query.exec( "SELECT progress_bar_current_value FROM Stats WHERE stat_name IS 'MagicDefense';")) {
            //Вывод предупреждения в консоль и файл
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();

            QString error =
                    cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                    "\nОШИБКА: Не удалось считать данные из таблицы\n"
                    "Person выдал ошибку в методе loadStat.\n"
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


        //Пересчёт вектора чанков магической защиты
        recalculateMagicDefense();
        //Обнуление текущего значения прогрессбара, так как ему будет передано значение из БД
        magicDefense.subtractValue(magicDefense.getValue());

        query.first();
        //Передача текущего значения прогрессбара
        magicDefense.addValue(query.value(0).toInt());

        database.close();
    }

    QSqlDatabase::removeDatabase("save");
    return true;
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

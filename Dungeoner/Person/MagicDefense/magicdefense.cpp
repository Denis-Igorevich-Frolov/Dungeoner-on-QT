/**************************************************************************
 *Данный класс является статом магической защиты. Вся необходимая логика
 *по вычислению векторов чанков магической защиты происходит здесь.
 **************************************************************************/

#include "magicdefense.h"
#include "Person/SecondaryStat/secondarystat.h"
#include "qdir.h"
#include "Global/global.h"
#include "qsqlquery.h"

#include <QDate>
#include <qfile.h>
#include <qsqldatabase.h>

MagicDefense::~MagicDefense()
{
    for(Chunk* chunk : nativeChunks)
        delete chunk;

    for(Chunk* chunk : bonusChunks)
        delete chunk;

    for(MagicDefenseBonus* bonus : bonuses)
        delete bonus;
}

MagicDefense::MagicDefense(QString personName, PrimaryStatsStruct *primaryStats):
    RecalculatebleStat(600000, personName, "MagicDefense", primaryStats)
{}

/*Дополнительный конструктор с передоваемой ссылкой на вектор указателей на стат. При
 *использовании этого конструктора, полученный стат автоматически добавится в коллекцию.*/
MagicDefense::MagicDefense(QString personName, PrimaryStatsStruct *primaryStats, QVector<RecalculatebleStat *> &stats):
    MagicDefense(personName, primaryStats)
{
    stats.append(this);
}

int MagicDefense::getValue() const
{
    return value;
}

/*Метод устанавливает общее значение всему прогрессбару, последовательно заполняя все чанки пока
 *не кончится переданное значение. Используется для первичной инициализации и сохранения значения
 *при перерасчёте векторов прогрессбара из переменной value, чтобы оно не сбрасывалось при любом
 *изменении.*/
void MagicDefense::setValue(int newValue)
{
    /*Исходя из максимального значения чанка в 10000 и максимального их количества
     *в 60, значение никогда не превысит 600000, а значение ниже 0 бессмысленно*/
    if(newValue>maximum)
        newValue = maximum;
    else if(newValue<0)
        newValue = 0;

    value = newValue;

    for(Chunk* chunk : chunks){
        //Вычисляется недостающая разница текущего значения до заполнения до максимального
        int difference = chunk->getFinalMaxValue()-chunk->getValue();
        /*Если эта разница меньше или равна передаваемому значению, то текущий чанк заполняется до
         *максимума, а из переданного значения вычитается затраченное на заполнение чанка значение*/
        if(difference<=value){
            chunk->setValue(chunk->getFinalMaxValue());
            value-=difference;
        /*Если же значение меньше разницы, то оно просто прибавляется к текущему значению чанка, заполняя
         *его на сколько хватает. И цикл останавливается так как всё переданное значение потрачено*/
        }else{
            chunk->setValue(chunk->getValue()+value);
            break;
        }
        //Если всё переданное значение потрачено, то цикл останавливается
        if(value<=0)
            break;
    }
}

void MagicDefense::addBonus(MagicDefenseBonus *bonus)
{
    bonuses.append(bonus);

    recalculate();
    //После изменения вектора бонусных чанков требуется полный перерасчёт общего вектора
    recalculationChunks();
    addValue(value);
}

/*Удаление бонуса. В метод передаётся указатель на бонус, который должен быть удалён. При этом
 *удаляется первый подошедший с конца бонус, а не конкретно тот, который инициировал удаление.
 *Если метод не смог обнаружить переданный на удаление бонус, он выводит предупреждение и
 *возвращает false, после чего следует запросить полный перерасчёт бонусов.*/
bool MagicDefense::removeBonus(MagicDefenseBonus *bonus)
{
    QMutableVectorIterator<MagicDefenseBonus*> iterator(bonuses);
    iterator.toBack();
    MagicDefenseBonus* MD;
    //Итератор идёт с конца, чтобы найти ближайшее к краю совпадение
    while(iterator.hasPrevious()){
        MD = iterator.previous();
        if(*MD==*bonus){
            delete MD;
            iterator.remove();

            recalculate();
            //После изменения вектора бонусных чанков требуется полный перерасчёт общего вектора
            recalculationChunks();
            addValue(value);
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

//Перерасчёт всех бонусов магической защиты
void MagicDefense::updateBonuses()
{
    //Удаляютя все бонусы с чанков, так как они сейчас будут переинициализированы и назначены заново
    for(Chunk* chunk : nativeChunks)
        chunk->clearBonuses();

    //Также удаляются и все бонусные чанки
    for(Chunk* chunk : bonusChunks)
        delete chunk;
    bonusChunks.clear();

    for(MagicDefenseBonus* bonus : bonuses){
        if(bonus->isBonusChunk){
            for(int bonusChunkMaxValue : bonus->getBonusChunksMaxVales())
                bonusChunks.append(new Chunk(bonusChunkMaxValue, 0));
        }
        else{
            if(bonus->isDynamic && !nativeChunks.isEmpty()){
                if(bonus->dynamicPosition == MagicDefenseBonus::FIRST){
                    nativeChunks.first()->addBonus(bonus);
                }else if(bonus->dynamicPosition == MagicDefenseBonus::LAST){
                    nativeChunks.last()->addBonus(bonus);
                }else if(bonus->dynamicPosition == MagicDefenseBonus::CENTER){
                    int position = nativeChunks.size()/2;
                    nativeChunks.at(position)->addBonus(bonus);
                }else if(bonus->dynamicPosition == MagicDefenseBonus::ALL){
                    for(Chunk* chunk : nativeChunks)
                        chunk->addBonus(bonus);
                    //Бонусу передаётся информация о том сколько чанков он изменил. Это требуется для информации в подсказке
                    bonus->setNumberOfChunksChanged(nativeChunks.size());
                }
            }else if(bonus->staticPosition <= nativeChunks.size() && bonus->staticPosition>0){
                nativeChunks.at(bonus->staticPosition-1)->addBonus(bonus);
            }else
                //Если чанка, к котому следует назначить бонус не существует, то финальное значение такого бонуса - 0
                bonus->setFinalValue(0);
        }
    }
    //Сортировка бонусов по степени воздействия
    std::sort(bonuses.begin(), bonuses.end(), [](MagicDefenseBonus* a, MagicDefenseBonus* b) {
        return *a > *b;
    });
}

//Получение количества родных чанков. Нужно только для подсказок
int MagicDefense::getNativeChunksSize()
{
    return nativeChunks.size();
}

//Перерасчёт количества родных чанков магической защиты
int MagicDefense::recalculate()
{
    int numberOfChunks = 0;
    //Требование для появления нового чанка магической защиты
    int requirementOfChunk = 5;
    int will = primaryStats->Will->getFinalValue();
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
    willUntilNextChunk = amountOfRequirements - primaryStats->Will->getFinalValue();

    //Генерируется новый вектор чанков исходя из новых статов
    QVector<Chunk*> chunks;
    for(int i = 0; i<numberOfChunks; i++){
        int chunkValue = floor(primaryStats->Magic->getFinalValue() * 0.7 + primaryStats->BodyType->getFinalValue() * 0.3);
        chunks.append(new Chunk(chunkValue, 0));
    }

    setNativeChunks(chunks);

    return numberOfChunks;
}

int MagicDefense::getWillUntilNextChunk() const
{
    return willUntilNextChunk;
}

/*Удаление бонусного чанка. В метод передаётся указатель на чанк, который должен быть удалён из
 *вектора бонусных чанков. При этом удаляется первый подошедший с конца чанк, а не конкретно тот,
 *который инициировал удаление. Это поднимает шансы на то, что так удалится тот чанк, который имеет
 *большие шансы оказаться незаполненным, так как он просто ближе к концу.*/
bool MagicDefense::removeBonusChunk(Chunk *chunk)
{
    QMutableVectorIterator<Chunk*> iterator(bonusChunks);
    iterator.toBack();
    Chunk* c;
    while(iterator.hasPrevious()){
        c = iterator.previous();
        if(c->getMaxValue()==chunk->getFinalMaxValue()){
            delete c;
            iterator.remove();
            //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
            recalculationChunks();
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
    "\nПРЕДУПРЕЖДЕНИЕ: не найден Chunk\n"
    "ProgressBar_2 выдал предупреждение в методе removeBonusChunk.\n"
    "При попытке удалить Chunk, он не был обнаружен.\n\n";
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

/*Обнуляет текущий активный чанк. Если обнуление было произведено, то водвращает true, если
 *нет - то это означает, что весь прогрессбар уже полностью обнулён и возвращается false*/
bool MagicDefense::spendLastChunk()
{
    //Проверка не пуст ли вектор чанков
    if(chunks.size()>0){
        int chunkIndex = getCurrentChunkIndex();
        /*Значение текущего чанка может быть равно нулю только в ситуации,
         *когда этот чанк первый и он пуст, соответственно обнулять нечего*/
        if(chunks.at(chunkIndex)->getValue()!=0){
            chunks.at(chunkIndex)->setValue(0);
            //После изменения значений нужно пересчетать общее заполненное значение всех векторов
            calculateValue();

            emit statChanged();
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

//Приравнивает значение текущего активного чанка к его максимальному значению
void MagicDefense::HealOneChunk()
{
    for(Chunk* chunk : chunks)
        if (chunk->getValue()!=chunk->getFinalMaxValue()){
            chunk->setValue(chunk->getFinalMaxValue());
            break;
        }
    calculateValue();

    emit statChanged();
}

//Приравнивает значение всех чанков к их максимальному значению
void MagicDefense::HealAllChunk()
{
    for(Chunk* chunk : chunks)
        chunk->setValue(chunk->getFinalMaxValue());
    calculateValue();

    emit statChanged();
}

bool MagicDefense::saveStat(bool saveValue, bool saveBonuses, bool createBackup)
{
    if(createBackup)
        this->createBackup();

    bool succesSaveValue = true;

    if(saveValue){
        //Сохранение текущего значение прогрессбара для магической защиты
        succesSaveValue = Stat::saveStat(true, false, false);
    }
    if(saveBonuses)
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
                    "MagicDefense выдал ошибку в методе saveMagicDefense.\n"
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
                    "MagicDefense выдал ошибку в методе saveMagicDefense.\n"
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
                    "MagicDefense выдал ошибку в методе saveMagicDefense.\n"
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
                    "MagicDefense выдал ошибку в методе saveMagicDefense.\n"
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
                    "MagicDefense выдал ошибку в методе saveMagicDefense.\n"
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
                    "MagicDefense выдал ошибку в методе saveMagicDefense.\n"
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

        for(MagicDefenseBonus* bonus : bonuses){
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
                        "MagicDefense выдал ошибку в методе saveMagicDefense.\n"
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
                                "MagicDefense выдал ошибку в методе loadStat.\n"
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
                                "MagicDefense выдал ошибку в методе saveMagicDefense.\n"
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
        //Если всё выполнилось успешно, то транзакция комитится
        if(!query.exec()){
           database.rollback();
           //Вывод предупреждения в консоль и файл
           QDate cd = QDate::currentDate();
           QTime ct = QTime::currentTime();

           QString error =
                   cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                   "\nОШИБКА: Ошибка транзакции при сохранении базы данных\n"
                   "MagicDefense выдал ошибку в методе saveStat.\n"
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

    return succesSaveValue;
}

bool MagicDefense::loadStat(bool loadValue, bool loadBonuses)
{
    //Скобки нужны чтобы к моменту закрытия базы данных QSqlDatabase database вышел из своей зоны видимости и удалился
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
            "MagicDefense выдал ошибку в методе loadMagicDefense.\n"
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
            "MagicDefense выдал ошибку в методе loadMagicDefense.\n"
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

        if(loadBonuses){
            if( !query.exec( "SELECT * FROM MagicDefenseBonuses;")) {
                //Вывод предупреждения в консоль и файл
                QDate cd = QDate::currentDate();
                QTime ct = QTime::currentTime();

                QString error =
                        cd.toString("d-MMMM-yyyy") + "  " + ct.toString(Qt::TextDate) +
                        "\nОШИБКА: Не удалось считать данные из таблицы\n"
                        "MagicDefense выдал ошибку в методе loadMagicDefense.\n"
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
            removeAllBonuses();
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
                                "MagicDefense выдал ошибку в методе loadMagicDefense.\n"
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
                    addBonus(new MagicDefenseBonus(bonusChunksMaxVales, query.value(7).toString(), query.value(8).toInt(),
                                                   query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));

                    //Проверка является ли бонус динамическим
                }else if(query.value(5).toBool())
                    addBonus(new MagicDefenseBonus(MagicDefenseBonus::DynamicPosition(query.value(3).toInt()),
                                                   query.value(1).toInt(), query.value(4).toBool(), query.value(7).toString(),
                                                   query.value(8).toInt(), query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));
                //Иначе он статический
                else
                    addBonus(new MagicDefenseBonus(query.value(2).toInt(), query.value(1).toInt(), query.value(4).toBool(), query.value(7).toString(),
                                                   query.value(8).toInt(), query.value(9).toInt(), query.value(10).toInt(), query.value(11).toInt()));
            }
        }

        //Пересчёт вектора чанков магической защиты
        recalculate();
        //Обнуление текущего значения прогрессбара, так как ему будет передано значение из БД
        subtractValue(maximum);

        query.first();

        database.close();
    }

    QSqlDatabase::removeDatabase("load");

    if(loadValue){
        Stat::loadStat(true, false);
        addValue(value);
    }

    return true;
}

bool MagicDefense::fastSave()
{
    return saveStat(true, true, false);
}

bool MagicDefense::fastLoad()
{
    return loadStat(true, true);
}

QVector<Chunk *> MagicDefense::getChunks()
{
    return chunks;
}

void MagicDefense::setNativeChunks(QVector<Chunk *> &newChunks)
{
    //Вызов этого метода означает переинициализацию и следовательно необходимо уничтожить все старые ссылки
    clearNativeChunks();

    /*Максимальная длина вектора родных чанков равна 50, если
     *она привышена, то вектор усекается до 50 значений*/
    if(newChunks.size()>50){
        QVector<Chunk*> newNChunks;
        for(int i = 0; i<50; i++)
            newNChunks.append(newChunks.at(i));
        nativeChunks = newNChunks;

        /*Так как вектор родных чанков динамически генерируется каждый раз заного, и неуместившиеся ячейки
         *никогда не понадобятся, необходимо высвобождение памяти у остатка переданного вектора*/
        QVectorIterator<Chunk*> iterator(newChunks);
        iterator.toBack();
        Chunk* c;
        for(int i = newChunks.size(); i>50; i--){
            c = iterator.previous();
            delete c;
        }
    }else
        nativeChunks = newChunks;

    recalculationChunks();
}

void MagicDefense::setBonusChunks(const QVector<Chunk *> &newChunks)
{
    /*Так как ссылки на бонусные чанки хранятся и удаляются в классах,
     *которые их сюда направили, высвобождение памяти не требуется*/

    //обнуление значений
    for(Chunk* chunk : newChunks)
        chunk->setValue(0);

    bonusChunks = newChunks;

    recalculationChunks();
}

/*Добавление чанка в вектор бонусных чанков. В метод передаётся указатель на новый чанк, затем его
 *текущее значение обнуляется и указатель добавляется в конец вектора бонусных чанков. Новый чанк
 *будет иметь текущее значение 0, так как все бонусы дают прибавку только к максимальному значению,
 *а не к текущему.*/
void MagicDefense::addBonusChunk(Chunk *chunk)
{
    chunk->setValue(0);
    bonusChunks.append(chunk);
    recalculationChunks();
}

//Добавление одного чанка в вектор родных чанков
void MagicDefense::addChunk(Chunk *chunk)
{
    if(nativeChunks.size()<50){
        chunk->setValue(0);
        nativeChunks.append(chunk);
    }

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunks();
}

int MagicDefense::getTotalValueWithoutBonuses() const
{
    return totalValueWithoutBonuses;
}

//Вычисление текущего общего заполненного значения всех чанков прогрессбара
void MagicDefense::calculateValue()
{
    value = 0;

    for(int i = 0; i<chunks.size(); i++){
        value+=chunks.at(i)->getValue();
    }
}

//Перерасчёт общего вектора всех чанков, который включает в себя и родные и бонусные чанки
void MagicDefense::recalculationChunks()
{
    updateBonuses();
    /*Если суммарное количество родных и бонусных чанков превышает 60,
     *то родные чанки вытесняют бонусные. В конечном итоге общая сумма
     *родных и бонусных чанков никогда не превышает 60.*/
    if(nativeChunks.size()+bonusChunks.size() > 60){
        finalBonusChunks.clear();
        /*Добавление бонусных чанков в общий вектор продолжается пока его
         *размер не достигнет 60, оставшиеся чанки считаются вытеснеными*/
        for(int i = 0; i<60-nativeChunks.size(); i++){
            /*Необходимо сбросить все значения, у родных чанков это происходит автоматически, а у
             *бонусных здесь. Прогрессбар помнит своё общее значение в переменной value и позже
             *заполнит им чанки в методе setValue. Делается это для ситуации когда бонусные чанки
             *заполнены, а вектор родных расширяется пустыми новыми чанками. Получается разрыв в
             *заполнении чанков, чего происходить не должно, а так заполнение как бы перетечёт в
             *новые пустые чанки.*/
            bonusChunks.at(i)->setValue(0);

            finalBonusChunks.append(bonusChunks.at(i));
        }
    }else{
        /*Необходимо сбросить все значения, у родных чанков это происходит автоматически, а у
         *бонусных здесь. Прогрессбар помнит своё общее значение в переменной value и позже
         *заполнит им чанки в методе setValue. Делается это для ситуации когда бонусные чанки
         *заполнены, а вектор родных расширяется пустыми новыми чанками. Получается разрыв в
         *заполнении чанков, чего происходить не должно, а так заполнение как бы перетечёт в
         *новые пустые чанки.*/
        for(Chunk* chunk : bonusChunks)
            chunk->setValue(0);

        finalBonusChunks = bonusChunks;
    }

    chunks.clear();

    //Добавляются сначала рордные, а затем бонусные чанки
    chunks.append(nativeChunks);
    chunks.append(finalBonusChunks);

    //Вычисляется общее максимальное значение всех чанков с учётом бонусов и без них
    totalValue = 0;
    totalValueWithoutBonuses = 0;
    for(Chunk* chunk : chunks){
        totalValue+=chunk->getFinalMaxValue();
        totalValueWithoutBonuses+=chunk->getMaxValue();
    }

    //Если значение больше максимального, то оно усекается до максимального
    if(value > totalValue)
        value = totalValue;

    amountOfNativeChunks = nativeChunks.size();
    amountOfBonusChunks = bonusChunks.size();
}

/*Метод возвращает индекс текущего активного чанка. Текущим чанком
 *считается последний чанк, имеющий ненулевое значение.*/
int MagicDefense::getCurrentChunkIndex()
{
    int currentChunk = 0;

    for(int i = 0; i<chunks.size(); i++)
        if(chunks.at(i)->getValue()!=0)
           currentChunk++;
        /*Если значение чанка равно нулю, то и значения всех последующих
         *чанков будут также равны нулю и нет смысла дальше гонять цикл*/
        else break;

    /*Если полученное значение равно 0, то прогрессбар пуст,
     *просто возвращается 0, как индекс самого первого чанка*/
    if(currentChunk == 0)
        return 0;

    /*Если же полученное значение нулю не равно, то порядковый
     *номер (отсчёт с 1) приводится к индексу (отсчёт с 0).*/
    return currentChunk-1;
}

/*Метод добавляет значение к текущему чанку. Если максимальное значение чанка не позволяет
 *переданному значению уместиться в нём полностью, то остаток переходит на следующий чанк,
 *и так пока либо не кончится значение, либо не кончатся чанки.*/
void MagicDefense::addValue(int value)
{
    //Предотвращение попадания в метод отрицательных значений
    if(value<0)
        value = 0;

    int currentChunk = getCurrentChunkIndex();
    Chunk* chunk;

    //Цикл идёт либо пока не кончится всё значение прибавки, либо пока не кончатся сами чанки
    while(value>0){
        //Если цикл дошёл до конца вектора чанков, то прибавка сразу прекращается
        if(currentChunk+1 > chunks.size())
            break;

        chunk = chunks.at(currentChunk);
        //Вычисляется разница максимального и текущего значения у текущего чанка
        int difference = chunk->getFinalMaxValue() - chunk->getValue();

        /*Если прибавляемое значение больше, чем эта разница, то чанк полностью заполняется, а из
         *прибавляемого значения вычитается разница. То есть итоговое значение прибавки после
         *этого равняется остатку от максимального заполнения одного чанка переданным значением.*/
        if(value>difference){
            chunk->setValue(chunk->getFinalMaxValue());
            value-=difference;
        }else{
            /*Если же разница больше прибавляемого значения, то это значение просто
             *прибавляется к текущему значению чанка и обнуляется завершая цикл.*/
            chunk->setValue(chunk->getValue()+value);
            value = 0;
        }
        currentChunk++;
    }

    //После изменения значений нужно пересчетать общее заполненное значение всех векторов
    calculateValue();
    emit statChanged();
}

/*Метод вычитает значение из текущего чанка. Если значение чанка меньше переданного вычитаемого
 *значения, то текущий чанк обнуляется, а остаток вычитается из предыдущего чанка, и так пока
 *либо не кончится значение, либо не кончатся чанки.*/
void MagicDefense::subtractValue(int value)
{
    //Предотвращение попадания в метод отрицательных значений
    if(value<0)
        value = 0;

    int currentChunk = getCurrentChunkIndex();
    Chunk* chunk;

    //Цикл идёт либо пока не кончится всё вычитаемое значение, либо пока не кончатся сами чанки
    while(value>0){
        //Если цикл дошёл до начала вектора чанков, то вычитание сразу прекращается
        if(currentChunk == -1)
            break;

        chunk = chunks.at(currentChunk);
        /*Значение текущего чанка может быть равно нулю только в ситуации, когда этот чанк
         *первый и он пуст, соответственно нет надобности в дальнейших вычислениях*/
        if(chunk->getValue()==0)
            break;
        /*Если вычитаемое значение больше значения текущего чанка, то от вычитаемого значения
         *отнимается значение чанка, и чанк обнуляется. То есть итоговое вычитаемое значение
         *после этого равняется остатку от обнуления одного чанка переданным значением.*/
        if(value>chunk->getValue()){
            value-=chunk->getValue();
            chunk->setValue(0);
        }else{
            /*Если же значение чанка больше вычитаемого значения, то это значение просто
             *вычитается из текущего значения чанка и обнуляется завершая цикл.*/
            chunk->setValue(chunk->getValue()-value);
            value = 0;
        }
        currentChunk--;
    }

    //После изменения значений нужно пересчетать общее заполненное значение всех векторов
    calculateValue();

    emit statChanged();
}

int MagicDefense::getTotalValue() const
{
    return totalValue;
}

int MagicDefense::getAmountOfNativeChunks() const
{
    return amountOfNativeChunks;
}

int MagicDefense::getAmountOfBonusChunks() const
{
    return amountOfBonusChunks;
}

/*Очистка вектора родных чанков. Нужно быть осторожным в вызове этого метода, ведь он сам
 *не перерисовывает прогрессбар. После его вызова ОБЯЗАТЕЛЬНО должна быть переинициализация
 *вектора родных чанков, даже пустым вектором, если то нужно. Безопасен только вызов из
 *начала метода setChunks, потому что он сам и переинициализирует вектор родных чанков.*/
void MagicDefense::clearNativeChunks()
{
    /*Так как вектор родных чанков динамически генерируется каждый раз заного, и его ячейки никогда
     *повторно не понадобятся, необходимо высвобождение памяти у элементов этого вектора*/
    for(Chunk* chunk : nativeChunks)
        delete chunk;

    nativeChunks.clear();
}

QVector<MagicDefenseBonus *> MagicDefense::getBonuses()
{
    return bonuses;
}

/*Очистка вектора бонусов. Память указателей на бонусы не высвобождается,
 *так как это должно происходить только в классе предмета или эффекта*/
void MagicDefense::removeAllBonuses()
{
    bonuses.clear();
    recalculate();
    //После изменения вектора бонусных чанков требуется полный перерасчёт общего вектора
    recalculationChunks();
    addValue(value);
}

//Так как класс MagicDefense унаследован от QObject, его оператор присваивания явным образом удалён, соответственно его следует переопределить самому
MagicDefense& MagicDefense::operator= (const MagicDefense &stat)
{
    totalValue = stat.totalValue;
    value = stat.value;
    amountOfNativeChunks = stat.amountOfNativeChunks;
    amountOfBonusChunks = stat.amountOfBonusChunks;
    chunks = stat.chunks;
    nativeChunks = stat.nativeChunks;
    bonusChunks = stat.bonusChunks;
    finalBonusChunks = stat.finalBonusChunks;
    bonuses = stat.bonuses;
    totalValueWithoutBonuses = stat.totalValueWithoutBonuses;

    return *this;
}

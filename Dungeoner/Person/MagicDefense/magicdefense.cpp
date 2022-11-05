#include "magicdefense.h"

#include <QDate>
#include <qfile.h>

MagicDefense::~MagicDefense()
{
    for(Chunk* chunk : nativeChunks)
        delete chunk;

    for(Chunk* chunk : bonusChunks)
        delete chunk;

    for(MagicDefenseBonus* bonus : bonuses)
        delete bonus;
}

int MagicDefense::getValue() const
{
    return value;
}

void MagicDefense::setValue(int newValue)
{
    if(newValue>600000)
        newValue = 600000;
    else if(newValue<0)
        newValue = 0;

    value = newValue;

    for(Chunk* chunk : chunks){
        int difference = chunk->getFinalMaxValue()-chunk->getValue();
        if(difference<=value){
            chunk->setValue(chunk->getFinalMaxValue());
            value-=difference;
        }else{
            chunk->setValue(chunk->getValue()+value);
            break;
        }
        if(value<=0)
            break;
    }
}

void MagicDefense::addBonus(MagicDefenseBonus *bonus)
{
    bonuses.append(bonus);

    recalculationChunks();
}

bool MagicDefense::removeBonus(MagicDefenseBonus *bonus)
{
    QMutableVectorIterator<MagicDefenseBonus*> iterator(bonuses);
    iterator.toBack();
    MagicDefenseBonus* MD;
    while(iterator.hasPrevious()){
        MD = iterator.previous();
        if(MD==bonus){
            delete MD;
            iterator.remove();

            recalculationChunks();
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

void MagicDefense::updateBonuses()
{
    for(Chunk* chunk : nativeChunks){
        chunk->clearBonuses();
    }

    for(Chunk* chunk : bonusChunks)
        delete chunk;
    bonusChunks.clear();

    for(MagicDefenseBonus* bonus : bonuses){
        if(bonus->isBonusChunk){
            for(int bonusChunkMaxValue : bonus->getBonusChunksMaxVales())
                bonusChunks.append(new Chunk(bonusChunkMaxValue, 0));
        }
        else
        {
            if(bonus->isDynamic){
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
                }
            }else if(bonus->staticPosition < nativeChunks.size())
                nativeChunks.at(bonus->staticPosition)->addBonus(bonus);
        }
    }
}

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

            //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
            recalculationChunks();
            return true;
        }else{
            //После изменения значений нужно пересчетать общее заполненное значение всех векторов
            calculateValue();
            return false;
        }
    }else{
        //После изменения значений нужно пересчетать общее заполненное значение всех векторов
        calculateValue();
        return false;
    }
}

void MagicDefense::HealOneChunk()
{
    for(Chunk* chunk : chunks)
        if (chunk->getValue()!=chunk->getFinalMaxValue()){
            chunk->setValue(chunk->getFinalMaxValue());
            break;
        }
    calculateValue();
}

void MagicDefense::HealAllChunk()
{
    for(Chunk* chunk : chunks)
        chunk->setValue(chunk->getFinalMaxValue());
    calculateValue();
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

void MagicDefense::addBonusChunk(Chunk *chunk)
{
    chunk->setValue(0);
    bonusChunks.append(chunk);
    recalculationChunks();
}

void MagicDefense::addChunk(Chunk *chunk)
{
    if(nativeChunks.size()<50){
        chunk->setValue(0);
        nativeChunks.append(chunk);
    }

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunks();
}

void MagicDefense::calculateValue()
{
    value = 0;

    for(int i = 0; i<chunks.size(); i++){
        value+=chunks.at(i)->getValue();
    }
}

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

    //Вычисляется общее максимальное значение всех чанков
    totalValue = 0;
    for(Chunk* chunk : chunks)
        totalValue+=chunk->getFinalMaxValue();

    //Если значение больше максимального, то оно усекается до максимального
    if(value > totalValue)
        value = totalValue;

    amountOfNativeChunks = nativeChunks.size();
    amountOfBonusChunks = bonusChunks.size();
}

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
}

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

    //После изменений векторов нужно пересчитать длинну заполненной области и позиции разделителей
    recalculationChunks();
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

void MagicDefense::clearNativeChunks()
{
    /*Так как вектор родных чанков динамически генерируется каждый раз заного, и его ячейки никогда
     *повторно не понадобятся, необходимо высвобождение памяти у элементов этого вектора*/
    for(Chunk* chunk : nativeChunks)
        delete chunk;

    nativeChunks.clear();
}

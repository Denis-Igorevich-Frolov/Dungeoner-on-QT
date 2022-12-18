/**************************************************************************
 *Данный класс является статом магической защиты. Вся необходимая логика
 *по вычислению векторов чанков магической защиты происходит здесь.
 **************************************************************************/

#ifndef MAGICDEFENSE_H
#define MAGICDEFENSE_H

#include "chunk.h"
#include "magicdefensebonus.h"
#include "qobject.h"

#include <QVector>

class MagicDefense: public QObject
{
    Q_OBJECT
public:
    ~MagicDefense();

    int getValue() const;

    void addBonus(MagicDefenseBonus* bonus);
    /*Удаление бонуса. В метод передаётся указатель на бонус, который должен быть удалён. При этом
     *удаляется первый подошедший с конца бонус, а не конкретно тот, который инициировал удаление.
     *Если метод не смог обнаружить переданный на удаление бонус, он выводит предупреждение и
     *возвращает false, после чего следует запросить полный перерасчёт бонусов.*/
    bool removeBonus(MagicDefenseBonus* bonus);

    QVector<Chunk *> getChunks();

    void setNativeChunks(QVector<Chunk *> &newChunks);
    void setBonusChunks(const QVector<Chunk*> &newChunks);

    /*Обнуляет текущий активный чанк. Если обнуление было произведено, то водвращает true, если
     *нет - то это означает, что весь прогрессбар уже полностью обнулён и возвращается false*/
    bool spendLastChunk();
    //Приравнивает значение текущего активного чанка к его максимальному значению
    void HealOneChunk();
    //Приравнивает значение всех чанков к их максимальному значению
    void HealAllChunk();

    int getTotalValue() const;

    int getAmountOfNativeChunks() const;
    int getAmountOfBonusChunks() const;

    /*Метод возвращает индекс текущего активного чанка. Текущим чанком
     *считается последний чанк, имеющий ненулевое значение.*/
    int getCurrentChunkIndex();
    /*Метод добавляет значение к текущему чанку. Если максимальное значение чанка не позволяет
     *переданному значению уместиться в нём полностью, то остаток переходит на следующий чанк,
     *и так пока либо не кончится значение, либо не кончатся чанки.*/
    void addValue(int value);
    /*Метод вычитает значение из текущего чанка. Если значение чанка меньше переданного вычитаемого
     *значения, то текущий чанк обнуляется, а остаток вычитается из предыдущего чанка, и так пока
     *либо не кончится значение, либо не кончатся чанки.*/
    void subtractValue(int value);

    QVector<MagicDefenseBonus *> getBonuses();

    /*Очистка вектора бонусов. Метод не обновляет отображение бонусов в виджетах. Память указателей на
     *бонусы не высвобождается, так как это должно происходить только в классе предмета или эффекта*/
    void removeAllBonuses();

    //Так как класс MagicDefense унаследован от QObject, его оператор присваивания явным образом удалён, соответственно его следует переопределить самому
    MagicDefense& operator= (const MagicDefense &stat);

    int getTotalValueWithoutBonuses() const;

    //Получение количества родных чанков. Нужно только для подсказок
    int getNativeChunksSize();

signals:
    void bonusesChanged();

private:
    /*Добавление чанка в вектор бонусных чанков. В метод передаётся указатель на новый чанк, затем его
     *текущее значение обнуляется и указатель добавляется в конец вектора бонусных чанков. Новый чанк
     *будет иметь текущее значение 0, так как все бонусы дают прибавку только к максимальному значению,
     *а не к текущему.*/
    void addBonusChunk(Chunk* chunk);
    /*Удаление бонусного чанка. В метод передаётся указатель на чанк, который должен быть удалён из
     *вектора бонусных чанков. При этом удаляется первый подошедший с конца чанк, а не конкретно тот,
     *который инициировал удаление. Это поднимает шансы на то, что так удалится тот чанк, который имеет
     *большие шансы оказаться незаполненным, так как он просто ближе к концу.*/
    bool removeBonusChunk(Chunk* chunk);
    //Добавление одного чанка в вектор родных чанков
    void addChunk(Chunk* chunk);

    //Максимальное значение всего прогрессбара. То есть сумма всех максимальных значений всех чанков
    int totalValue = 0;
    //Текущее общее заполненное значение всех чанков прогрессбара. То есть сумма всех текущих значений всех чанков
    int value = 0;
    //Максимальное значение без чёта бонусов. Хранится для выведения подсказки
    int totalValueWithoutBonuses = 0;

    //Количество родных и бонусных чанков хранятся здесь для более простой передачи этих данных в подсказку
    int amountOfNativeChunks = 0;
    int amountOfBonusChunks = 0;

    //Перерасчёт общего вектора всех чанков, который включает в себя и родные и бонусные чанки
    void recalculationChunks();

    /*Метод устанавливает общее значение всему прогрессбару, последовательно заполняя все чанки пока
     *не кончится переданное значение. Используется для первичной инициализации и сохранения значения
     *при перерасчёте векторов прогрессбара из переменной value, чтобы оно не сбрасывалось при любом
     *изменении.*/
    void setValue(int newValue);

    //Перерасчёт всех бонусов магической защиты
    void updateBonuses();

    //Общий вектор всех чанков
    QVector<Chunk*> chunks;
    //Вектор родных чанков, которые будут расположены в начале - перед бонусными
    QVector<Chunk*> nativeChunks;
    //Вектор бонусных чанков, который хранит все бонусы
    QVector<Chunk*> bonusChunks;
    //Вектор бонусных чанков, которые влезли в предел и будут добавлены в конец прогрессбара
    QVector<Chunk*> finalBonusChunks;

    //Вычисление текущего общего заполненного значения всех чанков прогрессбара
    void calculateValue();

    /*Очистка вектора родных чанков. Нужно быть осторожным в вызове этого метода, ведь он сам
     *не перерисовывает прогрессбар. После его вызова ОБЯЗАТЕЛЬНО должна быть переинициализация
     *вектора родных чанков, даже пустым вектором, если то нужно. Безопасен только вызов из
     *начала метода setChunks, потому что он сам и переинициализирует вектор родных чанков.*/
    void clearNativeChunks();

    //Вектор всех бонусов магической защиты
    QVector<MagicDefenseBonus*> bonuses;
};

#endif // MAGICDEFENSE_H

/************************************************************************************************************
 *Данный класс является прогрессбаром разделённым на ячейки. Он предназначен пока что только для
 *магической защиты. Общее значение складывается из векторов фрагментов прогрессбара (Сhunk).
 *Максимальное количество родных чанков 50, но бонусные чанки могут расширить предел до 60. Всё,
 *что не влезло в эти пределы усекается.
 *
 *Важно то, что частично заполненным может быть только один чанк, если такой чанк не первый, то
 *все чанки до него должны быть полностью заполненными, а все чанки после - полностью пустыми.
 *По этому, хоть вектор chunks и имеет сеттер, он предназначен только для первичной инициализации,
 *все же последующие вычисления производятся при помощи методов addValue, subtractValue, HealOneChunk,
 *spendLastChunk и т.д.
 *
 *addBonusChunk добавляет незаполненные ячейки в конец прогрессбара. Медод добавит незаполненную
 *ячейку даже если передать заполненную. Бонусные чанки добавляются всегда в конец, всегда уже
 *после родных чанков. При удалении бонусных чанков итератор делает обход с конца вектора.
 *
 *Надпись прогрессбара выводит информацию в формате
 *Текущий чанк / Всего чанков(текущее значение чанка / Максимальное значение чанка)
 ************************************************************************************************************/

#ifndef PROGRESSBAR_2_H
#define PROGRESSBAR_2_H

#include "chunk.h"

#include <QHBoxLayout>
#include <QWidget>

#include <CustomWidgets/LabelWithTooltip/labelwithtooltip.h>

namespace Ui {
class ProgressBar_2;
}


class ProgressBar_2 : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressBar_2(QWidget *parent = nullptr);
    ~ProgressBar_2();

    void setColor(const QColor &newColor);

    const QVector<Chunk*> &getChunks() const;
    //Метод задаёт родные чанки (nativeChunks)
    void setChunks(const QVector<Chunk*> &newChunks);
    /*Метод задаёт бонусные чанки (bonusChunks). Новые чанки будут иметь текущие значения 0,
     *так как все бонусы дают прибавку только к максимальному значению,а не к текущему.*/
    void setBonusChunks(const QVector<Chunk*> &newChunks);

    LabelWithTooltip* getLabelWithTooltip();

    /*Метод возвращает индекс текущего активного чанка. Текущим чанком
     *считается последний чанк, имеющий ненулевое значение.*/
    int getCurrentChunkIndex();
    /*Метод добавляет значение к текущему чанку. Если максимальное значение чанка не позволяет
     *переданному значению уместиться в нём полностью, то остаток переходит на следующий чанк,
     *и так пока либо не кончится значение, либо не кончатся чанки.*/
    void addValue(int value);
    /*Метод вычитает значение из текущего чанка. Если значение чанка меньше переданного вычитаемого
     *значения, то текущий чанк обнуляется, а остаток вычитается из предыдущего чанка, и так пока либо
     *не кончится значение, либо не кончатся чанки.*/
    void subtractValue(int value);

    /*Добавление чанка в вектор бонусных чанков. В метод передаётся указатель на новый чанк, затем его
     *текущее значение обнуляется и указатель добавляется в конец вектора бонусных чанков. Новый чанк
     *будет иметь текущее значение 0, так как все бонусы дают прибавку только к максимальному значению,
     *а не к текущему.*/
    void addBonusChunk(Chunk* chunk);
    /*Перегрузка идентичная по функционалу вышестоящему методу, только
     *эта функция добавляет переданный вектор к вектору бонусных чанков*/
    void addBonusChunk(QVector<Chunk*> chunks);

    /*Удаление бонусного чанка. Метод имеет 4 перегрузки:
     *
     *В первой передаётся указатель на чанк, затем итератор ищет первый с
     *конца чанк из вектора бонусных чанков, максимальное значение которого
     *совпадёт с переданным чанком и удаляет указатель на него.
     *
     *Во второй просто передаётся число, являющееся максимальным значением
     *вектора, которое итератор будет искать среди максимальных значений
     *вектора бонусных чанков и удалять соответствующий указатель. Обход
     *так же идёт с конца.
     *
     *Ещё 2 перегрузки делают тоже самое что и вышеописанные, только ищуются
     *все значения из переданных векторов.
     *
     *Поиск идёт именно по максимальному значению так как текущее значение
     *чанков не влияет на принятие решения по удалению бонуса. Он удалится
     *хоть пустым, хоть полным.
     *
     *Методы возвращают true если найденны все переданные значения, и false
     *если это не так. Даже при проваленном поиске метод удаляет всё, что он
     *всё-таки нашёл. Если любая из этих перегрузок вернула false, то следует
     *сразу же запросить полный пересчёт всех векторов чанка в вызывающем классе
     *и провести их полную переинициализацию в этом.
     *
     *Обход итераторов идёт с конца чтобы при ситуации, когда имеются два или
     *более одинаковых бонуса, удалить тот, который более вероятно будет
     *повреждённым (значение не будет равно максимальному значению). Это
     *просто вопрос баланса тут не важно какой именно бонус спровоцировал создание
     *чанка, всё-равно удалится именно последний подходящий по значениям.*/
    bool removeBonusChunk(Chunk* chunk);
    bool removeBonusChunk(int maxValue);
    bool removeBonusChunk(QVector<Chunk*> chunks);
    bool removeBonusChunk(QVector<int> maxValues);

    /*Обнуляет текущий активный чанк. Если обнуление было произведено, то водвращает true, если
     *нет то это означает, что весь прогрессбар уже полностью обнулён и возвращается false*/
    bool spendLastChunk();

    //Приравнивает значение текущего активного чанка к его максимальному значению
    void HealOneChunk();
    //Приравнивает значение всех чанков к их максимальному значению
    void HealAllChunk();

private:
    //Цвет, в который будет окрашенна заполненная область прогрессбара
    QColor color = QColor(0 , 0, 0, 0);
    /*Общий вектор чанков. Его первая часть состоит из родных чанков
     *(nativeChunks), а вторая - из бонусных (bonusChunks)*/
    QVector<Chunk*> chunks;
    //Вектор родных чанков, которые будут расположены в начале - перед бонусными
    QVector<Chunk*> nativeChunks;
    //Вектор бонусных чанков, который хранит все бонусы
    QVector<Chunk*> bonusChunks;
    //Вектор бонусных чанков, которые влезли в предел и будут добавлены в конец прогрессбара
    QVector<Chunk*> finalBonusChunks;

    /*Размер в пикселях, которому эквивалентен сдвиг
     *заполняемой области при изменении значения на 1*/
    double stepSize = 0;

    //Перерасчёт общего вектора всех чанков, который включает в себя и родные и бонусные чанки
    void recalculationChunks();

    //Пересчёт размера заполненной области и позиций разделителей
    void recalculationChunkWidth();
    //Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
    void redrawChunk();

    /*Переопределённая виртуальная функция класса QWidget. Во время этого эвента
     *происходит подгонка всех обёрток(wrapper) под размер виджета.*/
    void resizeEvent(QResizeEvent* event) override;

    Ui::ProgressBar_2 *ui;
};

#endif // PROGRESSBAR_2_H

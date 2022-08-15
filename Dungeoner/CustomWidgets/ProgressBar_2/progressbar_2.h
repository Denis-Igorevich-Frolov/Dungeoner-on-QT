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
    void setChunks(const QVector<Chunk*> &newChunks);

    LabelWithTooltip* getLabelWithTooltip();

    int getCurrentChunkIndex();
    void addValue(int value);
    void subtractValue(int value);

    void addChunk(Chunk* chank);
    void addChunk(int maxValue);

    void HealOneChunk();
    void HealAllChunk();

private:
    //Цвет, в который будет окрашенна заполненная область прогрессбара
    QColor color = QColor(0 , 0, 0, 0);
    QVector<Chunk*> chunks;

    /*Размер в пикселях, которому эквивалентен сдвиг
     *заполняемой области при изменении значения на 1*/
    double stepSize = 0;

    //Пересчёт размера заполненной области
    void recalculationChunkWidth();
    //Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
    void redrawChunk();

    /*Переопределённая виртуальная функция класса QWidget. Во время этого эвента
     *происходит подгонка всех обёрток(wrapper) под размер виджета.*/
    void resizeEvent(QResizeEvent* event) override;

    Ui::ProgressBar_2 *ui;
};

#endif // PROGRESSBAR_2_H

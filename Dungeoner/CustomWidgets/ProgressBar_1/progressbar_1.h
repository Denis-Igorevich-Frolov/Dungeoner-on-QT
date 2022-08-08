/************************************************************************************************
 *Да, это переизобретённый прогрессбар. Сделанно это было во-первых для визуального вида, а
 *во-вторых потому что я не нашёл очевидного способа задать бэкграунд заполненной области
 *стандартного прогрессбара при помощи QPixmap. Важно было задать бэкграунд именно при помощи
 *pixmap так как текстура заполненной области должна иметь функцию окраски в необходимый цвет,
 *когда как сама изначальная текстура серая. Окраска происходит при помощи метода fillRect у
 *QPainter, которому очевидно нужен QPixmap. Также реализован механизм вызова всплывающей
 *подсказки. В остальном же это обычный прогрессбар с отличием в том, что его надпись выводит
 *информацию в формате "value/maxValue"
 ************************************************************************************************/

#ifndef PROGRESSBAR_1_H
#define PROGRESSBAR_1_H

#include <QWidget>

namespace Ui {
class ProgressBar_1;
}

class ProgressBar_1 : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressBar_1(QWidget *parent = nullptr);
    ~ProgressBar_1();

    int getMinValue() const;
    void setMinValue(int newMinValue);

    int getMaxValue() const;
    void setMaxValue(int newMaxValue);

    int getValue() const;
    void setValue(int newValue);

    void setColor(const QColor &newColor);

private:
    //Цвет, в который будет окрашенна заполненная область прогрессбара
    QColor color = QColor(0 , 0, 0, 0);
    int minValue = 0;
    int maxValue = 0;
    int value = 0;
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

    Ui::ProgressBar_1 *ui;
};

#endif // PROGRESSBAR_1_H

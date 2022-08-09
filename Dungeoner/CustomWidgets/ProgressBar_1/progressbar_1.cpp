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

#include "progressbar_1.h"
#include "ui_progressbar_1.h"
#include "stylemaster.h"

#include <QPainter>

ProgressBar_1::ProgressBar_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBar_1)
{
    ui->setupUi(this);

    //Установка стилей для элементов виджета
    ui->BordersWrapper->setStyleSheet(StyleMaster::BordersStyle());
    ui->TipsWrapper->setStyleSheet(StyleMaster::TipsStyle());
    ui->ShadowWrapper->setStyleSheet(StyleMaster::ShadowStyle());
    //Задаётся стиль текста лейбла с подсказкой как "ЧИСЛА"
    ui->labelWithTooltip->setFontType(LabelWithTooltip::NUMBERS);
}

ProgressBar_1::~ProgressBar_1()
{
    delete ui;
}

int ProgressBar_1::getMinValue() const
{
    return minValue;
}

void ProgressBar_1::setMinValue(int newMinValue)
{
    //Минимальное значение не может быть больше максимального
    if(newMinValue>maxValue)
        minValue = maxValue;
    else
        minValue = newMinValue;

    /*Если после изменения значение оказывается меньше
     *минимального, то оно усекается до минимального*/
    if(value < minValue)
        setValue(minValue);

    //После изменения диапазона нужно перерисовать тело прогрессбара
    recalculationChunkWidth();

    ui->labelWithTooltip->setText(QString::number(value)+"/"+QString::number(maxValue));
}

int ProgressBar_1::getMaxValue() const
{
    return maxValue;
}

void ProgressBar_1::setMaxValue(int newMaxValue)
{
    //Максимальное значение не может быть меньше минимального
    if(newMaxValue<minValue)
        maxValue = minValue;
    else
        maxValue = newMaxValue;

    /*Если после изменения значение оказывается больше
     *максимального, то оно усекается до максимального*/
    if(value > maxValue)
        setValue(maxValue);

    //После изменения диапазона нужно перерисовать тело прогрессбара
    recalculationChunkWidth();

    ui->labelWithTooltip->setText(QString::number(value)+"/"+QString::number(maxValue));
}

int ProgressBar_1::getValue() const
{
    return value;
}

void ProgressBar_1::setValue(int newValue)
{
    //Значение находится в диапазоне от минимального до максимального
    if(newValue>maxValue)
        value = maxValue;
    else if(newValue<minValue)
        value = minValue;
    else
        value = newValue;

    //После изменения значения нужно перерисовать тело прогрессбара
    recalculationChunkWidth();

    ui->labelWithTooltip->setText(QString::number(value)+"/"+QString::number(maxValue));
}

void ProgressBar_1::setColor(const QColor &newColor)
{
    color = newColor;
}

//Пересчёт размера заполненной области
void ProgressBar_1::recalculationChunkWidth()
{
    //Вычисляется общее количество значений
    int totalValues = maxValue - minValue;
    //Если не проверить, то может получиться деление на 0
    if(totalValues!=0)
        /*86 - это суммарные горизонтальные отступы тела прогрессбара от краёв виджета.
         *Деля размер тела прогрессбара на общее количество значений узнаём размер
         *изменения заполненной области при изменении значения на 1.*/
        stepSize = (this->width()-86.0)/totalValues;
    else
        stepSize = 0.0;

    ui->ProgressBarChunk->setFixedWidth(value*stepSize);
}

//Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
void ProgressBar_1::redrawChunk()
{
    QImage new_image(":/Text-Block-1/Textures PNG/ProgressBarBody-1.png");
    QPixmap pixmap(this->width(), ui->ProgressBarChunk->height());
    QPainter painter(&pixmap);
    //Тайлинг текстуры
    int drawedWidth = 0;
    int drawedHeight = 0;
    while (true) {
        drawedWidth = 0;
        while (true) {
            painter.drawImage(drawedWidth, drawedHeight, new_image);
            drawedWidth += new_image.width();
            if (drawedWidth >= pixmap.width()) {
                break;
            }
        }
        drawedHeight += new_image.height();
        if (drawedHeight >= pixmap.height()) {
            break;
        }
    }
    //Стиль наложение цвета - умножение, чтобы окрашивать текстуру
    painter.setCompositionMode(QPainter::CompositionMode_Multiply);
    //Наложение цвета
    painter.fillRect(QRect(0, 0, this->width(), this->height()), color);
    painter.end();

    ui->ProgressBarChunk->setPixmap(pixmap);
}

/*Переопределённая виртуальная функция класса QWidget. Во время этого эвента
 *происходит подгонка всех обёрток(wrapper) под размер виджета.*/
void ProgressBar_1::resizeEvent(QResizeEvent *event)
{
    ui->ChunkWrapper->setFixedWidth(this->width());
    ui->TipsWrapper->setFixedWidth(this->width());
    ui->BordersWrapper->setFixedWidth(this->width());
    ui->ShadowWrapper->setFixedWidth(this->width());
    ui->LabelWithTooltipWrapper->setFixedWidth(this->width());

    //После изменения размера нужно перерисовать тело прогрессбара
    recalculationChunkWidth();
    redrawChunk();
}

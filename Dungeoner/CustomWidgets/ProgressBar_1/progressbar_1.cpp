#include "progressbar_1.h"
#include "ui_progressbar_1.h"
#include "stylemaster.h"

#include <QPainter>

ProgressBar_1::ProgressBar_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBar_1)
{
    ui->setupUi(this);

    ui->BordersWrapper->setStyleSheet(StyleMaster::BordersStyle());
    ui->TipsWrapper->setStyleSheet(StyleMaster::TipsStyle());
    ui->ShadowWrapper->setStyleSheet(StyleMaster::ShadowStyle());
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
    if(newMinValue>maxValue)
        minValue = maxValue;
    else
        minValue = newMinValue;

    recalculationChunkWidth();
}

int ProgressBar_1::getMaxValue() const
{
    return maxValue;
}

void ProgressBar_1::setMaxValue(int newMaxValue)
{
    if(newMaxValue<minValue)
        maxValue = minValue;
    else
        maxValue = newMaxValue;
}

int ProgressBar_1::getValue() const
{
    return value;
}

void ProgressBar_1::setValue(int newValue)
{
    if(newValue>maxValue)
        value = maxValue;
    else if(newValue<minValue)
        value = minValue;
    else
        value = newValue;
}

void ProgressBar_1::setColor(const QColor &newColor)
{
    color = newColor;
}

void ProgressBar_1::recalculationChunkWidth()
{
    int totalValues = maxValue - minValue;
    if(totalValues!=0)
        stepSize = (this->width()-86.0)/totalValues;
    else
        stepSize = 0.0;

    ui->ProgressBarChunk->setFixedWidth(value*stepSize);
}

void ProgressBar_1::redrawChunk()
{
    QImage new_image(":/Text-Block-1/Textures PNG/ProgressBarBody-1.png");
    QPixmap pixmap(ui->TipsWrapper->width(), ui->ProgressBarChunk->height());
    QPainter painter(&pixmap);
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
    painter.setCompositionMode(QPainter::CompositionMode_Multiply);
    painter.fillRect(QRect(0, 0, this->width(), this->height()), color);
    painter.end();

    ui->ProgressBarChunk->setPixmap(pixmap);
}

void ProgressBar_1::resizeEvent(QResizeEvent *event)
{
    ui->ChunkWrapper->setFixedWidth(this->width());
    ui->TipsWrapper->setFixedWidth(this->width());
    ui->BordersWrapper->setFixedWidth(this->width());
    ui->ShadowWrapper->setFixedWidth(this->width());

    recalculationChunkWidth();
    redrawChunk();
}

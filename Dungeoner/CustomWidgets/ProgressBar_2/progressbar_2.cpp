#include "progressbar_2.h"
#include "qpainter.h"
#include "ui_progressbar_2.h"
#include "PB2_stylemaster.h"

ProgressBar_2::ProgressBar_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBar_2)
{
    ui->setupUi(this);

    //Установка стилей для элементов виджета
    ui->BordersWrapper->setStyleSheet(PB2_StyleMaster::BordersStyle());
    ui->TipsWrapper->setStyleSheet(PB2_StyleMaster::TipsStyle());
    ui->ShadowWrapper->setStyleSheet(PB2_StyleMaster::ShadowStyle());
    //Задаётся стиль текста лейбла с подсказкой как "ЧИСЛА"
    ui->labelWithTooltip->setFontType(LabelWithTooltip::NUMBERS);
    ui->labelWithTooltip->setOutlineThickness(2);

//    layout = new ;
}

ProgressBar_2::~ProgressBar_2()
{
    for(Chunk* chunk:chunks)
        delete chunk;

    qDeleteAll(ui->SeparatorWrapper->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));

    delete ui;
}

void ProgressBar_2::setColor(const QColor &newColor)
{
    color = newColor;
}

const QVector<Chunk*> &ProgressBar_2::getChunks() const
{
    return chunks;
}

void ProgressBar_2::setChunks(const QVector<Chunk*> &newChunks)
{
    if(newChunks.size()>50){
        QVector<Chunk*> newVChunks;
        for(int i = 0; i<50; i++)
            newVChunks.append(newChunks.at(i));
        chunks = newVChunks;
    }else
        chunks = newChunks;

    recalculationChunkWidth();
}

LabelWithTooltip* ProgressBar_2::getLabelWithTooltip()
{
    return ui->labelWithTooltip;
}

int ProgressBar_2::getCurrentChunkIndex()
{
    int currentChunk = 0;

    for(int i = 0; i<chunks.size(); i++)
        if(chunks.at(i)->getValue()!=0)
           currentChunk++;

    if(currentChunk==0)
        currentChunk = 1;

    return currentChunk;
}

void ProgressBar_2::addValue(int value)
{
    if(value<0)
        value = 0;

    int currentChunk = getCurrentChunkIndex();
    Chunk* chunk;

    while(value>0){
        if(currentChunk > chunks.size())
            break;

        chunk = chunks.at(currentChunk-1);
        int difference = chunk->getMaxValue() - chunk->getValue();

        if(difference==0)
            break;

        if(value>difference){
            chunk->setValue(chunk->getMaxValue());
            value-=difference;
        }else{
            chunk->setValue(chunk->getValue()+value);
            value = 0;
        }
        currentChunk++;
    }

    recalculationChunkWidth();
}

void ProgressBar_2::subtractValue(int value)
{
    if(value<0)
        value = 0;

    int currentChunk = getCurrentChunkIndex();
    Chunk* chunk;

    while(value>0){
        if(currentChunk == 0)
            break;

        chunk = chunks.at(currentChunk-1);

        if(chunk->getValue()==0)
            break;

        if(value>chunk->getValue()){
            chunk->setValue(0);
            value-=chunk->getValue();
        }else{
            chunk->setValue(chunk->getValue()-value);
            value = 0;
        }
        currentChunk--;
    }

    recalculationChunkWidth();
}

void ProgressBar_2::addChunk(Chunk* chunk)
{
    if(chunks.size()<50){
        chunk->setValue(0);
        chunks.append(chunk);
        recalculationChunkWidth();
    }

}

void ProgressBar_2::addChunk(int maxValue)
{
    if(chunks.size()<50){
        Chunk* chunk = new Chunk(maxValue, 0);
        chunks.append(chunk);
        recalculationChunkWidth();
    }
}

void ProgressBar_2::HealOneChunk()
{
    for(Chunk* chunk : chunks)
        if (chunk->getValue()!=chunk->getMaxValue()){
            chunk->setValue(chunk->getMaxValue());
            break;
        }
    recalculationChunkWidth();
}

void ProgressBar_2::HealAllChunk()
{
    for(Chunk* chunk : chunks)
        chunk->setValue(chunk->getMaxValue());
    recalculationChunkWidth();
}

//Пересчёт размера заполненной области
void ProgressBar_2::recalculationChunkWidth()
{
    //Вычисляется общее количество значений
    int totalValues = 0;
    for(Chunk* chunk : chunks)
        totalValues+=chunk->getMaxValue();
    //Если не проверить, то может получиться деление на 0
    if(totalValues!=0)
        /*86 - это суммарные горизонтальные отступы тела прогрессбара от краёв виджета.
         *Деля размер тела прогрессбара на общее количество значений узнаём размер
         *изменения заполненной области при изменении значения на 1.*/
        stepSize = (this->width()-86.0)/totalValues;
    else
        stepSize = 0.0;

    qDeleteAll(ui->SeparatorWrapper->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));

    int value = 0;
    int offset = 0;
    for(int i = 0; i<chunks.size(); i++){
        value+=chunks.at(i)->getValue();
        offset+=chunks.at(i)->getMaxValue();
        if(i<chunks.size()-1){
            QLabel* separator = new QLabel(ui->SeparatorWrapper);
            separator->setGeometry(43+ceil(offset*stepSize)-5, 0, 9, 43);
            separator->setStyleSheet(PB2_StyleMaster::SeparatorStyle());
        }
    }

    ui->ProgressBarChunk->setFixedWidth(ceil(value*stepSize));

    int currentChunk = getCurrentChunkIndex();

    if(currentChunk!=0)
        ui->labelWithTooltip->setText(QString::number(currentChunk)+" / "+QString::number(chunks.size())+
                                      " ("+QString::number(chunks.at(currentChunk-1)->getValue())+" / "+
                                      QString::number(chunks.at(currentChunk-1)->getMaxValue())+")");
    else
        ui->labelWithTooltip->setText(QString::number(currentChunk)+" / "+QString::number(chunks.size())+
                                      " (0 / "+QString::number(chunks.first()->getMaxValue())+")");
}

//Перерисовка заполненной области при помощи тайлящейся окрашенной текстуры
void ProgressBar_2::redrawChunk()
{
    QImage new_image(":/Text-Block-1/Textures PNG/ProgressBarBody-1.jpg");
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
void ProgressBar_2::resizeEvent(QResizeEvent *event)
{
    ui->ChunkWrapper->setFixedWidth(this->width());
    ui->TipsWrapper->setFixedWidth(this->width());
    ui->BordersWrapper->setFixedWidth(this->width());
    ui->ShadowWrapper->setFixedWidth(this->width());
    ui->LabelWithTooltipWrapper->setFixedWidth(this->width());
    ui->SeparatorWrapper->setFixedWidth(this->width());

    //После изменения размера нужно перерисовать тело прогрессбара
    recalculationChunkWidth();
    redrawChunk();
}

#include "labelwithborder.h"
#include "ui_labelwithborder.h"
#include "stylemaster.h"

#include <QPainter>
#include <QPainterPath>

LabelWithBorder::LabelWithBorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabelWithBorder)
{
    ui->setupUi(this);

    //Изначальная инициализация типа шрифта значением по умолчанию, то есть типом "ТЕКСТ"
    setFontStyle(QColor("#bdc440"), QColor("#0b0a05"), 3, fontType);
    this->setMinimumHeight(this->property("fontSize").toInt()+3);
}

LabelWithBorder::~LabelWithBorder()
{
    delete ui;
}

//Устанавливает текст для LableText
void LabelWithBorder::setText(QString text)
{
    ui->LabelText->setText(text);
}

void LabelWithBorder::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPainterPath path;
    painter.translate(this->rect().center());
    if(horizontalAlignment == HorizontalAlignment::CENTER)
        path.addText(-ui->LabelText->width()/2, ui->LabelText->height()/2-3/*-5*/, ui->LabelText->font(), ui->LabelText->text());
    else if(horizontalAlignment == HorizontalAlignment::LEFT)
        path.addText(-this->width()/2, ui->LabelText->height()/2-3, ui->LabelText->font(), ui->LabelText->text());
    else if(horizontalAlignment == HorizontalAlignment::RIGHT)
        path.addText(this->width()/2-ui->LabelText->width(), ui->LabelText->height()/2-3, ui->LabelText->font(), ui->LabelText->text());
    painter.setRenderHints(QPainter::Antialiasing);
    painter.strokePath(path, QPen(borderColor, borderThickness));
    painter.fillPath(path, QBrush(textColor));
    painter.end();
    ui->LabelText->setVisible(false);
}

const QString &LabelWithBorder::getText() const
{
    return text;
}

LabelWithBorder::HorizontalAlignment LabelWithBorder::getHorizontalAlignment() const
{
    return horizontalAlignment;
}

void LabelWithBorder::setHorizontalAlignment(HorizontalAlignment newHorizontalAlignment)
{
    horizontalAlignment = newHorizontalAlignment;
    repaint();
}

LabelWithBorder::FontType LabelWithBorder::getFontType() const
{
    return fontType;
}

void LabelWithBorder::setFontStyle(QColor textColor, QColor borderColor, int borderThickness, FontType fontType)
{
    this->borderThickness = borderThickness;
    this->textColor = textColor;
    this->borderColor = borderColor;
    this->fontType = fontType;

    /*Метод устанавливает стиль для лейбла LabelText, при этом размер
     *шрифта извлекается из динамического свойства виджета fontSize,
     *а шрифт задаётся строкой с его именем, который выбирается исходя
     *из энума типа текста.
     *
     *Важно задать стиль текста до переопределения размера шрифта, так
     *как вызов этой функции снова задаст значение размера по умолчанию.*/
    if(fontType == FontType::TEXT)
        ui->LabelText->setStyleSheet(StyleMaster::TextFontStyle(this->property("fontSize").toInt(), "Algerian"));
    else if(fontType == FontType::NUMBERS){
        ui->LabelText->setStyleSheet(StyleMaster::TextFontStyle(this->property("fontSize").toInt(), "Old English Text MT"));
        /*Так как теперь лейбл имеет стиль "ЧИСЛА" устанавливаем изначальный
         *текст "0". Этого не требовалось для текста, потому что ещё в форме
         *там задано значение по умолчанию "NON"*/
        ui->LabelText->setText("0");
    }
}

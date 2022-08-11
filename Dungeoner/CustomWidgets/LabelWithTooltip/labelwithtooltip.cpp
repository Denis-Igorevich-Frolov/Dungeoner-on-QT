/******************************************************************************
 *Данный виджет - это поле с текстом (размер текст задаётся в динамическом
 *свойстве fontSize) с функционалом для вывода подсказки.
 *
 *Суть вынесения этого одного лейбла в отдельный класс в том, чтобы подсказка
 *выводилась только у этой части, а у всего родительского виджета
 ******************************************************************************/

#include "labelwithtooltip.h"
#include "qevent.h"
#include "ui_labelwithtooltip.h"
#include "LWT_stylemaster.h"

LabelWithTooltip::LabelWithTooltip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabelWithTooltip)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    //Связывание сигналов из TooltipDisplayEvents на такие же из этого класса
    connect(&tooltipDisplayEvents,SIGNAL(ShowTooltip()),this, SIGNAL(ShowTooltip()));
    connect(&tooltipDisplayEvents,SIGNAL(RemoveTooltip()),this, SIGNAL(RemoveTooltip()));

    //Изначальная инициализация типа шрифта значением по умолчанию, то есть типом "ТЕКСТ"
    setFontType(fontType);

    //Установка обводки текста
    border = new OutlineEffect();
    border->setOutlineThickness(1);
    ui->LabelText->setGraphicsEffect(border);
    ui->LabelText->setMargin(1);
}

LabelWithTooltip::~LabelWithTooltip()
{
    delete border;
    delete ui;
}

//Устанавливает текст для ButtonText
void LabelWithTooltip::setText(QString text)
{
    ui->LabelText->setText(text);
}

/*Переопределения виртуальных функций QWidget для вызова сигнала вывода
 *или удаления подсказки. Вся логика происходит в классе TooltipDisplayEvents*/
void LabelWithTooltip::mousePressEvent(QMouseEvent *event)
{
    tooltipDisplayEvents.mousePressEvent(event);
}
void LabelWithTooltip::mouseReleaseEvent(QMouseEvent *event)
{
    tooltipDisplayEvents.mouseReleaseEvent(event);
}
void LabelWithTooltip::enterEvent(QEnterEvent *event)
{
    tooltipDisplayEvents.enterEvent(event);
}
void LabelWithTooltip::leaveEvent(QEvent *event)
{
    tooltipDisplayEvents.leaveEvent(event);
}
void LabelWithTooltip::mouseMoveEvent(QMouseEvent *event)
{
    tooltipDisplayEvents.mouseMoveEvent(event, this->width(), this->height());
}

LabelWithTooltip::FontType LabelWithTooltip::getFontType() const
{
    return fontType;
}
void LabelWithTooltip::setFontType(FontType newFontType)
{
    fontType = newFontType;

    /*Метод устанавливает стиль для лейбла LabelText, при этом размер
     *шрифта извлекается из динамического свойства виджета fontSize,
     *а шрифт задаётся строкой с его именем, который выбирается исходя
     *из энума типа текста.
     *
     *Важно задать стиль текста до переопределения размера шрифта, так
     *как вызов этой функции снова задаст значение размера по умолчанию.*/
    if(fontType == FontType::TEXT)
        ui->LabelText->setStyleSheet(LWT_StyleMaster::TextFontStyle(this->property("fontSize").toInt(), "Algerian"));
    else if(fontType == FontType::NUMBERS){
        ui->LabelText->setStyleSheet(LWT_StyleMaster::TextFontStyle(this->property("fontSize").toInt(), "Old English Text MT"));
        /*Так как теперь лейбл имеет стиль "ЧИСЛА" устанавливаем изначальный
         *текст "0". Этого не требовалось для текста, потому что ещё в форме
         *там задано значение по умолчанию "NON"*/
        ui->LabelText->setText("0");
    }
}

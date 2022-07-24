/*Данный виджет - это поле с текстом (размер текст задаётся в динамическом
 *свойстве fontSize) с функционалом для вывода подсказки.
 *
 *Суть вынесения этого одного лейбла в отдельный класс в том, чтобы подсказка
 *выводилась только у этой части, а у всего родительского виджета*/

#include "labelwithtooltip.h"
#include "qevent.h"
#include "ui_labelwithtooltip.h"
#include "stylemaster.h"

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

    /*Метод устанавливает стиль для кнопки ButtonText, при этом размер
     *шрифта извлекается из динамического свойства виджета fontSize.*/
    ui->ButtonText->setStyleSheet(StyleMaster::TextFontStyle(this->property("fontSize").toInt()));

    //Установка тени текста
    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(1, 1);
    shadow->setColor(QColor(32, 29, 16));
    ui->ButtonText->setGraphicsEffect(shadow);
}

LabelWithTooltip::~LabelWithTooltip()
{
    delete shadow;
    delete ui;
}

//Устанавливает текст для ButtonText
void LabelWithTooltip::setText(QString text)
{
    ui->ButtonText->setText(text);
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

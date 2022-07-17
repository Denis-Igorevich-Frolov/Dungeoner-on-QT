/*
 *Данный виджет - это поле с текстом (размер текст задаётся в динамическом
 *свойстве fontSize) с функционалом для вывода подсказки. Подсказка выводится
 *при нажатии правой кнопкой мыши. При наводке курсора на виджет, его значёк
 *меняется на курсор со знаком вопроса.
 */

#include "labelwithtooltip.h"
#include "qevent.h"
#include "ui_labelwithtooltip.h"
#include "stylemaster.h"

#include <QGraphicsDropShadowEffect>

LabelWithTooltip::LabelWithTooltip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabelWithTooltip)
{
    ui->setupUi(this);

    /*Метод устанавливает стиль для кнопки ButtonText, при этом размер
     *шрифта извлекается из динамического свойства виджета fontSize.*/
    ui->ButtonText->setStyleSheet(StyleMaster::TextFontStyle(this->property("fontSize").toInt()));

    //Добавление тени
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(1, 1);
    effect->setColor(QColor(32, 29, 16));
    ui->ButtonText->setGraphicsEffect(effect);
}

LabelWithTooltip::~LabelWithTooltip()
{
    delete ui;
}

//Устанавливает текст для ButtonText
void LabelWithTooltip::setText(QString text)
{
    ui->ButtonText->setText(text);
}

/*Функция ивента нажатия клафиши мыши. Обрабатывает нажатие только
 *правой кнопки для вывода подсказки.*/
void LabelWithTooltip::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
        case Qt::LeftButton:
        {
            break;
        }
        case Qt::RightButton:
        {
            qDebug() << "Right Mouse button pressed";
            break;
        }
        case Qt::MiddleButton:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

/*Функция ивента отжатия клафиши мыши. Обрабатывает отжатие только
 * правой кнопки для сокрытия подсказки.
 */
void LabelWithTooltip::mouseReleaseEvent(QMouseEvent *event)
{
    switch (event->button()) {
        case Qt::LeftButton:
        {
            break;
        }
        case Qt::RightButton:
        {
            qDebug() << "Right Mouse button unpressed";
            break;
        }
        case Qt::MiddleButton:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

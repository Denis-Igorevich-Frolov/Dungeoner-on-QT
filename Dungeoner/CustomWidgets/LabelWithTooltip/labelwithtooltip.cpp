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

LabelWithTooltip::LabelWithTooltip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabelWithTooltip)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    /*Метод устанавливает стиль для кнопки ButtonText, при этом размер
     *шрифта извлекается из динамического свойства виджета fontSize.*/
    ui->ButtonText->setStyleSheet(StyleMaster::TextFontStyle(this->property("fontSize").toInt()));

    //Добавление тени
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

void LabelWithTooltip::mousePressEvent(QMouseEvent* event)
{
    //Считываем нажатие только правой кнопки мыши
    switch (event->buttons()){
    case Qt::RightButton:
    {
        rightMousePressed = true;

        break;
    }
    }

    CheckingDisplayOfTooltip();
}

void LabelWithTooltip::mouseReleaseEvent(QMouseEvent *event)
{
    rightMousePressed = false;

    CheckingDisplayOfTooltip();
}

void LabelWithTooltip::enterEvent(QEnterEvent *event)
{
    isHovered = true;

    /*Нет смысла проверять CheckingDisplayOfTooltip здесь, ведь
     *эвенты наведения не вызовутся при зажатой кнопки мыши*/
}

void LabelWithTooltip::leaveEvent(QEvent *event)
{
    isHovered = false;

    CheckingDisplayOfTooltip();
}

void LabelWithTooltip::mouseMoveEvent(QMouseEvent *event)
{
    /*Так как в Qt давольно посредственный обработчик эвентов, связанных с мышью,
     *эвент leaveEvent, как и любой ивент связанный с получением/потерей наведения,
     *никогда не будетвызван, если зажата хоть одна из кнопок мыши. По этому я
     *обрабатываю выход за пределы виджета вручную.*/

    if((event->position().x() < this->width()) && (event->position().y() < this->height()) &&
       (event->position().x() > 0) && (event->position().y() > 0))
    {
        isHovered = true;
    }else{
        isHovered = false;
    }

    CheckingDisplayOfTooltip();
}

/*Это проверка, вызываемая при почти каждом выше переопределённом эвенте.
 *Сиграл ShowTooltip будет вызван только при условии, что курсор наведён
 *на виджет и правая кнопка мыши зажата, иначе будет попытка вызова RemoveTooltip*/
void LabelWithTooltip::CheckingDisplayOfTooltip()
{
    if(isHovered&&rightMousePressed){
        emit ShowTooltip();
        TooltipHasBeenCalled = true;
    }else{
        /*TooltipHasBeenCalled проверяется для того, чтобы RemoveTooltip был вызван только
         *один раз, только при условии, что ShowTooltip ранее уже был вызван, ведь очевидно,
         *что чтобы удалить подсказку, она должна была быть вызвана*/
        if(TooltipHasBeenCalled){
            emit RemoveTooltip();
            TooltipHasBeenCalled = false;
        }
    }
}

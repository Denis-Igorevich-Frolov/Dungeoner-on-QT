#include "tooltipdisplayevents.h"
#include "qevent.h"

TooltipDisplayEvents::TooltipDisplayEvents(QWidget *parent) :
    QWidget(parent)
{

}

void TooltipDisplayEvents::mousePressEvent(QMouseEvent* event)
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

void TooltipDisplayEvents::mouseReleaseEvent(QMouseEvent *event)
{
    rightMousePressed = false;

    CheckingDisplayOfTooltip();
}

void TooltipDisplayEvents::enterEvent(QEnterEvent *event)
{
    isHovered = true;

    /*Нет смысла проверять CheckingDisplayOfTooltip здесь, ведь
     *эвенты наведения не вызовутся при зажатой кнопки мыши*/
}

void TooltipDisplayEvents::leaveEvent(QEvent *event)
{
    isHovered = false;

    CheckingDisplayOfTooltip();
}

void TooltipDisplayEvents::mouseMoveEvent(QMouseEvent *event, int width, int height)
{
    /*Так как в Qt давольно посредственный обработчик эвентов, связанных с мышью,
     *эвент leaveEvent, как и любой ивент связанный с получением/потерей наведения,
     *никогда не будетвызван, если зажата хоть одна из кнопок мыши. По этому я
     *обрабатываю выход за пределы виджета вручную.*/

    if((event->position().x() < width) && (event->position().y() < height) &&
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
void TooltipDisplayEvents::CheckingDisplayOfTooltip()
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

/*************************************************************************************************
 *Данный класс посылает сигналы для выведения и сокрытия подсказки. Подсказка выводится при
 *условии, что курсор наведён на виджет и зажата правая кнопка мыши.
 *
 *Так как вызов эвентов мыши происходит непосредственно в классе, который хочет реализовывать
 *функционал отображения подсказки, там должны быть явным образом переопределены виртуальные
 *функции класса QWidget: mousePressEvent, mouseReleaseEvent, enterEvent, leaveEvent и
 *mouseMoveEvent, которые, в свою очередь, должны вызывать соответствующие методы этого класса.
 *Сигналы вызова и сокрытия подсказки у имплементирующего класса, которые будут связанны с
 *сигналами этого класса лучше также назвать ShowTooltip и RemoveTooltip.
 *
 *Имплементирующий класс обязательно должен иметь атрибут setAttribute(Qt::WA_Hover).
 *
 *Крайне важно помнить, что у любого виджета, который хочет показывать подсказку, все
 *дочерние элементы интерфейса обязательно должны быть disabled. Сделать это можно в
 *редакторе форм сняв у них галочку enabled. Иначе некоторые эвенты будут "застревать"
 *в дочерних элементах виджета и не передаться родительскому
 *************************************************************************************************/

#include "tooltipdisplayevents.h"
#include "qevent.h"

#include <Global/global.h>

//Наследование от QWidget для взаимодействия с его ивентами
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

//Из имплементирующего класса следует передать width и height как: this->width и this->height соответственно.
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

/*Перегрузка функции движения мыши специально для вторичных навыков, которые
 *помещены в вертикальный скроллбар. Учитывает усечение геометрии элемента
 *при прокрутке скроллбара.*/
void TooltipDisplayEvents::mouseMoveEvent(QMouseEvent *event, int width, int height, int YPosition, int ScrollAreaHeight, int ScrollAreaOffset)
{
    if((event->position().x() < width) && (event->position().y() < height) &&
       (event->position().x() > 0) && (event->position().y() > 0))
    {
        /*Если вертикальная позиция курсора меньше, чем разница сдвига родительского
         *скроллбара и вертикальной позиции самого виджета внутри него, то это значит,
         *что курсор вышел за пределы скроллбара, в который помещён виджет. Следовательно
         *isHovered становится false и функция завершается.*/
        if(event->position().y()<(ScrollAreaOffset-YPosition)){
            isHovered = false;

            CheckingDisplayOfTooltip();
            return;
        }

        /*Если вертикальная позиция курсора больше, чем разница суммы сдвига с высотой
         *родительского скроллбара и вертикальной позиции самого виджета внутри него,
         *то это значит, что курсор вышел за пределы скроллбара, в который помещён
         *виджет. Следовательно isHovered становится false и функция завершается.
         *3 дополнительных пикселя здесь для подстраховки, без них ивент вызывался
         *чуть-чуть позже необходимого, что могло выглядеть не очень кравиво.*/
        if(event->position().y()>(ScrollAreaHeight+ScrollAreaOffset-YPosition-3)){
            isHovered = false;

            CheckingDisplayOfTooltip();
            return;
        }

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
        /*Если зажаты какие-либо модификаторы нажатия, находим какие и проверяем поддерживает
         *ли эта подсказка дополнительные подсказки по модификатору нажатия*/
        if(!Global::pressedKeys.empty()){
            //Alt
            if(Global::pressedKeys.last() == 16777251 && AltModifierIsUsed){
                emit ShowTooltip(AltTooltipContent);
            }else
            //Ctrl
            if(Global::pressedKeys.last() == 16777249 && CtrlModifierIsUsed){
                emit ShowTooltip(CtrlTooltipContent);
            }else
            //Shift
            if(Global::pressedKeys.last() == 16777248 && ShiftModifierIsUsed){
                emit ShowTooltip(ShiftTooltipContent);
            }else
                //Если модификаторы нажаты, но подсказка не имеет дополнений, вызывается обычная подсказка
                emit ShowTooltip(TooltipContent);
        }else
            emit ShowTooltip(TooltipContent);

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

void TooltipDisplayEvents::setTooltipContent(QVector<QLabel *> &newTooltipContent)
{
    TooltipContent = newTooltipContent;
}

//Установка контента для подсказок вызываемых с зажатым модификатором

void TooltipDisplayEvents::setAltTooltipContent(QVector<QLabel *> &newAltTooltipContent)
{
    AltModifierIsUsed = true;
    AltTooltipContent = newAltTooltipContent;
}

void TooltipDisplayEvents::setCtrlTooltipContent(QVector<QLabel *> &newCtrlTooltipContent)
{
    CtrlModifierIsUsed = true;
    CtrlTooltipContent = newCtrlTooltipContent;
}

void TooltipDisplayEvents::setShiftTooltipContent(QVector<QLabel *> &newShiftTooltipContent)
{
    ShiftModifierIsUsed = true;
    ShiftTooltipContent = newShiftTooltipContent;
}

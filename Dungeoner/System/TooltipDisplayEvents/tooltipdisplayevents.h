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

#ifndef TOOLTIPDISPLAYEVENTS_H
#define TOOLTIPDISPLAYEVENTS_H

#include <QWidget>

class TooltipDisplayEvents : public QWidget
{
    Q_OBJECT
public:
    explicit TooltipDisplayEvents(QWidget *parent = nullptr);

    /*Функции, которые имплементирующий класс вызовет в соответствующих
     *перегруженных виртуальных функциях из QWidget.*/
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    /*Единственный метод, чья сигнатура не совпадает с виртуальной функцией
     *из QWidget. Из имплементирующего класса следует передать width и height
     *как: this->width и this->height соответственно.*/
    void mouseMoveEvent(QMouseEvent *event, int width, int height);
    /*Это проверка, вызываемая при почти каждом выше переопределённом эвенте.
     *Сиграл ShowTooltip будет вызван только при условии, что курсор наведён
     *на виджет и правая кнопка мыши зажата, иначе будет попытка вызова RemoveTooltip*/
    void CheckingDisplayOfTooltip();

signals:
    //Сигнал отображения подсказки будет сдвигать её, если она уже существует
    void ShowTooltip();
    /*Сигнал сокрытия подсказки будет вызываться только, если подсказка
     *была выведена, и не более 1 раза за вызов подсказки*/
    void RemoveTooltip();

private:
    bool rightMousePressed = false;
    bool isHovered = false;

    /*TooltipHasBeenCalled участвует в проверке того, что RemoveTooltip был вызван
     *только один раз, только при условии, что ShowTooltip ранее уже был вызван*/
    bool TooltipHasBeenCalled = false;
};

#endif // TOOLTIPDISPLAYEVENTS_H

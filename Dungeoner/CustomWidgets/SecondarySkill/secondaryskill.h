#ifndef SECONDARYSKILL_H
#define SECONDARYSKILL_H

/*Данный класс представляет собой панельку вторичного навыка. Вынесен
 *в отдельный класс просто для выведения подсказки и гарантии того,
 *что все QGraphicsDropShadowEffect точно будут удалены в деструкторе.*/

#include "System/TooltipDisplayEvents/tooltipdisplayevents.h"

#include <QGraphicsDropShadowEffect>
#include <QWidget>

namespace Ui {
class SecondarySkill;
}

class SecondarySkill : public QWidget
{
    Q_OBJECT

public:
    explicit SecondarySkill(QWidget *parent = nullptr);
    ~SecondarySkill();

    long getValue() const;
    /*Сеттер на переменную Value. Также устанавливает число в
     *лейбл Value и меняет его межстрочный интервал*/
    void setValue(long newValue);
    void setInscription(QString inscription);
    void setFontSize(int size);

signals:
    //сигнал отображения подсказки будет сдвигать её, если она уже существует
    void ShowTooltip();
    void RemoveTooltip();

private:
    //Эффекты тени для текста
    QGraphicsDropShadowEffect* shadow1;
    QGraphicsDropShadowEffect* shadow2;

    /*Значение стата имеет ограничение в 9999999, превышать которое не стоит
     *из-за возрастающего риска переполнения при взаимодействии с ним*/
    long value = 0;
    QString SValue;

    Ui::SecondarySkill *ui;

    /*Переопределения виртуальных функций QWidget для вызова сигнала вывода
     *или удаления подсказки. Крайне важно помнить, что у любого фиджета,
     *который хочет показывать подсказку, все дочерние элементы интерфейса
     *обязательно должны быть disabled. Сделать это можно в редакторе форм
     *сняв у них галочку enabled. Иначе некоторые эвенты будут "застревать"
     *в дочерних элементах виджета и не передаться родительскому*/
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    TooltipDisplayEvents tooltipDisplayEvents;
};

#endif // SECONDARYSKILL_H

/************************************************************************
 *Данный класс представляет собой панельку вторичного навыка. Вынесен
 *в отдельный класс просто для выведения подсказки и гарантии того,
 *что все QGraphicsDropShadowEffect точно будут удалены в деструкторе.
 ************************************************************************/

#ifndef SECONDARYSKILL_H
#define SECONDARYSKILL_H

#include "System/TooltipDisplayEvents/tooltipdisplayevents.h"
#include "System/OutlineEffect/outlineeffect.h"

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
    void ShowTooltip();
    void RemoveTooltip();

private:
    OutlineEffect* borderInscription;
    OutlineEffect* borderValue;

    /*Значение стата имеет ограничение в 9999999, превышать которое не стоит
     *из-за возрастающего риска переполнения при взаимодействии с ним*/
    long value = 0;
    QString SValue;

    Ui::SecondarySkill *ui;

    /*Переопределения виртуальных функций QWidget для вызова сигнала вывода
     *или удаления подсказки. Вся логика происходит в классе TooltipDisplayEvents*/
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    TooltipDisplayEvents tooltipDisplayEvents;
};

#endif // SECONDARYSKILL_H

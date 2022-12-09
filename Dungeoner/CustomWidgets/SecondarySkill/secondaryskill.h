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
#include <qgridlayout.h>

#include <Person/Stat/stat.h>

namespace Ui {
class SecondarySkill;
}

class SecondarySkill : public QWidget
{
    Q_OBJECT

public:
    explicit SecondarySkill(QWidget *parent = nullptr);
    ~SecondarySkill();

    int getValue() const;
    /*Сеттер на переменную Value. Также устанавливает число в
     *лейбл Value и меняет его межстрочный интервал*/
    void setValue(int newValue);
    void setInscription(QString inscription);
    void setFontSize(int size);

    int getScrollAreaHeight() const;
    void setScrollAreaHeight(int newScrollAreaHeight);

    int getScrollAreaOffset() const;
    void setScrollAreaOffset(int newScrollAreaOffset);

    void setTooltipContent(QString fullName, QString formula, QString description);
    void setFormula(QString formula, int fontSize);

    void setStat(Stat *newStat);

signals:
    void ShowTooltip(QVector<QLabel*> TooltipContent);
    void RemoveTooltip();

private slots:
    void bonusesChanged();

private:
    OutlineEffect* borderInscription;
    OutlineEffect* borderValue;

    //Энум знака числа. Используется для подсказки бонусов
    enum NumberSign{
        PLUS,
        MINUS,
        ZERO
    };
    NumberSign numberSign = ZERO;

    /*Значение стата имеет ограничение в 9999999, превышать которое не стоит
     *из-за возрастающего риска переполнения при взаимодействии с ним*/
    int value = 0;
    QString SValue;

    Stat* stat = nullptr;

    QLabel* formulaLabel = new QLabel;
    QVector<QLabel*> tooltipContent;
    QLabel* valueLabel = new QLabel;
    QLabel* bonusesLabel = new QLabel;
    QGridLayout* bonusesLayout = new QGridLayout;
    //Генерация лейбла с информацией по всем бонусам для его дальнейшего добавления в tooltipContent
    void CreatingBonusTooltip();

    bool bonusesLableIsAppend = 0;

    Ui::SecondarySkill *ui;

    /*Переопределения виртуальных функций QWidget для вызова сигнала вывода
     *или удаления подсказки. Вся логика происходит в классе TooltipDisplayEvents*/
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    TooltipDisplayEvents tooltipDisplayEvents;

    //Высота скроллбара, в который помещён вторичный навык
    int ScrollAreaHeight = 0;
    //Сдвиг скроллбара, в который помещён вторичный навык
    int ScrollAreaOffset = 0;
};

#endif // SECONDARYSKILL_H

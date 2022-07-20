#ifndef SECONDARYSKILL_H
#define SECONDARYSKILL_H

/*Данный класс представляет собой панельку вторичного навыка. Вынесен
 *в отдельный класс просто для удобства и гарантии того, что все
 *QGraphicsDropShadowEffect точно будут удалены в деструкторе.*/

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

private:
    //Эффекты тени для текста
    QGraphicsDropShadowEffect* shadow1;
    QGraphicsDropShadowEffect* shadow2;

    /*Значение стата имеет ограничение в 9999999, превышать которое не стоит
     *из-за возрастающего риска переполнения при взаимодействии с ним*/
    long value = 0;
    QString SValue;

    Ui::SecondarySkill *ui;
};

#endif // SECONDARYSKILL_H

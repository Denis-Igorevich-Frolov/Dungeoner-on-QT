#ifndef SECONDARYSKILL_H
#define SECONDARYSKILL_H

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
    void setValue(long newValue);
    void setInscription(QString inscription);
    void setFontSize(int size);

private:
    QGraphicsDropShadowEffect* shadow1;
    QGraphicsDropShadowEffect* shadow2;

    long value = 0;
    QString SValue;

    Ui::SecondarySkill *ui;
};

#endif // SECONDARYSKILL_H

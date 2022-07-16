#ifndef PRIMARYSKILLSIGNATURE_H
#define PRIMARYSKILLSIGNATURE_H

/*
 *Данный виджет - это подпись первичных навыков. Он имеет
 *в себе LabelWithTooltip для вывода полной информации. В
 *виджете есть 2 кнопки для повышения и понижения значения
 *соответствующего навыка.
 */

#include <QWidget>
#include <QSpinBox>

namespace Ui {
class PrimarySkillSignature;
}

class PrimarySkillSignature : public QWidget
{
    Q_OBJECT

public:
    explicit PrimarySkillSignature(QWidget *parent = nullptr);
    ~PrimarySkillSignature();

    QSpinBox *SpinBoxValue;

    void setText(QString text);

private slots:
    void on_ButtonTop_released();
    void on_ButtonBottom_released();

private:
    Ui::PrimarySkillSignature *ui;

    //Массив нажатых клавиш, среди которых только Ctrl, Shift и Alt
    QVector<int> pressedKeys;

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
};

#endif // PRIMARYSKILLSIGNATURE_H

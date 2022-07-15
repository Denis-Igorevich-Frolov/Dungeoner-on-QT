#ifndef CHARACTERWINDOW_H
#define CHARACTERWINDOW_H

/*
 *Окно персонажа, содержащее всю информацию о нём
 */

#include <QWidget>

namespace Ui {
class CharacterWindow;
}

class CharacterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterWindow(QWidget *parent = nullptr);
    ~CharacterWindow();

private:
    Ui::CharacterWindow *ui;

    void setTextPrimarySkillSignature ();
    void setStyles ();
    void associatingLabelsWithValues();
};

#endif // CHARACTERWINDOW_H

#ifndef CHARACTERWINDOW_H
#define CHARACTERWINDOW_H

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
};

#endif // CHARACTERWINDOW_H

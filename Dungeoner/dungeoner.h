#ifndef DUNGEONER_H
#define DUNGEONER_H

#include <QMainWindow>
#include <Windows/CharacterWindow/characterwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Dungeoner; }
QT_END_NAMESPACE

class Dungeoner : public QMainWindow
{
    Q_OBJECT

public:
    Dungeoner(QWidget *parent = nullptr);
    ~Dungeoner();

private:
    Ui::Dungeoner *ui;
    CharacterWindow *characterWindow;
};
#endif // DUNGEONER_H

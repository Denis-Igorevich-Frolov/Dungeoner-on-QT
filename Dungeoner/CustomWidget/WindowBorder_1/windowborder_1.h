#ifndef WINDOWBORDER_1_H
#define WINDOWBORDER_1_H

/*Данный класс является виджетом рамки. Просто рамка*/

#include <QWidget>

namespace Ui {
class WindowBorder_1;
}

class WindowBorder_1 : public QWidget
{
    Q_OBJECT

public:
    explicit WindowBorder_1(QWidget *parent = nullptr);
    ~WindowBorder_1();

private:
    Ui::WindowBorder_1 *ui;
};

#endif // WINDOWBORDER_1_H

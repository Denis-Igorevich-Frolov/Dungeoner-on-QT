/*********************************************************
 *Данный класс является виджетом рамки. Просто рамка,
 *от остальных отличается только внешним видом
 *********************************************************/

#ifndef WINDOWBORDER_1_H
#define WINDOWBORDER_1_H

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

#ifndef WINDOWBORDER_2_H
#define WINDOWBORDER_2_H

#include <QWidget>

namespace Ui {
class WindowBorder_2;
}

class WindowBorder_2 : public QWidget
{
    Q_OBJECT

public:
    explicit WindowBorder_2(QWidget *parent = nullptr);
    ~WindowBorder_2();

private:
    Ui::WindowBorder_2 *ui;
};

#endif // WINDOWBORDER_2_H

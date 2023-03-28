#ifndef WINDOWBORDER_3_H
#define WINDOWBORDER_3_H

#include <QWidget>

namespace Ui {
class WindowBorder_3;
}

class WindowBorder_3 : public QWidget
{
    Q_OBJECT

public:
    explicit WindowBorder_3(QWidget *parent = nullptr);
    ~WindowBorder_3();

private:
    Ui::WindowBorder_3 *ui;

    void resizeEvent(QResizeEvent* event) override;
};

#endif // WINDOWBORDER_3_H

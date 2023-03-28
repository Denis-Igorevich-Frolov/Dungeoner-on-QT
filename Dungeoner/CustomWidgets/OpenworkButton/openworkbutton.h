#ifndef OPENWORKBUTTON_H
#define OPENWORKBUTTON_H

#include <QWidget>

namespace Ui {
class OpenworkButton;
}

class OpenworkButton : public QWidget
{
    Q_OBJECT

public:
    explicit OpenworkButton(QWidget *parent = nullptr);
    ~OpenworkButton();

    void setTextSize(int size);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_pushButton_toggled(bool checked);

private:
    Ui::OpenworkButton *ui;

    void resizeEvent(QResizeEvent* event) override;
};

#endif // OPENWORKBUTTON_H

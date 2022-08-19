#ifndef TOOLTIP_H
#define TOOLTIP_H

#include "qboxlayout.h"
#include "qlabel.h"

#include <QWidget>

namespace Ui {
class Tooltip;
}

class Tooltip : public QWidget
{
    Q_OBJECT

public:
    explicit Tooltip(QWidget *parent = nullptr);
    ~Tooltip();

    void setContent(QVector<QLabel*> content);

private:
    Ui::Tooltip *ui;

    /*Переопределённая виртуальная функция класса QWidget. /////*/
    void resizeEvent(QResizeEvent* event) override;

    QVBoxLayout* layout = new QVBoxLayout;
};

#endif // TOOLTIP_H

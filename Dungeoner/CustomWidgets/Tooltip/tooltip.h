#ifndef TOOLTIP_H
#define TOOLTIP_H

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

private:
    Ui::Tooltip *ui;
};

#endif // TOOLTIP_H

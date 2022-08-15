#ifndef MAGICDEFENSEPROGRESSBAR_H
#define MAGICDEFENSEPROGRESSBAR_H

#include <QWidget>

#include <CustomWidgets/ProgressBar_2/progressbar_2.h>

#include "System/OutlineEffect/outlineeffect.h"

namespace Ui {
class MagicDefenseProgressBar;
}

class MagicDefenseProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit MagicDefenseProgressBar(QWidget *parent = nullptr);
    ~MagicDefenseProgressBar();

    ProgressBar_2* getProgressBar();
    void setName(QString name);

private:
    Ui::MagicDefenseProgressBar *ui;

    OutlineEffect* outlineEffect;
};

#endif // MAGICDEFENSEPROGRESSBAR_H

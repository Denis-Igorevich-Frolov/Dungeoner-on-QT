#ifndef SECONDARYSKILLPROGRESSBAR_H
#define SECONDARYSKILLPROGRESSBAR_H

#include "System/OutlineEffect/outlineeffect.h"

#include <QWidget>

#include <CustomWidgets/ProgressBar_1/progressbar_1.h>

namespace Ui {
class SecondarySkillProgressBar;
}

class SecondarySkillProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit SecondarySkillProgressBar(QWidget *parent = nullptr);
    ~SecondarySkillProgressBar();

    ProgressBar_1* getProgressBar();
    void setName(QString name);

private:
    Ui::SecondarySkillProgressBar *ui;

    OutlineEffect* outlineEffect;
};

#endif // SECONDARYSKILLPROGRESSBAR_H

/*****************************************************************************************
 *Данный класс является готовым и подогнанным прогрессбаром с лейблом названия
 *сверху и разделителем снизу. Выделен в отдельный класс для простоты последующего
 *позиционирования и гарантии того, что все outlineEffect будут удалены в деструкторе.
 *****************************************************************************************/

#ifndef SECONDARYSKILLPROGRESSBAR_H
#define SECONDARYSKILLPROGRESSBAR_H

#include "System/OutlineEffect/outlineeffect.h"
#include "CustomWidgets/ProgressBar_1/progressbar_1.h"

#include <QWidget>

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
    //Установка текста лейблу над прогрессбаром
    void setName(QString name);

private:
    Ui::SecondarySkillProgressBar *ui;

    OutlineEffect* outlineEffect;
};

#endif // SECONDARYSKILLPROGRESSBAR_H

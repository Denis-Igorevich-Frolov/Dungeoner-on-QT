/*****************************************************************************************
 *Данный класс является готовым и подогнанным прогрессбаром магической защиты с лейблом
 *названия. Выделен в отдельный класс для простоты последующего позиционирования и
 *гарантии того, что все outlineEffect будут удалены в деструкторе.
 *****************************************************************************************/

#ifndef MAGICDEFENSEPROGRESSBAR_H
#define MAGICDEFENSEPROGRESSBAR_H

#include <QWidget>

#include "CustomWidgets/ProgressBar_2/progressbar_2.h"
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
    //Установка текста лейблу над прогрессбаром
    void setName(QString name);

private:
    Ui::MagicDefenseProgressBar *ui;

    OutlineEffect* outlineEffect;
};

#endif // MAGICDEFENSEPROGRESSBAR_H

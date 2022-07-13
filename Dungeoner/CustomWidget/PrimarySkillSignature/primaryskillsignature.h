#ifndef PRIMARYSKILLSIGNATURE_H
#define PRIMARYSKILLSIGNATURE_H

#include <QWidget>

namespace Ui {
class PrimarySkillSignature;
}

class PrimarySkillSignature : public QWidget
{
    Q_OBJECT

public:
    explicit PrimarySkillSignature(QWidget *parent = nullptr);
    ~PrimarySkillSignature();

private:
    Ui::PrimarySkillSignature *ui;
};

#endif // PRIMARYSKILLSIGNATURE_H

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

protected:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
};

#endif // PRIMARYSKILLSIGNATURE_H

#include "magicdefenseprogressbar.h"
#include "ui_magicdefenseprogressbar.h"
#include "MDP_stylemaster.h"

MagicDefenseProgressBar::MagicDefenseProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MagicDefenseProgressBar)
{
    ui->setupUi(this);

    ui->Name->setStyleSheet(MDP_StyleMaster::TextFontStyle(25, "Algerian"));

    outlineEffect = new OutlineEffect;
    outlineEffect->setOutlineThickness(1);
    ui->Name->setGraphicsEffect(outlineEffect);
}

MagicDefenseProgressBar::~MagicDefenseProgressBar()
{
    delete outlineEffect;
    delete ui;
}

ProgressBar_2* MagicDefenseProgressBar::getProgressBar()
{
    return ui->progressBar;
}

void MagicDefenseProgressBar::setName(QString name)
{
    ui->Name->setText(name);
}

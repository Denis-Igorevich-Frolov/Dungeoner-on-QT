#include "magicdefenseprogressbar.h"
#include "ui_magicdefenseprogressbar.h"
#include "MDP_stylemaster.h"

MagicDefenseProgressBar::MagicDefenseProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MagicDefenseProgressBar)
{
    ui->setupUi(this);

    //Установка стиля лейблу имени
    ui->Name->setFont(QFont("TextFont"));
    ui->Name->setStyleSheet(MDP_StyleMaster::TextFontStyle(25));

    //Установка эффекта обводки лейблу имени
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

//Установка текста лейблу над прогрессбаром
void MagicDefenseProgressBar::setName(QString name)
{
    ui->Name->setText(name);
}

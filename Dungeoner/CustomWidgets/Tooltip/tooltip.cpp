#include "tooltip.h"
#include "ui_tooltip.h"
#include "T_stylemaster.h"

Tooltip::Tooltip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tooltip)
{
    ui->setupUi(this);

    ui->Background->setStyleSheet(T_StyleMaster::BackgroundStyle());
    layout->setContentsMargins(17, 17, 17, 17);
    layout->setSpacing(5);
    ui->Content->setLayout(layout);
}

Tooltip::~Tooltip()
{
    qDeleteAll(layout->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
    delete layout;
    delete ui;
}

void Tooltip::setContent(QVector<QLabel *> content)
{
    delete layout;
    layout = new QVBoxLayout;
    layout->setContentsMargins(17, 17, 17, 17);
    layout->setSpacing(5);
    ui->Content->setLayout(layout);

    for(QLabel* label : content){
        label->setAlignment(Qt::AlignCenter);
        layout->addWidget(label);
    }

    setFixedSize(ui->Content->sizeHint()+QSize(30, 30));
}

void Tooltip::resizeEvent(QResizeEvent *event)
{
    ui->Content->setFixedSize(ui->Content->sizeHint());
    ui->Background->setFixedSize(this->size()-QSize(30, 30));
    ui->Border->setFixedSize(this->size()-QSize(30, 30));
}

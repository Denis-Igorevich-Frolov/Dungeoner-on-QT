#include "tooltip.h"
#include "ui_tooltip.h"
#include "T_stylemaster.h"

Tooltip::Tooltip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tooltip)
{
    ui->setupUi(this);

    ui->Background->setStyleSheet(T_StyleMaster::BackgroundStyle());
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
    delete ui->Content;
    ui->Content = new QFrame(this);
    ui->Content->move(15, 15);

    layout = new QVBoxLayout(ui->Content);
    layout->setContentsMargins(17, 12, 17, 12);
    layout->setSpacing(5);

    for(QLabel* label : content){
        QLabel* newLabel = new QLabel;
        newLabel->setAlignment(Qt::AlignCenter);
        newLabel->setText(label->text());
        newLabel->setStyleSheet(label->styleSheet());
        newLabel->setFixedSize(label->maximumSize());
        newLabel->setFont(label->font());
        layout->addWidget(newLabel);
    }

    setFixedSize(ui->Content->sizeHint()+QSize(30, 30));
}

void Tooltip::resizeEvent(QResizeEvent *event)
{
    ui->Content->setFixedSize(ui->Content->sizeHint());
    if(this->size().rwidth()>0&&this->size().rheight()>0){
        ui->Background->setFixedSize(this->size()-QSize(30, 30));
        ui->Border->setFixedSize(this->size()-QSize(30, 30));
    }
}

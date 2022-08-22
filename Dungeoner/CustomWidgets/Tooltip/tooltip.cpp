#include "tooltip.h"
#include "System/OutlineEffect/outlineeffect.h"
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
    for(auto item : ui->Content->children())
        delete item;

    layout = new QVBoxLayout(ui->Content);
    layout->setContentsMargins(17, 12, 17, 12);
    layout->setSpacing(8);

    int i = 0;
    for(QLabel* label : content){
        QLabel* newLabel = new QLabel;
        newLabel->setWordWrap(true);
        newLabel->setText(label->text());
        newLabel->setAlignment(Qt::AlignCenter);
        newLabel->setStyleSheet(label->styleSheet());
        newLabel->setMinimumSize(label->minimumSize());
        newLabel->setMaximumSize(label->maximumSize());
        newLabel->setFont(label->font());
        layout->addWidget(newLabel);
        if(newLabel->text().isEmpty())
            layout->setAlignment(newLabel, Qt::AlignHCenter);
        else{
            OutlineEffect* border = new OutlineEffect;
            border->setOutlineThickness(2);
            newLabel->setGraphicsEffect(border);
            newLabel->setMargin(2);
        }

        i++;
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

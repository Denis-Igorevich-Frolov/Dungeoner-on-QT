#include "paragraphwithborder.h"
#include "ui_paragraphwithborder.h"

#include <QLabel>

ParagraphWithBorder::ParagraphWithBorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParagraphWithBorder)
{
    ui->setupUi(this);

    setFontStyle(QColor("#bdc440"), QColor("#0b0a05"), 3, fontType);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
}

ParagraphWithBorder::~ParagraphWithBorder()
{
    for(auto *item:ui->wrapper->layout()->children())
        delete item;
    delete layout;

    delete ui;
}

void ParagraphWithBorder::setText(QString text)
{
    QLayoutItem *item;
        while ((item = layout->takeAt(0))){
            delete static_cast<LabelWithBorder*>(item->widget());
            delete item;
        }
    lines.clear();

    append(text);
}

void ParagraphWithBorder::append(QString text)
{
    QString line;
    for(int i = 0; i<text.size(); i++){
        if(text.at(i)=='/'&&i<text.size()-1)
            if(text.at(i+1)=='n'){
                lines.append(line);
                line.clear();
                i++;
                continue;
            }
        line.append(text.at(i));
    }

    if(lines.size()>0) {
        for (int i = 0; i<lines.size(); i++){
            LabelWithBorder *label = new LabelWithBorder;
            label->setText(lines.at(i));
            label->setFontStyle(textColor, borderColor, borderThickness, fontType);
            layout->addWidget(label);
        }
    }
    ui->wrapper->setLayout(layout);
}

void ParagraphWithBorder::setFontStyle(QColor textColor, QColor borderColor, int borderThickness, LabelWithBorder::FontType fontType)
{
    this->borderThickness = borderThickness;
    this->textColor = textColor;
    this->borderColor = borderColor;
    this->borderThickness = borderThickness;
    this->fontType = fontType;
}

ParagraphWithBorder::VerticalAlignment ParagraphWithBorder::getVerticalAlignment() const
{
    return verticalAlignment;
}

void ParagraphWithBorder::setVerticalAlignment(VerticalAlignment newVerticalAlignment)
{
    verticalAlignment = newVerticalAlignment;
    if(verticalAlignment == ParagraphWithBorder::CENTER){
        ui->BottomSpacer->changeSize(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->TopSpacer->changeSize(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    } else if(verticalAlignment == ParagraphWithBorder::TOP){
        ui->BottomSpacer->changeSize(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->TopSpacer->changeSize(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed);
    } else if(verticalAlignment == ParagraphWithBorder::BOTTOM){
        ui->BottomSpacer->changeSize(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed);
        ui->TopSpacer->changeSize(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
}

void ParagraphWithBorder::setHorizontalAlignment(LabelWithBorder::HorizontalAlignment newHorizontalAlignment)
{
    if(ui->wrapper->children().size()!=0)
        for(auto *item:ui->wrapper->children())
            if(dynamic_cast<LabelWithBorder*>(item))
                static_cast<LabelWithBorder*>(item)->setHorizontalAlignment(newHorizontalAlignment);
}

void ParagraphWithBorder::setAlignment(VerticalAlignment verticalAlignment, LabelWithBorder::HorizontalAlignment horizontalAlignment)
{
    setVerticalAlignment(verticalAlignment);
    setHorizontalAlignment(horizontalAlignment);
}

int ParagraphWithBorder::getLineSpacing() const
{
    return lineSpacing;
}

void ParagraphWithBorder::setLineSpacing(int newLineSpacing)
{
//    ui->wrapper->resize(ui->wrapper->layout()->sizeHint().width(), ui->wrapper->layout()->sizeHint().height()-lineSpacing*lines.size());
    lineSpacing = newLineSpacing;
//    ui->wrapper->resize(ui->wrapper->layout()->sizeHint().width(), ui->wrapper->layout()->sizeHint().height()+lineSpacing*lines.size());
//    for(auto *item:ui->wrapper->children())
//        if(dynamic_cast<LabelWithBorder*>(item)){
//            LabelWithBorder* label = static_cast<LabelWithBorder*>(item);
//        }
}

/********************************************************************************
** Form generated from reading UI file 'labelwithtooltip.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELWITHTOOLTIP_H
#define UI_LABELWITHTOOLTIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabelWithTooltip
{
public:
    QPushButton *ButtonText;

    void setupUi(QWidget *LabelWithTooltip)
    {
        if (LabelWithTooltip->objectName().isEmpty())
            LabelWithTooltip->setObjectName(QString::fromUtf8("LabelWithTooltip"));
        LabelWithTooltip->resize(75, 24);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelWithTooltip->sizePolicy().hasHeightForWidth());
        LabelWithTooltip->setSizePolicy(sizePolicy);
        LabelWithTooltip->setMinimumSize(QSize(75, 24));
        LabelWithTooltip->setMaximumSize(QSize(75, 24));
        LabelWithTooltip->setProperty("fontSize", QVariant(23));
        ButtonText = new QPushButton(LabelWithTooltip);
        ButtonText->setObjectName(QString::fromUtf8("ButtonText"));
        ButtonText->setGeometry(QRect(0, 0, 75, 24));
        sizePolicy.setHeightForWidth(ButtonText->sizePolicy().hasHeightForWidth());
        ButtonText->setSizePolicy(sizePolicy);
        ButtonText->setMaximumSize(QSize(75, 24));
        ButtonText->setCursor(QCursor(Qt::WhatsThisCursor));

        retranslateUi(LabelWithTooltip);

        QMetaObject::connectSlotsByName(LabelWithTooltip);
    } // setupUi

    void retranslateUi(QWidget *LabelWithTooltip)
    {
        LabelWithTooltip->setWindowTitle(QCoreApplication::translate("LabelWithTooltip", "Form", nullptr));
        ButtonText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LabelWithTooltip: public Ui_LabelWithTooltip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELWITHTOOLTIP_H

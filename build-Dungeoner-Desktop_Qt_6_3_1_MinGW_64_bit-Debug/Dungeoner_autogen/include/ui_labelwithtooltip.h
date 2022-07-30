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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabelWithTooltip
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *ButtonText;

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
        LabelWithTooltip->setCursor(QCursor(Qt::WhatsThisCursor));
        LabelWithTooltip->setProperty("fontSize", QVariant(23));
        horizontalLayout = new QHBoxLayout(LabelWithTooltip);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ButtonText = new QLabel(LabelWithTooltip);
        ButtonText->setObjectName(QString::fromUtf8("ButtonText"));
        ButtonText->setEnabled(false);
        ButtonText->setLayoutDirection(Qt::RightToLeft);
        ButtonText->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(ButtonText);


        retranslateUi(LabelWithTooltip);

        QMetaObject::connectSlotsByName(LabelWithTooltip);
    } // setupUi

    void retranslateUi(QWidget *LabelWithTooltip)
    {
        LabelWithTooltip->setWindowTitle(QCoreApplication::translate("LabelWithTooltip", "Form", nullptr));
        ButtonText->setText(QCoreApplication::translate("LabelWithTooltip", "NON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LabelWithTooltip: public Ui_LabelWithTooltip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELWITHTOOLTIP_H

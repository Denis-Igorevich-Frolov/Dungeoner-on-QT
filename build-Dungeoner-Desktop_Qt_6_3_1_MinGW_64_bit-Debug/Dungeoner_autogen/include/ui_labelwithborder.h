/********************************************************************************
** Form generated from reading UI file 'labelwithborder.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELWITHBORDER_H
#define UI_LABELWITHBORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabelWithBorder
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *LabelText;

    void setupUi(QWidget *LabelWithBorder)
    {
        if (LabelWithBorder->objectName().isEmpty())
            LabelWithBorder->setObjectName(QString::fromUtf8("LabelWithBorder"));
        LabelWithBorder->resize(75, 34);
        LabelWithBorder->setStyleSheet(QString::fromUtf8(""));
        LabelWithBorder->setProperty("fontSize", QVariant(23));
        horizontalLayout = new QHBoxLayout(LabelWithBorder);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LabelText = new QLabel(LabelWithBorder);
        LabelText->setObjectName(QString::fromUtf8("LabelText"));
        LabelText->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelText->sizePolicy().hasHeightForWidth());
        LabelText->setSizePolicy(sizePolicy);
        LabelText->setLayoutDirection(Qt::RightToLeft);
        LabelText->setAlignment(Qt::AlignCenter);
        LabelText->setWordWrap(false);

        horizontalLayout->addWidget(LabelText);


        retranslateUi(LabelWithBorder);

        QMetaObject::connectSlotsByName(LabelWithBorder);
    } // setupUi

    void retranslateUi(QWidget *LabelWithBorder)
    {
        LabelWithBorder->setWindowTitle(QCoreApplication::translate("LabelWithBorder", "Form", nullptr));
        LabelText->setText(QCoreApplication::translate("LabelWithBorder", "NON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LabelWithBorder: public Ui_LabelWithBorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELWITHBORDER_H

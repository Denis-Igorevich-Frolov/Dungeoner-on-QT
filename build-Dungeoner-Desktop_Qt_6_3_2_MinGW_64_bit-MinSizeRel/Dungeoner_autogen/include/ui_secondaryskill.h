/********************************************************************************
** Form generated from reading UI file 'secondaryskill.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDARYSKILL_H
#define UI_SECONDARYSKILL_H

#include <CustomWidgets/WindowBorder_1/windowborder_1.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondarySkill
{
public:
    QHBoxLayout *horizontalLayout;
    WindowBorder_1 *Border;
    QLabel *Value;
    QLabel *Inscription;

    void setupUi(QWidget *SecondarySkill)
    {
        if (SecondarySkill->objectName().isEmpty())
            SecondarySkill->setObjectName(QString::fromUtf8("SecondarySkill"));
        SecondarySkill->resize(304, 71);
        SecondarySkill->setCursor(QCursor(Qt::WhatsThisCursor));
        horizontalLayout = new QHBoxLayout(SecondarySkill);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 1, 1);
        Border = new WindowBorder_1(SecondarySkill);
        Border->setObjectName(QString::fromUtf8("Border"));
        Border->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Border->sizePolicy().hasHeightForWidth());
        Border->setSizePolicy(sizePolicy);
        Border->setMinimumSize(QSize(303, 70));
        Border->setMaximumSize(QSize(303, 70));
        Border->setStyleSheet(QString::fromUtf8(""));
        Value = new QLabel(Border);
        Value->setObjectName(QString::fromUtf8("Value"));
        Value->setGeometry(QRect(194, 0, 80, 70));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Value->sizePolicy().hasHeightForWidth());
        Value->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        font.setStrikeOut(false);
        font.setKerning(false);
        Value->setFont(font);
        Value->setStyleSheet(QString::fromUtf8(""));
        Value->setTextFormat(Qt::AutoText);
        Value->setScaledContents(false);
        Value->setAlignment(Qt::AlignCenter);
        Value->setWordWrap(true);
        Value->setIndent(0);
        Value->setOpenExternalLinks(false);
        Inscription = new QLabel(Border);
        Inscription->setObjectName(QString::fromUtf8("Inscription"));
        Inscription->setGeometry(QRect(32, 13, 162, 45));
        sizePolicy.setHeightForWidth(Inscription->sizePolicy().hasHeightForWidth());
        Inscription->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(17);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        Inscription->setFont(font1);
        Inscription->setStyleSheet(QString::fromUtf8(""));
        Inscription->setTextFormat(Qt::AutoText);
        Inscription->setScaledContents(false);
        Inscription->setAlignment(Qt::AlignCenter);
        Inscription->setWordWrap(true);
        Inscription->setIndent(0);
        Inscription->setOpenExternalLinks(false);

        horizontalLayout->addWidget(Border);


        retranslateUi(SecondarySkill);

        QMetaObject::connectSlotsByName(SecondarySkill);
    } // setupUi

    void retranslateUi(QWidget *SecondarySkill)
    {
        SecondarySkill->setWindowTitle(QCoreApplication::translate("SecondarySkill", "Form", nullptr));
        Value->setText(QCoreApplication::translate("SecondarySkill", "0", nullptr));
        Inscription->setText(QCoreApplication::translate("SecondarySkill", "NON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondarySkill: public Ui_SecondarySkill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDARYSKILL_H

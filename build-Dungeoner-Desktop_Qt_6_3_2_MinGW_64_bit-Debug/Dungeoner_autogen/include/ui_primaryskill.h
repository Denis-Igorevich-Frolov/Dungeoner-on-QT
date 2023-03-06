/********************************************************************************
** Form generated from reading UI file 'primaryskill.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMARYSKILL_H
#define UI_PRIMARYSKILL_H

#include <CustomWidgets/PrimarySkillSignature/primaryskillsignature.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimarySkill
{
public:
    PrimarySkillSignature *primarySkillSignature;
    QSpinBox *Value;

    void setupUi(QWidget *PrimarySkill)
    {
        if (PrimarySkill->objectName().isEmpty())
            PrimarySkill->setObjectName(QString::fromUtf8("PrimarySkill"));
        PrimarySkill->resize(111, 105);
        primarySkillSignature = new PrimarySkillSignature(PrimarySkill);
        primarySkillSignature->setObjectName(QString::fromUtf8("primarySkillSignature"));
        primarySkillSignature->setGeometry(QRect(0, 0, 111, 58));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(primarySkillSignature->sizePolicy().hasHeightForWidth());
        primarySkillSignature->setSizePolicy(sizePolicy);
        primarySkillSignature->setMinimumSize(QSize(111, 58));
        primarySkillSignature->setMaximumSize(QSize(111, 58));
        primarySkillSignature->setMouseTracking(true);
        primarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        Value = new QSpinBox(PrimarySkill);
        Value->setObjectName(QString::fromUtf8("Value"));
        Value->setGeometry(QRect(11, 70, 89, 35));
        sizePolicy.setHeightForWidth(Value->sizePolicy().hasHeightForWidth());
        Value->setSizePolicy(sizePolicy);
        Value->setMinimumSize(QSize(89, 35));
        Value->setMaximumSize(QSize(89, 35));
        Value->setCursor(QCursor(Qt::IBeamCursor));
        Value->setLayoutDirection(Qt::LeftToRight);
        Value->setStyleSheet(QString::fromUtf8(""));
        Value->setAlignment(Qt::AlignCenter);
        Value->setMaximum(999999);
        Value->setProperty("fontSize", QVariant(28));

        retranslateUi(PrimarySkill);

        QMetaObject::connectSlotsByName(PrimarySkill);
    } // setupUi

    void retranslateUi(QWidget *PrimarySkill)
    {
        PrimarySkill->setWindowTitle(QCoreApplication::translate("PrimarySkill", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrimarySkill: public Ui_PrimarySkill {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMARYSKILL_H

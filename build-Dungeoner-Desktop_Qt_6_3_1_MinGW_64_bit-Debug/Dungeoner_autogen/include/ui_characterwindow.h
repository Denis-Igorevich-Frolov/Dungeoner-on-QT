/********************************************************************************
** Form generated from reading UI file 'characterwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERWINDOW_H
#define UI_CHARACTERWINDOW_H

#include <CustomWidget/PrimarySkillSignature/primaryskillsignature.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterWindow
{
public:
    QFrame *PrimarySkillSignatures;
    PrimarySkillSignature *StrengthPrimarySkillSignature;
    PrimarySkillSignature *AgilityPrimarySkillSignature;
    PrimarySkillSignature *IntelligencePrimarySkillSignature;
    PrimarySkillSignature *MagicPrimarySkillSignature;
    PrimarySkillSignature *BodyTypePrimarySkillSignature;
    PrimarySkillSignature *WillPrimarySkillSignature;

    void setupUi(QWidget *CharacterWindow)
    {
        if (CharacterWindow->objectName().isEmpty())
            CharacterWindow->setObjectName(QString::fromUtf8("CharacterWindow"));
        CharacterWindow->resize(1037, 389);
        CharacterWindow->setStyleSheet(QString::fromUtf8("background: #130a0f;"));
        PrimarySkillSignatures = new QFrame(CharacterWindow);
        PrimarySkillSignatures->setObjectName(QString::fromUtf8("PrimarySkillSignatures"));
        PrimarySkillSignatures->setGeometry(QRect(100, 80, 611, 58));
        PrimarySkillSignatures->setFrameShape(QFrame::StyledPanel);
        PrimarySkillSignatures->setFrameShadow(QFrame::Raised);
        StrengthPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        StrengthPrimarySkillSignature->setObjectName(QString::fromUtf8("StrengthPrimarySkillSignature"));
        StrengthPrimarySkillSignature->setGeometry(QRect(0, 0, 111, 58));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StrengthPrimarySkillSignature->sizePolicy().hasHeightForWidth());
        StrengthPrimarySkillSignature->setSizePolicy(sizePolicy);
        StrengthPrimarySkillSignature->setMinimumSize(QSize(111, 58));
        StrengthPrimarySkillSignature->setMaximumSize(QSize(111, 58));
        StrengthPrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        AgilityPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        AgilityPrimarySkillSignature->setObjectName(QString::fromUtf8("AgilityPrimarySkillSignature"));
        AgilityPrimarySkillSignature->setGeometry(QRect(100, 0, 111, 58));
        sizePolicy.setHeightForWidth(AgilityPrimarySkillSignature->sizePolicy().hasHeightForWidth());
        AgilityPrimarySkillSignature->setSizePolicy(sizePolicy);
        AgilityPrimarySkillSignature->setMinimumSize(QSize(111, 58));
        AgilityPrimarySkillSignature->setMaximumSize(QSize(111, 58));
        AgilityPrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        IntelligencePrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        IntelligencePrimarySkillSignature->setObjectName(QString::fromUtf8("IntelligencePrimarySkillSignature"));
        IntelligencePrimarySkillSignature->setGeometry(QRect(200, 0, 111, 58));
        sizePolicy.setHeightForWidth(IntelligencePrimarySkillSignature->sizePolicy().hasHeightForWidth());
        IntelligencePrimarySkillSignature->setSizePolicy(sizePolicy);
        IntelligencePrimarySkillSignature->setMinimumSize(QSize(111, 58));
        IntelligencePrimarySkillSignature->setMaximumSize(QSize(111, 58));
        IntelligencePrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        MagicPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        MagicPrimarySkillSignature->setObjectName(QString::fromUtf8("MagicPrimarySkillSignature"));
        MagicPrimarySkillSignature->setGeometry(QRect(300, 0, 111, 58));
        sizePolicy.setHeightForWidth(MagicPrimarySkillSignature->sizePolicy().hasHeightForWidth());
        MagicPrimarySkillSignature->setSizePolicy(sizePolicy);
        MagicPrimarySkillSignature->setMinimumSize(QSize(111, 58));
        MagicPrimarySkillSignature->setMaximumSize(QSize(111, 58));
        MagicPrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        BodyTypePrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        BodyTypePrimarySkillSignature->setObjectName(QString::fromUtf8("BodyTypePrimarySkillSignature"));
        BodyTypePrimarySkillSignature->setGeometry(QRect(400, 0, 111, 58));
        sizePolicy.setHeightForWidth(BodyTypePrimarySkillSignature->sizePolicy().hasHeightForWidth());
        BodyTypePrimarySkillSignature->setSizePolicy(sizePolicy);
        BodyTypePrimarySkillSignature->setMinimumSize(QSize(111, 58));
        BodyTypePrimarySkillSignature->setMaximumSize(QSize(111, 58));
        BodyTypePrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        WillPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        WillPrimarySkillSignature->setObjectName(QString::fromUtf8("WillPrimarySkillSignature"));
        WillPrimarySkillSignature->setGeometry(QRect(500, 0, 111, 58));
        sizePolicy.setHeightForWidth(WillPrimarySkillSignature->sizePolicy().hasHeightForWidth());
        WillPrimarySkillSignature->setSizePolicy(sizePolicy);
        WillPrimarySkillSignature->setMinimumSize(QSize(111, 58));
        WillPrimarySkillSignature->setMaximumSize(QSize(111, 58));
        WillPrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));

        retranslateUi(CharacterWindow);

        QMetaObject::connectSlotsByName(CharacterWindow);
    } // setupUi

    void retranslateUi(QWidget *CharacterWindow)
    {
        CharacterWindow->setWindowTitle(QCoreApplication::translate("CharacterWindow", "Form", nullptr));
        StrengthPrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "NON", nullptr)));
        AgilityPrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "NON", nullptr)));
        IntelligencePrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "NON", nullptr)));
        MagicPrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "NON", nullptr)));
        BodyTypePrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "NON", nullptr)));
        WillPrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "NON", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class CharacterWindow: public Ui_CharacterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERWINDOW_H

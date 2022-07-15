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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *PrimarySkillSignatures;
    PrimarySkillSignature *StrengthPrimarySkillSignature;
    PrimarySkillSignature *AgilityPrimarySkillSignature;
    PrimarySkillSignature *IntelligencePrimarySkillSignature;
    PrimarySkillSignature *MagicPrimarySkillSignature;
    PrimarySkillSignature *BodyTypePrimarySkillSignature;
    PrimarySkillSignature *WillPrimarySkillSignature;
    QSpacerItem *verticalSpacer;
    QFrame *ValuesPanel;
    QFrame *PrimarySkillValues;
    QSpinBox *StrengthValue;
    QSpinBox *AgilityValue;
    QSpinBox *IntelligenceValue;
    QSpinBox *MagicValue;
    QSpinBox *BodyTypeValue;
    QSpinBox *WillValue;
    QFrame *Separators;
    QLabel *Separator4;
    QLabel *Separator1;
    QLabel *Separator5;
    QLabel *Separator2;
    QLabel *Separator3;

    void setupUi(QWidget *CharacterWindow)
    {
        if (CharacterWindow->objectName().isEmpty())
            CharacterWindow->setObjectName(QString::fromUtf8("CharacterWindow"));
        CharacterWindow->resize(1110, 430);
        CharacterWindow->setFocusPolicy(Qt::StrongFocus);
        CharacterWindow->setStyleSheet(QString::fromUtf8("#CharacterWindow{\n"
"	background: #130a0f;\n"
"}"));
        verticalLayoutWidget = new QWidget(CharacterWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 40, 613, 108));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PrimarySkillSignatures = new QFrame(verticalLayoutWidget);
        PrimarySkillSignatures->setObjectName(QString::fromUtf8("PrimarySkillSignatures"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrimarySkillSignatures->sizePolicy().hasHeightForWidth());
        PrimarySkillSignatures->setSizePolicy(sizePolicy);
        PrimarySkillSignatures->setMinimumSize(QSize(611, 58));
        PrimarySkillSignatures->setMaximumSize(QSize(611, 58));
        PrimarySkillSignatures->setFrameShape(QFrame::StyledPanel);
        PrimarySkillSignatures->setFrameShadow(QFrame::Raised);
        StrengthPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        StrengthPrimarySkillSignature->setObjectName(QString::fromUtf8("StrengthPrimarySkillSignature"));
        StrengthPrimarySkillSignature->setGeometry(QRect(0, 0, 111, 58));
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

        verticalLayout->addWidget(PrimarySkillSignatures);

        verticalSpacer = new QSpacerItem(0, 7, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        ValuesPanel = new QFrame(verticalLayoutWidget);
        ValuesPanel->setObjectName(QString::fromUtf8("ValuesPanel"));
        sizePolicy.setHeightForWidth(ValuesPanel->sizePolicy().hasHeightForWidth());
        ValuesPanel->setSizePolicy(sizePolicy);
        ValuesPanel->setMinimumSize(QSize(611, 35));
        ValuesPanel->setMaximumSize(QSize(611, 35));
        ValuesPanel->setFrameShape(QFrame::StyledPanel);
        ValuesPanel->setFrameShadow(QFrame::Raised);
        PrimarySkillValues = new QFrame(ValuesPanel);
        PrimarySkillValues->setObjectName(QString::fromUtf8("PrimarySkillValues"));
        PrimarySkillValues->setGeometry(QRect(0, 0, 611, 35));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PrimarySkillValues->sizePolicy().hasHeightForWidth());
        PrimarySkillValues->setSizePolicy(sizePolicy1);
        PrimarySkillValues->setMinimumSize(QSize(0, 35));
        PrimarySkillValues->setMaximumSize(QSize(16777215, 35));
        PrimarySkillValues->setFrameShape(QFrame::StyledPanel);
        PrimarySkillValues->setFrameShadow(QFrame::Raised);
        StrengthValue = new QSpinBox(PrimarySkillValues);
        StrengthValue->setObjectName(QString::fromUtf8("StrengthValue"));
        StrengthValue->setGeometry(QRect(11, 0, 89, 35));
        sizePolicy.setHeightForWidth(StrengthValue->sizePolicy().hasHeightForWidth());
        StrengthValue->setSizePolicy(sizePolicy);
        StrengthValue->setMinimumSize(QSize(89, 35));
        StrengthValue->setMaximumSize(QSize(89, 35));
        StrengthValue->setCursor(QCursor(Qt::IBeamCursor));
        StrengthValue->setLayoutDirection(Qt::LeftToRight);
        StrengthValue->setStyleSheet(QString::fromUtf8(""));
        StrengthValue->setAlignment(Qt::AlignCenter);
        StrengthValue->setMaximum(999999);
        StrengthValue->setProperty("fontSize", QVariant(28));
        AgilityValue = new QSpinBox(PrimarySkillValues);
        AgilityValue->setObjectName(QString::fromUtf8("AgilityValue"));
        AgilityValue->setGeometry(QRect(111, 0, 89, 35));
        sizePolicy.setHeightForWidth(AgilityValue->sizePolicy().hasHeightForWidth());
        AgilityValue->setSizePolicy(sizePolicy);
        AgilityValue->setMinimumSize(QSize(89, 35));
        AgilityValue->setMaximumSize(QSize(89, 35));
        AgilityValue->setCursor(QCursor(Qt::IBeamCursor));
        AgilityValue->setLayoutDirection(Qt::LeftToRight);
        AgilityValue->setStyleSheet(QString::fromUtf8(""));
        AgilityValue->setAlignment(Qt::AlignCenter);
        AgilityValue->setMaximum(999999);
        AgilityValue->setProperty("fontSize", QVariant(28));
        IntelligenceValue = new QSpinBox(PrimarySkillValues);
        IntelligenceValue->setObjectName(QString::fromUtf8("IntelligenceValue"));
        IntelligenceValue->setGeometry(QRect(211, 0, 89, 35));
        sizePolicy.setHeightForWidth(IntelligenceValue->sizePolicy().hasHeightForWidth());
        IntelligenceValue->setSizePolicy(sizePolicy);
        IntelligenceValue->setMinimumSize(QSize(89, 35));
        IntelligenceValue->setMaximumSize(QSize(89, 35));
        IntelligenceValue->setCursor(QCursor(Qt::IBeamCursor));
        IntelligenceValue->setLayoutDirection(Qt::LeftToRight);
        IntelligenceValue->setStyleSheet(QString::fromUtf8(""));
        IntelligenceValue->setAlignment(Qt::AlignCenter);
        IntelligenceValue->setMaximum(999999);
        IntelligenceValue->setProperty("fontSize", QVariant(28));
        MagicValue = new QSpinBox(PrimarySkillValues);
        MagicValue->setObjectName(QString::fromUtf8("MagicValue"));
        MagicValue->setGeometry(QRect(311, 0, 89, 35));
        sizePolicy.setHeightForWidth(MagicValue->sizePolicy().hasHeightForWidth());
        MagicValue->setSizePolicy(sizePolicy);
        MagicValue->setMinimumSize(QSize(89, 35));
        MagicValue->setMaximumSize(QSize(89, 35));
        MagicValue->setCursor(QCursor(Qt::IBeamCursor));
        MagicValue->setLayoutDirection(Qt::LeftToRight);
        MagicValue->setStyleSheet(QString::fromUtf8(""));
        MagicValue->setAlignment(Qt::AlignCenter);
        MagicValue->setMaximum(999999);
        MagicValue->setProperty("fontSize", QVariant(28));
        BodyTypeValue = new QSpinBox(PrimarySkillValues);
        BodyTypeValue->setObjectName(QString::fromUtf8("BodyTypeValue"));
        BodyTypeValue->setGeometry(QRect(411, 0, 89, 35));
        sizePolicy.setHeightForWidth(BodyTypeValue->sizePolicy().hasHeightForWidth());
        BodyTypeValue->setSizePolicy(sizePolicy);
        BodyTypeValue->setMinimumSize(QSize(89, 35));
        BodyTypeValue->setMaximumSize(QSize(89, 35));
        BodyTypeValue->setCursor(QCursor(Qt::IBeamCursor));
        BodyTypeValue->setLayoutDirection(Qt::LeftToRight);
        BodyTypeValue->setStyleSheet(QString::fromUtf8(""));
        BodyTypeValue->setAlignment(Qt::AlignCenter);
        BodyTypeValue->setMaximum(999999);
        BodyTypeValue->setProperty("fontSize", QVariant(28));
        WillValue = new QSpinBox(PrimarySkillValues);
        WillValue->setObjectName(QString::fromUtf8("WillValue"));
        WillValue->setGeometry(QRect(511, 0, 89, 35));
        sizePolicy.setHeightForWidth(WillValue->sizePolicy().hasHeightForWidth());
        WillValue->setSizePolicy(sizePolicy);
        WillValue->setMinimumSize(QSize(89, 35));
        WillValue->setMaximumSize(QSize(89, 35));
        WillValue->setCursor(QCursor(Qt::IBeamCursor));
        WillValue->setLayoutDirection(Qt::LeftToRight);
        WillValue->setStyleSheet(QString::fromUtf8(""));
        WillValue->setAlignment(Qt::AlignCenter);
        WillValue->setMaximum(999999);
        WillValue->setProperty("fontSize", QVariant(28));
        Separators = new QFrame(ValuesPanel);
        Separators->setObjectName(QString::fromUtf8("Separators"));
        Separators->setGeometry(QRect(0, 0, 611, 41));
        sizePolicy.setHeightForWidth(Separators->sizePolicy().hasHeightForWidth());
        Separators->setSizePolicy(sizePolicy);
        Separators->setMinimumSize(QSize(611, 35));
        Separators->setMaximumSize(QSize(611, 35));
        Separators->setFrameShape(QFrame::StyledPanel);
        Separators->setFrameShadow(QFrame::Raised);
        Separator4 = new QLabel(Separators);
        Separator4->setObjectName(QString::fromUtf8("Separator4"));
        Separator4->setGeometry(QRect(405, 0, 1, 35));
        sizePolicy.setHeightForWidth(Separator4->sizePolicy().hasHeightForWidth());
        Separator4->setSizePolicy(sizePolicy);
        Separator4->setMinimumSize(QSize(1, 35));
        Separator4->setMaximumSize(QSize(1, 35));
        Separator4->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separator1 = new QLabel(Separators);
        Separator1->setObjectName(QString::fromUtf8("Separator1"));
        Separator1->setGeometry(QRect(105, 0, 1, 35));
        sizePolicy.setHeightForWidth(Separator1->sizePolicy().hasHeightForWidth());
        Separator1->setSizePolicy(sizePolicy);
        Separator1->setMinimumSize(QSize(1, 35));
        Separator1->setMaximumSize(QSize(1, 35));
        Separator1->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separator5 = new QLabel(Separators);
        Separator5->setObjectName(QString::fromUtf8("Separator5"));
        Separator5->setGeometry(QRect(505, 0, 1, 35));
        sizePolicy.setHeightForWidth(Separator5->sizePolicy().hasHeightForWidth());
        Separator5->setSizePolicy(sizePolicy);
        Separator5->setMinimumSize(QSize(1, 35));
        Separator5->setMaximumSize(QSize(1, 35));
        Separator5->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separator2 = new QLabel(Separators);
        Separator2->setObjectName(QString::fromUtf8("Separator2"));
        Separator2->setGeometry(QRect(205, 0, 1, 35));
        sizePolicy.setHeightForWidth(Separator2->sizePolicy().hasHeightForWidth());
        Separator2->setSizePolicy(sizePolicy);
        Separator2->setMinimumSize(QSize(1, 35));
        Separator2->setMaximumSize(QSize(1, 35));
        Separator2->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separator3 = new QLabel(Separators);
        Separator3->setObjectName(QString::fromUtf8("Separator3"));
        Separator3->setGeometry(QRect(305, 0, 1, 35));
        sizePolicy.setHeightForWidth(Separator3->sizePolicy().hasHeightForWidth());
        Separator3->setSizePolicy(sizePolicy);
        Separator3->setMinimumSize(QSize(1, 35));
        Separator3->setMaximumSize(QSize(1, 35));
        Separator3->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separators->raise();
        PrimarySkillValues->raise();

        verticalLayout->addWidget(ValuesPanel);


        retranslateUi(CharacterWindow);

        QMetaObject::connectSlotsByName(CharacterWindow);
    } // setupUi

    void retranslateUi(QWidget *CharacterWindow)
    {
        CharacterWindow->setWindowTitle(QCoreApplication::translate("CharacterWindow", "Form", nullptr));
        StrengthPrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\230\320\233\320\220", nullptr)));
        AgilityPrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\233\320\236\320\222\320\232", nullptr)));
        IntelligencePrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\235\320\242", nullptr)));
        MagicPrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\220\320\223", nullptr)));
        BodyTypePrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\225\320\233", nullptr)));
        WillPrimarySkillSignature->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\320\236\320\233\320\257", nullptr)));
        Separator4->setText(QString());
        Separator1->setText(QString());
        Separator5->setText(QString());
        Separator2->setText(QString());
        Separator3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CharacterWindow: public Ui_CharacterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERWINDOW_H

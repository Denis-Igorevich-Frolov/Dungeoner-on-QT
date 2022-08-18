/********************************************************************************
** Form generated from reading UI file 'characterwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERWINDOW_H
#define UI_CHARACTERWINDOW_H

#include <CustomWidgets/MagicDefenseProgressBar/magicdefenseprogressbar.h>
#include <CustomWidgets/PrimarySkillSignature/primaryskillsignature.h>
#include <CustomWidgets/SecondarySkill/secondaryskill.h>
#include <CustomWidgets/SecondarySkillProgressBar/secondaryskillprogressbar.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterWindow
{
public:
    QFrame *TopMenuWrapper;
    QVBoxLayout *verticalLayout_3;
    QFrame *TopMenu;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *TopMenuBorder;
    QFrame *SkillsWraper;
    QVBoxLayout *verticalLayout;
    QFrame *PrimarySkillWrapper;
    QVBoxLayout *PrimarySkillWrapperL;
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
    QFrame *SecondarySkillsWraper;
    QHBoxLayout *horizontalLayout;
    QFrame *ScrollAreaWraper;
    QScrollArea *ScrollAreaSecondarySkills;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *SecondarySkills;
    SecondarySkill *MeleeAccuracy;
    SecondarySkill *ResistMagicDamage;
    SecondarySkill *MagicCastChance;
    SecondarySkill *LoadCapacity;
    SecondarySkill *Attentiveness;
    SecondarySkill *MagicDamage;
    SecondarySkill *Initiative;
    SecondarySkill *ResistPhysicalDamage;
    SecondarySkill *Evasion;
    SecondarySkill *MagicAccuracy;
    SecondarySkill *StrengtheningPhysicalEffects;
    SecondarySkill *ResistPhysicalEffects;
    SecondarySkill *StrengtheningMagicalEffects;
    SecondarySkill *ChanceOfUsingCombatTechnique;
    SecondarySkill *ResistMagicEffects;
    SecondarySkill *RangedAccuracy;
    SecondarySkill *Stealth;
    SecondarySkill *PhysicalDamage;
    SecondarySkill *MoveRange;
    QFrame *SecondarySkillsShadowBottom;
    QFrame *SecondarySkillsShadowTop;
    QScrollBar *verticalScrollBar;
    QFrame *ProgressBars;
    QVBoxLayout *verticalLayout_5;
    SecondarySkillProgressBar *Health;
    SecondarySkillProgressBar *Endurance;
    SecondarySkillProgressBar *Mana;
    MagicDefenseProgressBar *MagicDefense;
    QFrame *BottomBoundWrapper;
    QVBoxLayout *verticalLayout_4;
    QFrame *DecorativeElementWrapper;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *BottomBorder;
    QLabel *BottomBound;

    void setupUi(QWidget *CharacterWindow)
    {
        if (CharacterWindow->objectName().isEmpty())
            CharacterWindow->setObjectName(QString::fromUtf8("CharacterWindow"));
        CharacterWindow->resize(1920, 1080);
        CharacterWindow->setFocusPolicy(Qt::StrongFocus);
        CharacterWindow->setStyleSheet(QString::fromUtf8("#CharacterWindow{\n"
"	background: #130a0f;\n"
"}"));
        TopMenuWrapper = new QFrame(CharacterWindow);
        TopMenuWrapper->setObjectName(QString::fromUtf8("TopMenuWrapper"));
        TopMenuWrapper->setGeometry(QRect(-1, -1, 1922, 89));
        TopMenuWrapper->setStyleSheet(QString::fromUtf8(""));
        TopMenuWrapper->setFrameShape(QFrame::StyledPanel);
        TopMenuWrapper->setFrameShadow(QFrame::Raised);
        TopMenuWrapper->setLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(TopMenuWrapper);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        TopMenu = new QFrame(TopMenuWrapper);
        TopMenu->setObjectName(QString::fromUtf8("TopMenu"));
        TopMenu->setStyleSheet(QString::fromUtf8("Background: black;"));
        TopMenu->setFrameShape(QFrame::StyledPanel);
        TopMenu->setFrameShadow(QFrame::Raised);
        TopMenu->setLineWidth(0);
        pushButton = new QPushButton(TopMenu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 20, 80, 24));
        pushButton->setStyleSheet(QString::fromUtf8("background: white;"));
        pushButton_2 = new QPushButton(TopMenu);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 20, 80, 24));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: white;"));
        pushButton_3 = new QPushButton(TopMenu);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 20, 80, 24));
        pushButton_3->setStyleSheet(QString::fromUtf8("background: white;"));
        pushButton_4 = new QPushButton(TopMenu);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(660, 10, 161, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background:white;"));

        verticalLayout_3->addWidget(TopMenu);

        TopMenuBorder = new QLabel(TopMenuWrapper);
        TopMenuBorder->setObjectName(QString::fromUtf8("TopMenuBorder"));
        TopMenuBorder->setMaximumSize(QSize(16777215, 3));
        TopMenuBorder->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(174, 156, 82, 255), stop:0.337079 rgba(174, 156, 82, 255), stop:0.339799 rgba(190, 195, 64, 255), stop:0.657303 rgba(190, 195, 64, 255), stop:0.662469 rgba(131, 118, 63, 255), stop:1 rgba(131, 118, 63, 255))"));
        TopMenuBorder->setLineWidth(0);

        verticalLayout_3->addWidget(TopMenuBorder);

        SkillsWraper = new QFrame(CharacterWindow);
        SkillsWraper->setObjectName(QString::fromUtf8("SkillsWraper"));
        SkillsWraper->setGeometry(QRect(46, 123, 666, 534));
        SkillsWraper->setFrameShape(QFrame::StyledPanel);
        SkillsWraper->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(SkillsWraper);
        verticalLayout->setSpacing(32);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PrimarySkillWrapper = new QFrame(SkillsWraper);
        PrimarySkillWrapper->setObjectName(QString::fromUtf8("PrimarySkillWrapper"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrimarySkillWrapper->sizePolicy().hasHeightForWidth());
        PrimarySkillWrapper->setSizePolicy(sizePolicy);
        PrimarySkillWrapperL = new QVBoxLayout(PrimarySkillWrapper);
        PrimarySkillWrapperL->setSpacing(0);
        PrimarySkillWrapperL->setObjectName(QString::fromUtf8("PrimarySkillWrapperL"));
        PrimarySkillWrapperL->setContentsMargins(0, 0, 0, 0);
        PrimarySkillSignatures = new QFrame(PrimarySkillWrapper);
        PrimarySkillSignatures->setObjectName(QString::fromUtf8("PrimarySkillSignatures"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PrimarySkillSignatures->sizePolicy().hasHeightForWidth());
        PrimarySkillSignatures->setSizePolicy(sizePolicy1);
        PrimarySkillSignatures->setMinimumSize(QSize(611, 58));
        PrimarySkillSignatures->setMaximumSize(QSize(611, 58));
        PrimarySkillSignatures->setFrameShape(QFrame::StyledPanel);
        PrimarySkillSignatures->setFrameShadow(QFrame::Raised);
        StrengthPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        StrengthPrimarySkillSignature->setObjectName(QString::fromUtf8("StrengthPrimarySkillSignature"));
        StrengthPrimarySkillSignature->setGeometry(QRect(0, 0, 111, 58));
        sizePolicy1.setHeightForWidth(StrengthPrimarySkillSignature->sizePolicy().hasHeightForWidth());
        StrengthPrimarySkillSignature->setSizePolicy(sizePolicy1);
        StrengthPrimarySkillSignature->setMinimumSize(QSize(111, 58));
        StrengthPrimarySkillSignature->setMaximumSize(QSize(111, 58));
        StrengthPrimarySkillSignature->setMouseTracking(false);
        StrengthPrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        AgilityPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        AgilityPrimarySkillSignature->setObjectName(QString::fromUtf8("AgilityPrimarySkillSignature"));
        AgilityPrimarySkillSignature->setGeometry(QRect(100, 0, 111, 58));
        sizePolicy1.setHeightForWidth(AgilityPrimarySkillSignature->sizePolicy().hasHeightForWidth());
        AgilityPrimarySkillSignature->setSizePolicy(sizePolicy1);
        AgilityPrimarySkillSignature->setMinimumSize(QSize(111, 58));
        AgilityPrimarySkillSignature->setMaximumSize(QSize(111, 58));
        AgilityPrimarySkillSignature->setMouseTracking(false);
        AgilityPrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        IntelligencePrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        IntelligencePrimarySkillSignature->setObjectName(QString::fromUtf8("IntelligencePrimarySkillSignature"));
        IntelligencePrimarySkillSignature->setGeometry(QRect(200, 0, 111, 58));
        sizePolicy1.setHeightForWidth(IntelligencePrimarySkillSignature->sizePolicy().hasHeightForWidth());
        IntelligencePrimarySkillSignature->setSizePolicy(sizePolicy1);
        IntelligencePrimarySkillSignature->setMinimumSize(QSize(111, 58));
        IntelligencePrimarySkillSignature->setMaximumSize(QSize(111, 58));
        IntelligencePrimarySkillSignature->setMouseTracking(false);
        IntelligencePrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        MagicPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        MagicPrimarySkillSignature->setObjectName(QString::fromUtf8("MagicPrimarySkillSignature"));
        MagicPrimarySkillSignature->setGeometry(QRect(300, 0, 111, 58));
        sizePolicy1.setHeightForWidth(MagicPrimarySkillSignature->sizePolicy().hasHeightForWidth());
        MagicPrimarySkillSignature->setSizePolicy(sizePolicy1);
        MagicPrimarySkillSignature->setMinimumSize(QSize(111, 58));
        MagicPrimarySkillSignature->setMaximumSize(QSize(111, 58));
        MagicPrimarySkillSignature->setMouseTracking(false);
        MagicPrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        BodyTypePrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        BodyTypePrimarySkillSignature->setObjectName(QString::fromUtf8("BodyTypePrimarySkillSignature"));
        BodyTypePrimarySkillSignature->setGeometry(QRect(400, 0, 111, 58));
        sizePolicy1.setHeightForWidth(BodyTypePrimarySkillSignature->sizePolicy().hasHeightForWidth());
        BodyTypePrimarySkillSignature->setSizePolicy(sizePolicy1);
        BodyTypePrimarySkillSignature->setMinimumSize(QSize(111, 58));
        BodyTypePrimarySkillSignature->setMaximumSize(QSize(111, 58));
        BodyTypePrimarySkillSignature->setMouseTracking(false);
        BodyTypePrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));
        WillPrimarySkillSignature = new PrimarySkillSignature(PrimarySkillSignatures);
        WillPrimarySkillSignature->setObjectName(QString::fromUtf8("WillPrimarySkillSignature"));
        WillPrimarySkillSignature->setGeometry(QRect(500, 0, 111, 58));
        sizePolicy1.setHeightForWidth(WillPrimarySkillSignature->sizePolicy().hasHeightForWidth());
        WillPrimarySkillSignature->setSizePolicy(sizePolicy1);
        WillPrimarySkillSignature->setMinimumSize(QSize(111, 58));
        WillPrimarySkillSignature->setMaximumSize(QSize(111, 58));
        WillPrimarySkillSignature->setMouseTracking(false);
        WillPrimarySkillSignature->setStyleSheet(QString::fromUtf8("background: black;"));

        PrimarySkillWrapperL->addWidget(PrimarySkillSignatures);

        verticalSpacer = new QSpacerItem(608, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        PrimarySkillWrapperL->addItem(verticalSpacer);

        ValuesPanel = new QFrame(PrimarySkillWrapper);
        ValuesPanel->setObjectName(QString::fromUtf8("ValuesPanel"));
        sizePolicy1.setHeightForWidth(ValuesPanel->sizePolicy().hasHeightForWidth());
        ValuesPanel->setSizePolicy(sizePolicy1);
        ValuesPanel->setMinimumSize(QSize(611, 35));
        ValuesPanel->setMaximumSize(QSize(611, 35));
        ValuesPanel->setFrameShape(QFrame::StyledPanel);
        ValuesPanel->setFrameShadow(QFrame::Raised);
        PrimarySkillValues = new QFrame(ValuesPanel);
        PrimarySkillValues->setObjectName(QString::fromUtf8("PrimarySkillValues"));
        PrimarySkillValues->setGeometry(QRect(0, 0, 611, 35));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PrimarySkillValues->sizePolicy().hasHeightForWidth());
        PrimarySkillValues->setSizePolicy(sizePolicy2);
        PrimarySkillValues->setMinimumSize(QSize(0, 35));
        PrimarySkillValues->setMaximumSize(QSize(16777215, 35));
        PrimarySkillValues->setFrameShape(QFrame::StyledPanel);
        PrimarySkillValues->setFrameShadow(QFrame::Raised);
        StrengthValue = new QSpinBox(PrimarySkillValues);
        StrengthValue->setObjectName(QString::fromUtf8("StrengthValue"));
        StrengthValue->setGeometry(QRect(11, 0, 89, 35));
        sizePolicy1.setHeightForWidth(StrengthValue->sizePolicy().hasHeightForWidth());
        StrengthValue->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(AgilityValue->sizePolicy().hasHeightForWidth());
        AgilityValue->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(IntelligenceValue->sizePolicy().hasHeightForWidth());
        IntelligenceValue->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(MagicValue->sizePolicy().hasHeightForWidth());
        MagicValue->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(BodyTypeValue->sizePolicy().hasHeightForWidth());
        BodyTypeValue->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(WillValue->sizePolicy().hasHeightForWidth());
        WillValue->setSizePolicy(sizePolicy1);
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
        Separators->setGeometry(QRect(0, 0, 611, 35));
        sizePolicy1.setHeightForWidth(Separators->sizePolicy().hasHeightForWidth());
        Separators->setSizePolicy(sizePolicy1);
        Separators->setMinimumSize(QSize(611, 35));
        Separators->setMaximumSize(QSize(611, 35));
        Separators->setFrameShape(QFrame::StyledPanel);
        Separators->setFrameShadow(QFrame::Raised);
        Separator4 = new QLabel(Separators);
        Separator4->setObjectName(QString::fromUtf8("Separator4"));
        Separator4->setGeometry(QRect(405, 0, 1, 35));
        sizePolicy1.setHeightForWidth(Separator4->sizePolicy().hasHeightForWidth());
        Separator4->setSizePolicy(sizePolicy1);
        Separator4->setMinimumSize(QSize(1, 35));
        Separator4->setMaximumSize(QSize(1, 35));
        Separator4->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separator1 = new QLabel(Separators);
        Separator1->setObjectName(QString::fromUtf8("Separator1"));
        Separator1->setGeometry(QRect(105, 0, 1, 35));
        sizePolicy1.setHeightForWidth(Separator1->sizePolicy().hasHeightForWidth());
        Separator1->setSizePolicy(sizePolicy1);
        Separator1->setMinimumSize(QSize(1, 35));
        Separator1->setMaximumSize(QSize(1, 35));
        Separator1->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separator5 = new QLabel(Separators);
        Separator5->setObjectName(QString::fromUtf8("Separator5"));
        Separator5->setGeometry(QRect(505, 0, 1, 35));
        sizePolicy1.setHeightForWidth(Separator5->sizePolicy().hasHeightForWidth());
        Separator5->setSizePolicy(sizePolicy1);
        Separator5->setMinimumSize(QSize(1, 35));
        Separator5->setMaximumSize(QSize(1, 35));
        Separator5->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separator2 = new QLabel(Separators);
        Separator2->setObjectName(QString::fromUtf8("Separator2"));
        Separator2->setGeometry(QRect(205, 0, 1, 35));
        sizePolicy1.setHeightForWidth(Separator2->sizePolicy().hasHeightForWidth());
        Separator2->setSizePolicy(sizePolicy1);
        Separator2->setMinimumSize(QSize(1, 35));
        Separator2->setMaximumSize(QSize(1, 35));
        Separator2->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separator3 = new QLabel(Separators);
        Separator3->setObjectName(QString::fromUtf8("Separator3"));
        Separator3->setGeometry(QRect(305, 0, 1, 35));
        sizePolicy1.setHeightForWidth(Separator3->sizePolicy().hasHeightForWidth());
        Separator3->setSizePolicy(sizePolicy1);
        Separator3->setMinimumSize(QSize(1, 35));
        Separator3->setMaximumSize(QSize(1, 35));
        Separator3->setStyleSheet(QString::fromUtf8("background:  #50541a;"));
        Separators->raise();
        PrimarySkillValues->raise();

        PrimarySkillWrapperL->addWidget(ValuesPanel);


        verticalLayout->addWidget(PrimarySkillWrapper, 0, Qt::AlignLeft);

        SecondarySkillsWraper = new QFrame(SkillsWraper);
        SecondarySkillsWraper->setObjectName(QString::fromUtf8("SecondarySkillsWraper"));
        SecondarySkillsWraper->setFrameShape(QFrame::StyledPanel);
        SecondarySkillsWraper->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(SecondarySkillsWraper);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ScrollAreaWraper = new QFrame(SecondarySkillsWraper);
        ScrollAreaWraper->setObjectName(QString::fromUtf8("ScrollAreaWraper"));
        ScrollAreaWraper->setMinimumSize(QSize(0, 395));
        ScrollAreaWraper->setFrameShape(QFrame::StyledPanel);
        ScrollAreaWraper->setFrameShadow(QFrame::Raised);
        ScrollAreaWraper->setLineWidth(0);
        ScrollAreaSecondarySkills = new QScrollArea(ScrollAreaWraper);
        ScrollAreaSecondarySkills->setObjectName(QString::fromUtf8("ScrollAreaSecondarySkills"));
        ScrollAreaSecondarySkills->setGeometry(QRect(0, 0, 616, 395));
        ScrollAreaSecondarySkills->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        ScrollAreaSecondarySkills->setLineWidth(0);
        ScrollAreaSecondarySkills->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ScrollAreaSecondarySkills->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ScrollAreaSecondarySkills->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        ScrollAreaSecondarySkills->setWidgetResizable(true);
        ScrollAreaSecondarySkills->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 616, 774));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        SecondarySkills = new QGridLayout();
        SecondarySkills->setSpacing(8);
        SecondarySkills->setObjectName(QString::fromUtf8("SecondarySkills"));
        SecondarySkills->setSizeConstraint(QLayout::SetDefaultConstraint);
        MeleeAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        MeleeAccuracy->setObjectName(QString::fromUtf8("MeleeAccuracy"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(MeleeAccuracy->sizePolicy().hasHeightForWidth());
        MeleeAccuracy->setSizePolicy(sizePolicy3);
        MeleeAccuracy->setMinimumSize(QSize(303, 70));
        MeleeAccuracy->setMaximumSize(QSize(303, 70));
        MeleeAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        MeleeAccuracy->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(MeleeAccuracy, 4, 0, 1, 1);

        ResistMagicDamage = new SecondarySkill(scrollAreaWidgetContents);
        ResistMagicDamage->setObjectName(QString::fromUtf8("ResistMagicDamage"));
        sizePolicy3.setHeightForWidth(ResistMagicDamage->sizePolicy().hasHeightForWidth());
        ResistMagicDamage->setSizePolicy(sizePolicy3);
        ResistMagicDamage->setMinimumSize(QSize(303, 70));
        ResistMagicDamage->setMaximumSize(QSize(303, 70));
        ResistMagicDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistMagicDamage->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistMagicDamage, 1, 1, 1, 1);

        MagicCastChance = new SecondarySkill(scrollAreaWidgetContents);
        MagicCastChance->setObjectName(QString::fromUtf8("MagicCastChance"));
        sizePolicy3.setHeightForWidth(MagicCastChance->sizePolicy().hasHeightForWidth());
        MagicCastChance->setSizePolicy(sizePolicy3);
        MagicCastChance->setMinimumSize(QSize(303, 70));
        MagicCastChance->setMaximumSize(QSize(303, 70));
        MagicCastChance->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicCastChance->setProperty("FontSize", QVariant(16));

        SecondarySkills->addWidget(MagicCastChance, 8, 0, 1, 1);

        LoadCapacity = new SecondarySkill(scrollAreaWidgetContents);
        LoadCapacity->setObjectName(QString::fromUtf8("LoadCapacity"));
        sizePolicy3.setHeightForWidth(LoadCapacity->sizePolicy().hasHeightForWidth());
        LoadCapacity->setSizePolicy(sizePolicy3);
        LoadCapacity->setMinimumSize(QSize(303, 70));
        LoadCapacity->setMaximumSize(QSize(303, 70));
        LoadCapacity->setStyleSheet(QString::fromUtf8("background:black;"));
        LoadCapacity->setProperty("FontSize", QVariant(16));

        SecondarySkills->addWidget(LoadCapacity, 7, 0, 1, 1);

        Attentiveness = new SecondarySkill(scrollAreaWidgetContents);
        Attentiveness->setObjectName(QString::fromUtf8("Attentiveness"));
        sizePolicy3.setHeightForWidth(Attentiveness->sizePolicy().hasHeightForWidth());
        Attentiveness->setSizePolicy(sizePolicy3);
        Attentiveness->setMinimumSize(QSize(303, 70));
        Attentiveness->setMaximumSize(QSize(303, 70));
        Attentiveness->setStyleSheet(QString::fromUtf8("background:black;"));
        Attentiveness->setProperty("FontSize", QVariant(17));

        SecondarySkills->addWidget(Attentiveness, 6, 1, 1, 1);

        MagicDamage = new SecondarySkill(scrollAreaWidgetContents);
        MagicDamage->setObjectName(QString::fromUtf8("MagicDamage"));
        sizePolicy3.setHeightForWidth(MagicDamage->sizePolicy().hasHeightForWidth());
        MagicDamage->setSizePolicy(sizePolicy3);
        MagicDamage->setMinimumSize(QSize(303, 70));
        MagicDamage->setMaximumSize(QSize(303, 70));
        MagicDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicDamage->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(MagicDamage, 0, 1, 1, 1);

        Initiative = new SecondarySkill(scrollAreaWidgetContents);
        Initiative->setObjectName(QString::fromUtf8("Initiative"));
        sizePolicy3.setHeightForWidth(Initiative->sizePolicy().hasHeightForWidth());
        Initiative->setSizePolicy(sizePolicy3);
        Initiative->setMinimumSize(QSize(303, 70));
        Initiative->setMaximumSize(QSize(303, 70));
        Initiative->setStyleSheet(QString::fromUtf8("background:black;"));
        Initiative->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(Initiative, 7, 1, 1, 1);

        ResistPhysicalDamage = new SecondarySkill(scrollAreaWidgetContents);
        ResistPhysicalDamage->setObjectName(QString::fromUtf8("ResistPhysicalDamage"));
        sizePolicy3.setHeightForWidth(ResistPhysicalDamage->sizePolicy().hasHeightForWidth());
        ResistPhysicalDamage->setSizePolicy(sizePolicy3);
        ResistPhysicalDamage->setMinimumSize(QSize(303, 70));
        ResistPhysicalDamage->setMaximumSize(QSize(303, 70));
        ResistPhysicalDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistPhysicalDamage->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistPhysicalDamage, 1, 0, 1, 1);

        Evasion = new SecondarySkill(scrollAreaWidgetContents);
        Evasion->setObjectName(QString::fromUtf8("Evasion"));
        sizePolicy3.setHeightForWidth(Evasion->sizePolicy().hasHeightForWidth());
        Evasion->setSizePolicy(sizePolicy3);
        Evasion->setMinimumSize(QSize(303, 70));
        Evasion->setMaximumSize(QSize(303, 70));
        Evasion->setStyleSheet(QString::fromUtf8("background:black;"));
        Evasion->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(Evasion, 5, 1, 1, 1);

        MagicAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        MagicAccuracy->setObjectName(QString::fromUtf8("MagicAccuracy"));
        sizePolicy3.setHeightForWidth(MagicAccuracy->sizePolicy().hasHeightForWidth());
        MagicAccuracy->setSizePolicy(sizePolicy3);
        MagicAccuracy->setMinimumSize(QSize(303, 70));
        MagicAccuracy->setMaximumSize(QSize(303, 70));
        MagicAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicAccuracy->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(MagicAccuracy, 5, 0, 1, 1);

        StrengtheningPhysicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        StrengtheningPhysicalEffects->setObjectName(QString::fromUtf8("StrengtheningPhysicalEffects"));
        sizePolicy3.setHeightForWidth(StrengtheningPhysicalEffects->sizePolicy().hasHeightForWidth());
        StrengtheningPhysicalEffects->setSizePolicy(sizePolicy3);
        StrengtheningPhysicalEffects->setMinimumSize(QSize(303, 70));
        StrengtheningPhysicalEffects->setMaximumSize(QSize(303, 70));
        StrengtheningPhysicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        StrengtheningPhysicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(StrengtheningPhysicalEffects, 3, 0, 1, 1);

        ResistPhysicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        ResistPhysicalEffects->setObjectName(QString::fromUtf8("ResistPhysicalEffects"));
        sizePolicy3.setHeightForWidth(ResistPhysicalEffects->sizePolicy().hasHeightForWidth());
        ResistPhysicalEffects->setSizePolicy(sizePolicy3);
        ResistPhysicalEffects->setMinimumSize(QSize(303, 70));
        ResistPhysicalEffects->setMaximumSize(QSize(303, 70));
        ResistPhysicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistPhysicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistPhysicalEffects, 2, 0, 1, 1);

        StrengtheningMagicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        StrengtheningMagicalEffects->setObjectName(QString::fromUtf8("StrengtheningMagicalEffects"));
        sizePolicy3.setHeightForWidth(StrengtheningMagicalEffects->sizePolicy().hasHeightForWidth());
        StrengtheningMagicalEffects->setSizePolicy(sizePolicy3);
        StrengtheningMagicalEffects->setMinimumSize(QSize(303, 70));
        StrengtheningMagicalEffects->setMaximumSize(QSize(303, 70));
        StrengtheningMagicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        StrengtheningMagicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(StrengtheningMagicalEffects, 3, 1, 1, 1);

        ChanceOfUsingCombatTechnique = new SecondarySkill(scrollAreaWidgetContents);
        ChanceOfUsingCombatTechnique->setObjectName(QString::fromUtf8("ChanceOfUsingCombatTechnique"));
        sizePolicy3.setHeightForWidth(ChanceOfUsingCombatTechnique->sizePolicy().hasHeightForWidth());
        ChanceOfUsingCombatTechnique->setSizePolicy(sizePolicy3);
        ChanceOfUsingCombatTechnique->setMinimumSize(QSize(303, 70));
        ChanceOfUsingCombatTechnique->setMaximumSize(QSize(303, 70));
        ChanceOfUsingCombatTechnique->setStyleSheet(QString::fromUtf8("background:black;"));
        ChanceOfUsingCombatTechnique->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ChanceOfUsingCombatTechnique, 8, 1, 1, 1);

        ResistMagicEffects = new SecondarySkill(scrollAreaWidgetContents);
        ResistMagicEffects->setObjectName(QString::fromUtf8("ResistMagicEffects"));
        sizePolicy3.setHeightForWidth(ResistMagicEffects->sizePolicy().hasHeightForWidth());
        ResistMagicEffects->setSizePolicy(sizePolicy3);
        ResistMagicEffects->setMinimumSize(QSize(303, 70));
        ResistMagicEffects->setMaximumSize(QSize(303, 70));
        ResistMagicEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistMagicEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistMagicEffects, 2, 1, 1, 1);

        RangedAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        RangedAccuracy->setObjectName(QString::fromUtf8("RangedAccuracy"));
        sizePolicy3.setHeightForWidth(RangedAccuracy->sizePolicy().hasHeightForWidth());
        RangedAccuracy->setSizePolicy(sizePolicy3);
        RangedAccuracy->setMinimumSize(QSize(303, 70));
        RangedAccuracy->setMaximumSize(QSize(303, 70));
        RangedAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        RangedAccuracy->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(RangedAccuracy, 4, 1, 1, 1);

        Stealth = new SecondarySkill(scrollAreaWidgetContents);
        Stealth->setObjectName(QString::fromUtf8("Stealth"));
        sizePolicy3.setHeightForWidth(Stealth->sizePolicy().hasHeightForWidth());
        Stealth->setSizePolicy(sizePolicy3);
        Stealth->setMinimumSize(QSize(303, 70));
        Stealth->setMaximumSize(QSize(303, 70));
        Stealth->setStyleSheet(QString::fromUtf8("background:black;"));
        Stealth->setProperty("FontSize", QVariant(20));

        SecondarySkills->addWidget(Stealth, 6, 0, 1, 1);

        PhysicalDamage = new SecondarySkill(scrollAreaWidgetContents);
        PhysicalDamage->setObjectName(QString::fromUtf8("PhysicalDamage"));
        sizePolicy3.setHeightForWidth(PhysicalDamage->sizePolicy().hasHeightForWidth());
        PhysicalDamage->setSizePolicy(sizePolicy3);
        PhysicalDamage->setMinimumSize(QSize(303, 70));
        PhysicalDamage->setMaximumSize(QSize(303, 70));
        PhysicalDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        PhysicalDamage->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(PhysicalDamage, 0, 0, 1, 1);

        MoveRange = new SecondarySkill(scrollAreaWidgetContents);
        MoveRange->setObjectName(QString::fromUtf8("MoveRange"));
        sizePolicy3.setHeightForWidth(MoveRange->sizePolicy().hasHeightForWidth());
        MoveRange->setSizePolicy(sizePolicy3);
        MoveRange->setMinimumSize(QSize(303, 70));
        MoveRange->setMaximumSize(QSize(303, 70));
        MoveRange->setStyleSheet(QString::fromUtf8("background:black;"));
        MoveRange->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(MoveRange, 9, 0, 1, 1, Qt::AlignLeft);


        verticalLayout_2->addLayout(SecondarySkills);

        ScrollAreaSecondarySkills->setWidget(scrollAreaWidgetContents);
        SecondarySkillsShadowBottom = new QFrame(ScrollAreaWraper);
        SecondarySkillsShadowBottom->setObjectName(QString::fromUtf8("SecondarySkillsShadowBottom"));
        SecondarySkillsShadowBottom->setEnabled(false);
        SecondarySkillsShadowBottom->setGeometry(QRect(0, 387, 616, 7));
        SecondarySkillsShadowBottom->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(0, 0, 0, 165))"));
        SecondarySkillsShadowBottom->setFrameShape(QFrame::StyledPanel);
        SecondarySkillsShadowBottom->setFrameShadow(QFrame::Raised);
        SecondarySkillsShadowTop = new QFrame(ScrollAreaWraper);
        SecondarySkillsShadowTop->setObjectName(QString::fromUtf8("SecondarySkillsShadowTop"));
        SecondarySkillsShadowTop->setEnabled(false);
        SecondarySkillsShadowTop->setGeometry(QRect(0, 0, 616, 7));
        SecondarySkillsShadowTop->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 162), stop:1 rgba(255, 255, 255, 0))"));
        SecondarySkillsShadowTop->setFrameShape(QFrame::StyledPanel);
        SecondarySkillsShadowTop->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(ScrollAreaWraper);

        verticalScrollBar = new QScrollBar(SecondarySkillsWraper);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setMaximumSize(QSize(16777215, 340));
        verticalScrollBar->setCursor(QCursor(Qt::PointingHandCursor));
        verticalScrollBar->setStyleSheet(QString::fromUtf8(""));
        verticalScrollBar->setMaximum(377);
        verticalScrollBar->setSingleStep(76);
        verticalScrollBar->setPageStep(18);
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalScrollBar);


        verticalLayout->addWidget(SecondarySkillsWraper);

        ProgressBars = new QFrame(CharacterWindow);
        ProgressBars->setObjectName(QString::fromUtf8("ProgressBars"));
        ProgressBars->setGeometry(QRect(48, 685, 736, 361));
        ProgressBars->setFrameShape(QFrame::StyledPanel);
        ProgressBars->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(ProgressBars);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        Health = new SecondarySkillProgressBar(ProgressBars);
        Health->setObjectName(QString::fromUtf8("Health"));
        Health->setMinimumSize(QSize(734, 87));
        Health->setMaximumSize(QSize(734, 87));

        verticalLayout_5->addWidget(Health);

        Endurance = new SecondarySkillProgressBar(ProgressBars);
        Endurance->setObjectName(QString::fromUtf8("Endurance"));
        Endurance->setMinimumSize(QSize(734, 87));
        Endurance->setMaximumSize(QSize(734, 87));

        verticalLayout_5->addWidget(Endurance);

        Mana = new SecondarySkillProgressBar(ProgressBars);
        Mana->setObjectName(QString::fromUtf8("Mana"));
        Mana->setMinimumSize(QSize(734, 87));
        Mana->setMaximumSize(QSize(734, 87));

        verticalLayout_5->addWidget(Mana);

        MagicDefense = new MagicDefenseProgressBar(ProgressBars);
        MagicDefense->setObjectName(QString::fromUtf8("MagicDefense"));
        MagicDefense->setMinimumSize(QSize(734, 80));
        MagicDefense->setMaximumSize(QSize(734, 80));

        verticalLayout_5->addWidget(MagicDefense);

        BottomBoundWrapper = new QFrame(CharacterWindow);
        BottomBoundWrapper->setObjectName(QString::fromUtf8("BottomBoundWrapper"));
        BottomBoundWrapper->setGeometry(QRect(-1, 1045, 1922, 37));
        BottomBoundWrapper->setFrameShape(QFrame::StyledPanel);
        BottomBoundWrapper->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(BottomBoundWrapper);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        DecorativeElementWrapper = new QFrame(BottomBoundWrapper);
        DecorativeElementWrapper->setObjectName(QString::fromUtf8("DecorativeElementWrapper"));
        DecorativeElementWrapper->setMinimumSize(QSize(0, 10));
        DecorativeElementWrapper->setMaximumSize(QSize(16777215, 10));
        DecorativeElementWrapper->setFrameShape(QFrame::StyledPanel);
        DecorativeElementWrapper->setFrameShadow(QFrame::Raised);
        label = new QLabel(DecorativeElementWrapper);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 0, 43, 10));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/Text-Block-1/Textures PNG/DecorativeElement-1-L.png);"));
        label_2 = new QLabel(DecorativeElementWrapper);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(776, 0, 43, 10));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Text-Block-1/Textures PNG/DecorativeElement-1-R.png);"));
        label_3 = new QLabel(DecorativeElementWrapper);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1868, 0, 43, 10));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/Text-Block-1/Textures PNG/DecorativeElement-1-R.png);"));
        label_4 = new QLabel(DecorativeElementWrapper);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1101, 0, 43, 10));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/Text-Block-1/Textures PNG/DecorativeElement-1-L.png);"));

        verticalLayout_4->addWidget(DecorativeElementWrapper);

        BottomBorder = new QLabel(BottomBoundWrapper);
        BottomBorder->setObjectName(QString::fromUtf8("BottomBorder"));
        BottomBorder->setMinimumSize(QSize(0, 3));
        BottomBorder->setMaximumSize(QSize(16777215, 3));
        BottomBorder->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(174, 156, 82, 255), stop:0.337079 rgba(174, 156, 82, 255), stop:0.339799 rgba(190, 195, 64, 255), stop:0.657303 rgba(190, 195, 64, 255), stop:0.662469 rgba(131, 118, 63, 255), stop:1 rgba(131, 118, 63, 255))"));

        verticalLayout_4->addWidget(BottomBorder);

        BottomBound = new QLabel(BottomBoundWrapper);
        BottomBound->setObjectName(QString::fromUtf8("BottomBound"));
        BottomBound->setMinimumSize(QSize(0, 23));
        BottomBound->setMaximumSize(QSize(16777215, 23));
        BottomBound->setStyleSheet(QString::fromUtf8("background: black;"));

        verticalLayout_4->addWidget(BottomBound);

        TopMenuWrapper->raise();
        SkillsWraper->raise();
        BottomBoundWrapper->raise();
        ProgressBars->raise();

        retranslateUi(CharacterWindow);

        QMetaObject::connectSlotsByName(CharacterWindow);
    } // setupUi

    void retranslateUi(QWidget *CharacterWindow)
    {
        CharacterWindow->setWindowTitle(QCoreApplication::translate("CharacterWindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("CharacterWindow", "\320\241\320\270\320\273\320\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CharacterWindow", "\320\233\320\276\320\262\320\272\320\276\321\201\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\263\320\270\321\217", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CharacterWindow", "\320\227\320\260\321\205\320\270\320\273\321\217\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\265\321\201\321\201\320\261\320\260\321\200\321\213", nullptr));
        TopMenuBorder->setText(QString());
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
        MeleeAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\261\320\273\320\270\320\266\320\275\320\265\320\263\320\276 \320\261\320\276\321\217", nullptr)));
        ResistMagicDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\203\321\200\320\276\320\275\321\203", nullptr)));
        MagicCastChance->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \321\201\320\276\321\202\320\262\320\276\321\200\320\265\320\275\320\270\321\217 \320\274\320\260\320\263\320\270\320\270", nullptr)));
        LoadCapacity->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\223\321\200\321\203\320\267\320\276\320\277\320\276\320\264\321\212\321\221\320\274\320\275\320\276\321\201\321\202\321\214", nullptr)));
        Attentiveness->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\320\275\320\270\320\274\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr)));
        MagicDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\203\321\200\320\276\320\275", nullptr)));
        Initiative->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\275\320\270\321\206\320\270\320\260\321\202\320\270\320\262\320\260", nullptr)));
        ResistPhysicalDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\203\321\200\320\276\320\275\321\203", nullptr)));
        Evasion->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265", nullptr)));
        MagicAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\274\320\260\320\263\320\270\320\270", nullptr)));
        StrengtheningPhysicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\321\201\320\270\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\215\321\204\321\204\320\265\320\272\321\202\320\276\320\262", nullptr)));
        ResistPhysicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\215\321\204\321\204\320\265\320\272\321\202\320\260\320\274", nullptr)));
        StrengtheningMagicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\321\201\320\270\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\215\321\204\321\204\320\265\320\272\321\202\320\276\320\262", nullptr)));
        ChanceOfUsingCombatTechnique->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \320\261\320\276\320\265\320\262\320\276\320\263\320\276  \320\277\321\200\320\270\321\221\320\274\320\260", nullptr)));
        ResistMagicEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\215\321\204\321\204\320\265\320\272\321\202\320\260\320\274", nullptr)));
        RangedAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\264\320\260\320\273\321\214\320\275\320\265\320\263\320\276 \320\261\320\276\321\217", nullptr)));
        Stealth->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\272\321\200\321\213\321\202\320\275\320\276\321\201\321\202\321\214", nullptr)));
        PhysicalDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\244\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\203\321\200\320\276\320\275", nullptr)));
        MoveRange->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\224\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", nullptr)));
        Health->setProperty("Color", QVariant(QCoreApplication::translate("CharacterWindow", "#dc0000", nullptr)));
        Health->setProperty("Name", QVariant(QCoreApplication::translate("CharacterWindow", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr)));
        Endurance->setProperty("Color", QVariant(QCoreApplication::translate("CharacterWindow", "#0fcd00", nullptr)));
        Endurance->setProperty("Name", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\321\213\320\275\320\276\321\201\320\273\320\270\320\262\320\276\321\201\321\202\321\214", nullptr)));
        Mana->setProperty("Color", QVariant(QCoreApplication::translate("CharacterWindow", "#1e55ff", nullptr)));
        Mana->setProperty("Name", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\275\320\260", nullptr)));
        MagicDefense->setProperty("Color", QVariant(QCoreApplication::translate("CharacterWindow", "#9e17cf", nullptr)));
        MagicDefense->setProperty("Name", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\267\320\260\321\211\320\270\321\202\320\260", nullptr)));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        BottomBorder->setText(QString());
        BottomBound->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CharacterWindow: public Ui_CharacterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERWINDOW_H

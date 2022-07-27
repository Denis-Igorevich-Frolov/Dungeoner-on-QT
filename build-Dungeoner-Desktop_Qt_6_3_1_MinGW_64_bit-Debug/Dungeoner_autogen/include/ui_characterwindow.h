/********************************************************************************
** Form generated from reading UI file 'characterwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERWINDOW_H
#define UI_CHARACTERWINDOW_H

#include <CustomWidgets/PrimarySkillSignature/primaryskillsignature.h>
#include <CustomWidgets/SecondarySkill/secondaryskill.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *ScrollAreaWraper;
    QScrollArea *ScrollAreaSecondarySkills;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *SecondarySkills;
    SecondarySkill *MagicTechniqueCastChance;
    SecondarySkill *Stealth;
    SecondarySkill *ResistPhysicalEffects;
    SecondarySkill *MagicAccuracy;
    SecondarySkill *ResistMagicDamage;
    SecondarySkill *MagicCastChance;
    SecondarySkill *ResistMagicEffects;
    SecondarySkill *LoadCapacity;
    SecondarySkill *ResistPhysicalDamage;
    SecondarySkill *Evasion;
    SecondarySkill *Initiative;
    SecondarySkill *ChanceToUseCombat;
    SecondarySkill *Attentiveness;
    SecondarySkill *PhysicalDamage;
    SecondarySkill *StrengtheningMagicalEffects;
    SecondarySkill *RangedAccuracy;
    SecondarySkill *MagicDamage;
    SecondarySkill *TravelRange;
    SecondarySkill *StrengtheningPhysicalEffects;
    SecondarySkill *MeleeAccuracy;
    QFrame *SecondarySkillsShadowBottom;
    QFrame *SecondarySkillsShadowTop;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *CharacterWindow)
    {
        if (CharacterWindow->objectName().isEmpty())
            CharacterWindow->setObjectName(QString::fromUtf8("CharacterWindow"));
        CharacterWindow->resize(1186, 646);
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
        Separators->setGeometry(QRect(0, 0, 611, 35));
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

        frame = new QFrame(CharacterWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(130, 220, 666, 395));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ScrollAreaWraper = new QFrame(frame);
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
        MagicTechniqueCastChance = new SecondarySkill(scrollAreaWidgetContents);
        MagicTechniqueCastChance->setObjectName(QString::fromUtf8("MagicTechniqueCastChance"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MagicTechniqueCastChance->sizePolicy().hasHeightForWidth());
        MagicTechniqueCastChance->setSizePolicy(sizePolicy2);
        MagicTechniqueCastChance->setMinimumSize(QSize(303, 70));
        MagicTechniqueCastChance->setMaximumSize(QSize(303, 70));
        MagicTechniqueCastChance->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicTechniqueCastChance->setProperty("FontSize", QVariant(16));

        SecondarySkills->addWidget(MagicTechniqueCastChance, 9, 0, 1, 1);

        Stealth = new SecondarySkill(scrollAreaWidgetContents);
        Stealth->setObjectName(QString::fromUtf8("Stealth"));
        sizePolicy2.setHeightForWidth(Stealth->sizePolicy().hasHeightForWidth());
        Stealth->setSizePolicy(sizePolicy2);
        Stealth->setMinimumSize(QSize(303, 70));
        Stealth->setMaximumSize(QSize(303, 70));
        Stealth->setStyleSheet(QString::fromUtf8("background:black;"));
        Stealth->setProperty("FontSize", QVariant(25));

        SecondarySkills->addWidget(Stealth, 6, 0, 1, 1);

        ResistPhysicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        ResistPhysicalEffects->setObjectName(QString::fromUtf8("ResistPhysicalEffects"));
        sizePolicy2.setHeightForWidth(ResistPhysicalEffects->sizePolicy().hasHeightForWidth());
        ResistPhysicalEffects->setSizePolicy(sizePolicy2);
        ResistPhysicalEffects->setMinimumSize(QSize(303, 70));
        ResistPhysicalEffects->setMaximumSize(QSize(303, 70));
        ResistPhysicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistPhysicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistPhysicalEffects, 2, 0, 1, 1);

        MagicAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        MagicAccuracy->setObjectName(QString::fromUtf8("MagicAccuracy"));
        sizePolicy2.setHeightForWidth(MagicAccuracy->sizePolicy().hasHeightForWidth());
        MagicAccuracy->setSizePolicy(sizePolicy2);
        MagicAccuracy->setMinimumSize(QSize(303, 70));
        MagicAccuracy->setMaximumSize(QSize(303, 70));
        MagicAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicAccuracy->setProperty("FontSize", QVariant(22));

        SecondarySkills->addWidget(MagicAccuracy, 5, 0, 1, 1);

        ResistMagicDamage = new SecondarySkill(scrollAreaWidgetContents);
        ResistMagicDamage->setObjectName(QString::fromUtf8("ResistMagicDamage"));
        sizePolicy2.setHeightForWidth(ResistMagicDamage->sizePolicy().hasHeightForWidth());
        ResistMagicDamage->setSizePolicy(sizePolicy2);
        ResistMagicDamage->setMinimumSize(QSize(303, 70));
        ResistMagicDamage->setMaximumSize(QSize(303, 70));
        ResistMagicDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistMagicDamage->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistMagicDamage, 1, 1, 1, 1);

        MagicCastChance = new SecondarySkill(scrollAreaWidgetContents);
        MagicCastChance->setObjectName(QString::fromUtf8("MagicCastChance"));
        sizePolicy2.setHeightForWidth(MagicCastChance->sizePolicy().hasHeightForWidth());
        MagicCastChance->setSizePolicy(sizePolicy2);
        MagicCastChance->setMinimumSize(QSize(303, 70));
        MagicCastChance->setMaximumSize(QSize(303, 70));
        MagicCastChance->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicCastChance->setProperty("FontSize", QVariant(16));

        SecondarySkills->addWidget(MagicCastChance, 8, 0, 1, 1);

        ResistMagicEffects = new SecondarySkill(scrollAreaWidgetContents);
        ResistMagicEffects->setObjectName(QString::fromUtf8("ResistMagicEffects"));
        sizePolicy2.setHeightForWidth(ResistMagicEffects->sizePolicy().hasHeightForWidth());
        ResistMagicEffects->setSizePolicy(sizePolicy2);
        ResistMagicEffects->setMinimumSize(QSize(303, 70));
        ResistMagicEffects->setMaximumSize(QSize(303, 70));
        ResistMagicEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistMagicEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistMagicEffects, 2, 1, 1, 1);

        LoadCapacity = new SecondarySkill(scrollAreaWidgetContents);
        LoadCapacity->setObjectName(QString::fromUtf8("LoadCapacity"));
        sizePolicy2.setHeightForWidth(LoadCapacity->sizePolicy().hasHeightForWidth());
        LoadCapacity->setSizePolicy(sizePolicy2);
        LoadCapacity->setMinimumSize(QSize(303, 70));
        LoadCapacity->setMaximumSize(QSize(303, 70));
        LoadCapacity->setStyleSheet(QString::fromUtf8("background:black;"));
        LoadCapacity->setProperty("FontSize", QVariant(16));

        SecondarySkills->addWidget(LoadCapacity, 7, 0, 1, 1);

        ResistPhysicalDamage = new SecondarySkill(scrollAreaWidgetContents);
        ResistPhysicalDamage->setObjectName(QString::fromUtf8("ResistPhysicalDamage"));
        sizePolicy2.setHeightForWidth(ResistPhysicalDamage->sizePolicy().hasHeightForWidth());
        ResistPhysicalDamage->setSizePolicy(sizePolicy2);
        ResistPhysicalDamage->setMinimumSize(QSize(303, 70));
        ResistPhysicalDamage->setMaximumSize(QSize(303, 70));
        ResistPhysicalDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistPhysicalDamage->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistPhysicalDamage, 1, 0, 1, 1);

        Evasion = new SecondarySkill(scrollAreaWidgetContents);
        Evasion->setObjectName(QString::fromUtf8("Evasion"));
        sizePolicy2.setHeightForWidth(Evasion->sizePolicy().hasHeightForWidth());
        Evasion->setSizePolicy(sizePolicy2);
        Evasion->setMinimumSize(QSize(303, 70));
        Evasion->setMaximumSize(QSize(303, 70));
        Evasion->setStyleSheet(QString::fromUtf8("background:black;"));
        Evasion->setProperty("FontSize", QVariant(25));

        SecondarySkills->addWidget(Evasion, 5, 1, 1, 1);

        Initiative = new SecondarySkill(scrollAreaWidgetContents);
        Initiative->setObjectName(QString::fromUtf8("Initiative"));
        sizePolicy2.setHeightForWidth(Initiative->sizePolicy().hasHeightForWidth());
        Initiative->setSizePolicy(sizePolicy2);
        Initiative->setMinimumSize(QSize(303, 70));
        Initiative->setMaximumSize(QSize(303, 70));
        Initiative->setStyleSheet(QString::fromUtf8("background:black;"));
        Initiative->setProperty("FontSize", QVariant(24));

        SecondarySkills->addWidget(Initiative, 7, 1, 1, 1);

        ChanceToUseCombat = new SecondarySkill(scrollAreaWidgetContents);
        ChanceToUseCombat->setObjectName(QString::fromUtf8("ChanceToUseCombat"));
        sizePolicy2.setHeightForWidth(ChanceToUseCombat->sizePolicy().hasHeightForWidth());
        ChanceToUseCombat->setSizePolicy(sizePolicy2);
        ChanceToUseCombat->setMinimumSize(QSize(303, 70));
        ChanceToUseCombat->setMaximumSize(QSize(303, 70));
        ChanceToUseCombat->setStyleSheet(QString::fromUtf8("background:black;"));
        ChanceToUseCombat->setProperty("FontSize", QVariant(16));

        SecondarySkills->addWidget(ChanceToUseCombat, 8, 1, 1, 1);

        Attentiveness = new SecondarySkill(scrollAreaWidgetContents);
        Attentiveness->setObjectName(QString::fromUtf8("Attentiveness"));
        sizePolicy2.setHeightForWidth(Attentiveness->sizePolicy().hasHeightForWidth());
        Attentiveness->setSizePolicy(sizePolicy2);
        Attentiveness->setMinimumSize(QSize(303, 70));
        Attentiveness->setMaximumSize(QSize(303, 70));
        Attentiveness->setStyleSheet(QString::fromUtf8("background:black;"));
        Attentiveness->setProperty("FontSize", QVariant(17));

        SecondarySkills->addWidget(Attentiveness, 6, 1, 1, 1);

        PhysicalDamage = new SecondarySkill(scrollAreaWidgetContents);
        PhysicalDamage->setObjectName(QString::fromUtf8("PhysicalDamage"));
        sizePolicy2.setHeightForWidth(PhysicalDamage->sizePolicy().hasHeightForWidth());
        PhysicalDamage->setSizePolicy(sizePolicy2);
        PhysicalDamage->setMinimumSize(QSize(303, 70));
        PhysicalDamage->setMaximumSize(QSize(303, 70));
        PhysicalDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        PhysicalDamage->setProperty("FontSize", QVariant(22));

        SecondarySkills->addWidget(PhysicalDamage, 0, 0, 1, 1);

        StrengtheningMagicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        StrengtheningMagicalEffects->setObjectName(QString::fromUtf8("StrengtheningMagicalEffects"));
        sizePolicy2.setHeightForWidth(StrengtheningMagicalEffects->sizePolicy().hasHeightForWidth());
        StrengtheningMagicalEffects->setSizePolicy(sizePolicy2);
        StrengtheningMagicalEffects->setMinimumSize(QSize(303, 70));
        StrengtheningMagicalEffects->setMaximumSize(QSize(303, 70));
        StrengtheningMagicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        StrengtheningMagicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(StrengtheningMagicalEffects, 3, 1, 1, 1);

        RangedAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        RangedAccuracy->setObjectName(QString::fromUtf8("RangedAccuracy"));
        sizePolicy2.setHeightForWidth(RangedAccuracy->sizePolicy().hasHeightForWidth());
        RangedAccuracy->setSizePolicy(sizePolicy2);
        RangedAccuracy->setMinimumSize(QSize(303, 70));
        RangedAccuracy->setMaximumSize(QSize(303, 70));
        RangedAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        RangedAccuracy->setProperty("FontSize", QVariant(20));

        SecondarySkills->addWidget(RangedAccuracy, 4, 1, 1, 1);

        MagicDamage = new SecondarySkill(scrollAreaWidgetContents);
        MagicDamage->setObjectName(QString::fromUtf8("MagicDamage"));
        sizePolicy2.setHeightForWidth(MagicDamage->sizePolicy().hasHeightForWidth());
        MagicDamage->setSizePolicy(sizePolicy2);
        MagicDamage->setMinimumSize(QSize(303, 70));
        MagicDamage->setMaximumSize(QSize(303, 70));
        MagicDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicDamage->setProperty("FontSize", QVariant(22));

        SecondarySkills->addWidget(MagicDamage, 0, 1, 1, 1);

        TravelRange = new SecondarySkill(scrollAreaWidgetContents);
        TravelRange->setObjectName(QString::fromUtf8("TravelRange"));
        sizePolicy2.setHeightForWidth(TravelRange->sizePolicy().hasHeightForWidth());
        TravelRange->setSizePolicy(sizePolicy2);
        TravelRange->setMinimumSize(QSize(303, 70));
        TravelRange->setMaximumSize(QSize(303, 70));
        TravelRange->setStyleSheet(QString::fromUtf8("background:black;"));
        TravelRange->setProperty("FontSize", QVariant(20));

        SecondarySkills->addWidget(TravelRange, 9, 1, 1, 1);

        StrengtheningPhysicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        StrengtheningPhysicalEffects->setObjectName(QString::fromUtf8("StrengtheningPhysicalEffects"));
        sizePolicy2.setHeightForWidth(StrengtheningPhysicalEffects->sizePolicy().hasHeightForWidth());
        StrengtheningPhysicalEffects->setSizePolicy(sizePolicy2);
        StrengtheningPhysicalEffects->setMinimumSize(QSize(303, 70));
        StrengtheningPhysicalEffects->setMaximumSize(QSize(303, 70));
        StrengtheningPhysicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        StrengtheningPhysicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(StrengtheningPhysicalEffects, 3, 0, 1, 1);

        MeleeAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        MeleeAccuracy->setObjectName(QString::fromUtf8("MeleeAccuracy"));
        sizePolicy2.setHeightForWidth(MeleeAccuracy->sizePolicy().hasHeightForWidth());
        MeleeAccuracy->setSizePolicy(sizePolicy2);
        MeleeAccuracy->setMinimumSize(QSize(303, 70));
        MeleeAccuracy->setMaximumSize(QSize(303, 70));
        MeleeAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        MeleeAccuracy->setProperty("FontSize", QVariant(20));

        SecondarySkills->addWidget(MeleeAccuracy, 4, 0, 1, 1);


        verticalLayout_2->addLayout(SecondarySkills);

        ScrollAreaSecondarySkills->setWidget(scrollAreaWidgetContents);
        SecondarySkillsShadowBottom = new QFrame(ScrollAreaWraper);
        SecondarySkillsShadowBottom->setObjectName(QString::fromUtf8("SecondarySkillsShadowBottom"));
        SecondarySkillsShadowBottom->setEnabled(false);
        SecondarySkillsShadowBottom->setGeometry(QRect(0, 387, 614, 7));
        SecondarySkillsShadowBottom->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(0, 0, 0, 165))"));
        SecondarySkillsShadowBottom->setFrameShape(QFrame::StyledPanel);
        SecondarySkillsShadowBottom->setFrameShadow(QFrame::Raised);
        SecondarySkillsShadowTop = new QFrame(ScrollAreaWraper);
        SecondarySkillsShadowTop->setObjectName(QString::fromUtf8("SecondarySkillsShadowTop"));
        SecondarySkillsShadowTop->setEnabled(false);
        SecondarySkillsShadowTop->setGeometry(QRect(0, 0, 614, 7));
        SecondarySkillsShadowTop->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 162), stop:1 rgba(255, 255, 255, 0))"));
        SecondarySkillsShadowTop->setFrameShape(QFrame::StyledPanel);
        SecondarySkillsShadowTop->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(ScrollAreaWraper);

        verticalScrollBar = new QScrollBar(frame);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setMaximumSize(QSize(16777215, 340));
        verticalScrollBar->setStyleSheet(QString::fromUtf8(""));
        verticalScrollBar->setMaximum(10);
        verticalScrollBar->setPageStep(1);
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalScrollBar);


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
        MagicTechniqueCastChance->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \321\201\320\276\321\202\320\262\320\276\321\200\320\265\320\275\320\270\321\217 \320\274\320\260\320\263. \321\202\320\265\321\205\320\275\320\270\320\272\320\270", nullptr)));
        Stealth->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\272\321\200\321\213\321\202\320\275\320\276\321\201\321\202\321\214", nullptr)));
        ResistPhysicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\215\321\204\321\204\320\265\320\272\321\202\320\260\320\274", nullptr)));
        MagicAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\274\320\260\320\263\320\270\320\270", nullptr)));
        ResistMagicDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\203\321\200\320\276\320\275\321\203", nullptr)));
        MagicCastChance->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \321\201\320\276\321\202\320\262\320\276\321\200\320\265\320\275\320\270\321\217 \320\274\320\260\320\263\320\270\320\270", nullptr)));
        ResistMagicEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\215\321\204\321\204\320\265\320\272\321\202\320\260\320\274", nullptr)));
        LoadCapacity->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\223\321\200\321\203\320\267\320\276\320\277\320\276\320\264\321\212\321\221\320\274\320\275\320\276\321\201\321\202\321\214", nullptr)));
        ResistPhysicalDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\203\321\200\320\276\320\275\321\203", nullptr)));
        Evasion->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265", nullptr)));
        Initiative->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\275\320\270\321\206\320\270\320\260\321\202\320\270\320\262\320\260", nullptr)));
        ChanceToUseCombat->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \320\277\321\200\320\270\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\261\320\276\320\265\320\262\320\276\320\263\320\276 \320\277\321\200\320\270\321\221\320\274\320\260", nullptr)));
        Attentiveness->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\320\275\320\270\320\274\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr)));
        PhysicalDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\244\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\203\321\200\320\276\320\275", nullptr)));
        StrengtheningMagicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\321\201\320\270\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\215\321\204\321\204\320\265\320\272\321\202\320\276\320\262", nullptr)));
        RangedAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\264\320\260\320\273\321\214\320\275\320\265\320\263\320\276 \320\261\320\276\321\217", nullptr)));
        MagicDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\203\321\200\320\276\320\275", nullptr)));
        TravelRange->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\224\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", nullptr)));
        StrengtheningPhysicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\321\201\320\270\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\215\321\204\321\204\320\265\320\272\321\202\320\276\320\262", nullptr)));
        MeleeAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\261\320\273\320\270\320\266\320\275\320\265\320\263\320\276 \320\261\320\276\321\217", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class CharacterWindow: public Ui_CharacterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'characterwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERWINDOW_H
#define UI_CHARACTERWINDOW_H

#include <CustomWidgets/CharacterEquipment/characterequipment.h>
#include <CustomWidgets/FPS_Counter/fps_counter.h>
#include <CustomWidgets/Inventories/CharacterWindowInventory/characterwindowinventory.h>
#include <CustomWidgets/MagicDefenseProgressBar/magicdefenseprogressbar.h>
#include <CustomWidgets/OpenworkButton/openworkbutton.h>
#include <CustomWidgets/PrimarySkill/primaryskill.h>
#include <CustomWidgets/SecondarySkill/secondaryskill.h>
#include <CustomWidgets/SecondarySkillProgressBar/secondaryskillprogressbar.h>
#include <CustomWidgets/Tooltip/tooltip.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterWindow
{
public:
    QFrame *TopMenuWrapper;
    QVBoxLayout *verticalLayout_3;
    QFrame *TopMenu;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *SaveButton;
    QPushButton *LoadButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    FPS_Counter *FPSCounter;
    QLabel *TopMenuBorder;
    QFrame *SkillsWraper;
    QVBoxLayout *verticalLayout;
    QFrame *PrimarySkillWrapper;
    QVBoxLayout *PrimarySkillWrapperL;
    QFrame *PrimarySkillsPanel;
    QFrame *PrimarySkills;
    PrimarySkill *PrimarySkillStrength;
    PrimarySkill *PrimarySkillAgility;
    PrimarySkill *PrimarySkillIntelligence;
    PrimarySkill *PrimarySkillMagic;
    PrimarySkill *PrimarySkillBodyType;
    PrimarySkill *PrimarySkillWill;
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
    SecondarySkill *ResistPhysicalEffects;
    SecondarySkill *StrengtheningPhysicalEffects;
    SecondarySkill *ResistMagicEffects;
    SecondarySkill *MeleeAccuracy;
    SecondarySkill *StrengtheningMagicalEffects;
    SecondarySkill *ResistPhysicalDamage;
    SecondarySkill *MagicDamage;
    SecondarySkill *MagicAccuracy;
    SecondarySkill *LoadCapacity;
    SecondarySkill *RangedAccuracy;
    SecondarySkill *ResistMagicDamage;
    SecondarySkill *Evasion;
    SecondarySkill *Stealth;
    SecondarySkill *MoveRange;
    SecondarySkill *MagicCastChance;
    SecondarySkill *ChanceOfUsingCombatTechnique;
    SecondarySkill *Initiative;
    SecondarySkill *Attentiveness;
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
    QLabel *BottomBorder;
    QLabel *BottomBound;
    Tooltip *tooltip;
    CharacterWindowInventory *Inventory;
    QLabel *DecorativeElement1;
    QLabel *DecorativeElement3;
    QLabel *DecorativeElement2;
    QLabel *DecorativeElement4;
    CharacterEquipment *Equipment;
    OpenworkButton *widget;

    void setupUi(QWidget *CharacterWindow)
    {
        if (CharacterWindow->objectName().isEmpty())
            CharacterWindow->setObjectName(QString::fromUtf8("CharacterWindow"));
        CharacterWindow->resize(1920, 1080);
        CharacterWindow->setMouseTracking(true);
        CharacterWindow->setFocusPolicy(Qt::StrongFocus);
        CharacterWindow->setAcceptDrops(true);
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
        pushButton_4 = new QPushButton(TopMenu);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(800, 20, 161, 34));
        pushButton_4->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton = new QPushButton(TopMenu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 1, 51, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_2 = new QPushButton(TopMenu);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(124, 1, 51, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_3 = new QPushButton(TopMenu);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(184, 1, 51, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("background:white;"));
        SaveButton = new QPushButton(TopMenu);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(1480, 20, 71, 41));
        SaveButton->setStyleSheet(QString::fromUtf8("background:white;"));
        LoadButton = new QPushButton(TopMenu);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));
        LoadButton->setEnabled(true);
        LoadButton->setGeometry(QRect(1580, 20, 71, 41));
        LoadButton->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_5 = new QPushButton(TopMenu);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(243, 1, 51, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_6 = new QPushButton(TopMenu);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(302, 1, 51, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_7 = new QPushButton(TopMenu);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(609, 1, 51, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_8 = new QPushButton(TopMenu);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(550, 1, 51, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_9 = new QPushButton(TopMenu);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(367, 1, 51, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_10 = new QPushButton(TopMenu);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(431, 1, 51, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_11 = new QPushButton(TopMenu);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(491, 1, 51, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_12 = new QPushButton(TopMenu);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(550, 44, 51, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_13 = new QPushButton(TopMenu);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(120, 44, 51, 41));
        pushButton_13->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_14 = new QPushButton(TopMenu);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(610, 44, 51, 41));
        pushButton_14->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_15 = new QPushButton(TopMenu);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(490, 44, 51, 41));
        pushButton_15->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_16 = new QPushButton(TopMenu);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(370, 44, 51, 41));
        pushButton_16->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_17 = new QPushButton(TopMenu);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(60, 44, 51, 41));
        pushButton_17->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_18 = new QPushButton(TopMenu);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(240, 44, 51, 41));
        pushButton_18->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_19 = new QPushButton(TopMenu);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(430, 44, 51, 41));
        pushButton_19->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_20 = new QPushButton(TopMenu);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(303, 44, 51, 41));
        pushButton_20->setStyleSheet(QString::fromUtf8("background:white;"));
        pushButton_21 = new QPushButton(TopMenu);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setGeometry(QRect(180, 44, 51, 41));
        pushButton_21->setStyleSheet(QString::fromUtf8("background:white;"));
        FPSCounter = new FPS_Counter(TopMenu);
        FPSCounter->setObjectName(QString::fromUtf8("FPSCounter"));
        FPSCounter->setGeometry(QRect(1780, 20, 60, 30));
        FPSCounter->setStyleSheet(QString::fromUtf8("background: white;"));

        verticalLayout_3->addWidget(TopMenu);

        TopMenuBorder = new QLabel(TopMenuWrapper);
        TopMenuBorder->setObjectName(QString::fromUtf8("TopMenuBorder"));
        TopMenuBorder->setMaximumSize(QSize(16777215, 3));
        TopMenuBorder->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(174, 156, 82, 255), stop:0.337079 rgba(174, 156, 82, 255), stop:0.339799 rgba(190, 195, 64, 255), stop:0.657303 rgba(190, 195, 64, 255), stop:0.662469 rgba(131, 118, 63, 255), stop:1 rgba(131, 118, 63, 255))"));
        TopMenuBorder->setLineWidth(0);

        verticalLayout_3->addWidget(TopMenuBorder);

        SkillsWraper = new QFrame(CharacterWindow);
        SkillsWraper->setObjectName(QString::fromUtf8("SkillsWraper"));
        SkillsWraper->setGeometry(QRect(46, 110, 666, 534));
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
        PrimarySkillsPanel = new QFrame(PrimarySkillWrapper);
        PrimarySkillsPanel->setObjectName(QString::fromUtf8("PrimarySkillsPanel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PrimarySkillsPanel->sizePolicy().hasHeightForWidth());
        PrimarySkillsPanel->setSizePolicy(sizePolicy1);
        PrimarySkillsPanel->setMinimumSize(QSize(611, 105));
        PrimarySkillsPanel->setMaximumSize(QSize(611, 105));
        PrimarySkillsPanel->setFrameShape(QFrame::StyledPanel);
        PrimarySkillsPanel->setFrameShadow(QFrame::Raised);
        PrimarySkills = new QFrame(PrimarySkillsPanel);
        PrimarySkills->setObjectName(QString::fromUtf8("PrimarySkills"));
        PrimarySkills->setGeometry(QRect(0, 0, 611, 105));
        sizePolicy1.setHeightForWidth(PrimarySkills->sizePolicy().hasHeightForWidth());
        PrimarySkills->setSizePolicy(sizePolicy1);
        PrimarySkills->setMinimumSize(QSize(0, 105));
        PrimarySkills->setMaximumSize(QSize(16777215, 105));
        PrimarySkills->setFrameShape(QFrame::StyledPanel);
        PrimarySkills->setFrameShadow(QFrame::Raised);
        PrimarySkillStrength = new PrimarySkill(PrimarySkills);
        PrimarySkillStrength->setObjectName(QString::fromUtf8("PrimarySkillStrength"));
        PrimarySkillStrength->setGeometry(QRect(0, 0, 111, 105));
        sizePolicy1.setHeightForWidth(PrimarySkillStrength->sizePolicy().hasHeightForWidth());
        PrimarySkillStrength->setSizePolicy(sizePolicy1);
        PrimarySkillAgility = new PrimarySkill(PrimarySkills);
        PrimarySkillAgility->setObjectName(QString::fromUtf8("PrimarySkillAgility"));
        PrimarySkillAgility->setGeometry(QRect(100, 0, 111, 105));
        sizePolicy1.setHeightForWidth(PrimarySkillAgility->sizePolicy().hasHeightForWidth());
        PrimarySkillAgility->setSizePolicy(sizePolicy1);
        PrimarySkillIntelligence = new PrimarySkill(PrimarySkills);
        PrimarySkillIntelligence->setObjectName(QString::fromUtf8("PrimarySkillIntelligence"));
        PrimarySkillIntelligence->setGeometry(QRect(200, 0, 111, 105));
        sizePolicy1.setHeightForWidth(PrimarySkillIntelligence->sizePolicy().hasHeightForWidth());
        PrimarySkillIntelligence->setSizePolicy(sizePolicy1);
        PrimarySkillMagic = new PrimarySkill(PrimarySkills);
        PrimarySkillMagic->setObjectName(QString::fromUtf8("PrimarySkillMagic"));
        PrimarySkillMagic->setGeometry(QRect(300, 0, 111, 105));
        sizePolicy1.setHeightForWidth(PrimarySkillMagic->sizePolicy().hasHeightForWidth());
        PrimarySkillMagic->setSizePolicy(sizePolicy1);
        PrimarySkillBodyType = new PrimarySkill(PrimarySkills);
        PrimarySkillBodyType->setObjectName(QString::fromUtf8("PrimarySkillBodyType"));
        PrimarySkillBodyType->setGeometry(QRect(400, 0, 111, 105));
        sizePolicy1.setHeightForWidth(PrimarySkillBodyType->sizePolicy().hasHeightForWidth());
        PrimarySkillBodyType->setSizePolicy(sizePolicy1);
        PrimarySkillWill = new PrimarySkill(PrimarySkills);
        PrimarySkillWill->setObjectName(QString::fromUtf8("PrimarySkillWill"));
        PrimarySkillWill->setGeometry(QRect(500, 0, 111, 105));
        sizePolicy1.setHeightForWidth(PrimarySkillWill->sizePolicy().hasHeightForWidth());
        PrimarySkillWill->setSizePolicy(sizePolicy1);
        Separators = new QFrame(PrimarySkillsPanel);
        Separators->setObjectName(QString::fromUtf8("Separators"));
        Separators->setGeometry(QRect(0, 70, 611, 35));
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
        PrimarySkills->raise();

        PrimarySkillWrapperL->addWidget(PrimarySkillsPanel);


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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 616, 696));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        SecondarySkills = new QGridLayout();
        SecondarySkills->setSpacing(8);
        SecondarySkills->setObjectName(QString::fromUtf8("SecondarySkills"));
        SecondarySkills->setSizeConstraint(QLayout::SetDefaultConstraint);
        ResistPhysicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        ResistPhysicalEffects->setObjectName(QString::fromUtf8("ResistPhysicalEffects"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ResistPhysicalEffects->sizePolicy().hasHeightForWidth());
        ResistPhysicalEffects->setSizePolicy(sizePolicy2);
        ResistPhysicalEffects->setMinimumSize(QSize(303, 70));
        ResistPhysicalEffects->setMaximumSize(QSize(303, 70));
        ResistPhysicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistPhysicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistPhysicalEffects, 2, 0, 1, 1);

        StrengtheningPhysicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        StrengtheningPhysicalEffects->setObjectName(QString::fromUtf8("StrengtheningPhysicalEffects"));
        sizePolicy2.setHeightForWidth(StrengtheningPhysicalEffects->sizePolicy().hasHeightForWidth());
        StrengtheningPhysicalEffects->setSizePolicy(sizePolicy2);
        StrengtheningPhysicalEffects->setMinimumSize(QSize(303, 70));
        StrengtheningPhysicalEffects->setMaximumSize(QSize(303, 70));
        StrengtheningPhysicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        StrengtheningPhysicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(StrengtheningPhysicalEffects, 3, 0, 1, 1);

        ResistMagicEffects = new SecondarySkill(scrollAreaWidgetContents);
        ResistMagicEffects->setObjectName(QString::fromUtf8("ResistMagicEffects"));
        sizePolicy2.setHeightForWidth(ResistMagicEffects->sizePolicy().hasHeightForWidth());
        ResistMagicEffects->setSizePolicy(sizePolicy2);
        ResistMagicEffects->setMinimumSize(QSize(303, 70));
        ResistMagicEffects->setMaximumSize(QSize(303, 70));
        ResistMagicEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistMagicEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistMagicEffects, 2, 1, 1, 1);

        MeleeAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        MeleeAccuracy->setObjectName(QString::fromUtf8("MeleeAccuracy"));
        sizePolicy2.setHeightForWidth(MeleeAccuracy->sizePolicy().hasHeightForWidth());
        MeleeAccuracy->setSizePolicy(sizePolicy2);
        MeleeAccuracy->setMinimumSize(QSize(303, 70));
        MeleeAccuracy->setMaximumSize(QSize(303, 70));
        MeleeAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        MeleeAccuracy->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(MeleeAccuracy, 4, 0, 1, 1);

        StrengtheningMagicalEffects = new SecondarySkill(scrollAreaWidgetContents);
        StrengtheningMagicalEffects->setObjectName(QString::fromUtf8("StrengtheningMagicalEffects"));
        sizePolicy2.setHeightForWidth(StrengtheningMagicalEffects->sizePolicy().hasHeightForWidth());
        StrengtheningMagicalEffects->setSizePolicy(sizePolicy2);
        StrengtheningMagicalEffects->setMinimumSize(QSize(303, 70));
        StrengtheningMagicalEffects->setMaximumSize(QSize(303, 70));
        StrengtheningMagicalEffects->setStyleSheet(QString::fromUtf8("background:black;"));
        StrengtheningMagicalEffects->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(StrengtheningMagicalEffects, 3, 1, 1, 1);

        ResistPhysicalDamage = new SecondarySkill(scrollAreaWidgetContents);
        ResistPhysicalDamage->setObjectName(QString::fromUtf8("ResistPhysicalDamage"));
        sizePolicy2.setHeightForWidth(ResistPhysicalDamage->sizePolicy().hasHeightForWidth());
        ResistPhysicalDamage->setSizePolicy(sizePolicy2);
        ResistPhysicalDamage->setMinimumSize(QSize(303, 70));
        ResistPhysicalDamage->setMaximumSize(QSize(303, 70));
        ResistPhysicalDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistPhysicalDamage->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistPhysicalDamage, 1, 0, 1, 1);

        MagicDamage = new SecondarySkill(scrollAreaWidgetContents);
        MagicDamage->setObjectName(QString::fromUtf8("MagicDamage"));
        sizePolicy2.setHeightForWidth(MagicDamage->sizePolicy().hasHeightForWidth());
        MagicDamage->setSizePolicy(sizePolicy2);
        MagicDamage->setMinimumSize(QSize(303, 70));
        MagicDamage->setMaximumSize(QSize(303, 70));
        MagicDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicDamage->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(MagicDamage, 0, 0, 1, 1);

        MagicAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        MagicAccuracy->setObjectName(QString::fromUtf8("MagicAccuracy"));
        sizePolicy2.setHeightForWidth(MagicAccuracy->sizePolicy().hasHeightForWidth());
        MagicAccuracy->setSizePolicy(sizePolicy2);
        MagicAccuracy->setMinimumSize(QSize(303, 70));
        MagicAccuracy->setMaximumSize(QSize(303, 70));
        MagicAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicAccuracy->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(MagicAccuracy, 5, 0, 1, 1);

        LoadCapacity = new SecondarySkill(scrollAreaWidgetContents);
        LoadCapacity->setObjectName(QString::fromUtf8("LoadCapacity"));
        sizePolicy2.setHeightForWidth(LoadCapacity->sizePolicy().hasHeightForWidth());
        LoadCapacity->setSizePolicy(sizePolicy2);
        LoadCapacity->setMinimumSize(QSize(303, 70));
        LoadCapacity->setMaximumSize(QSize(303, 70));
        LoadCapacity->setStyleSheet(QString::fromUtf8("background:black;"));
        LoadCapacity->setProperty("FontSize", QVariant(16));

        SecondarySkills->addWidget(LoadCapacity, 7, 0, 1, 1);

        RangedAccuracy = new SecondarySkill(scrollAreaWidgetContents);
        RangedAccuracy->setObjectName(QString::fromUtf8("RangedAccuracy"));
        sizePolicy2.setHeightForWidth(RangedAccuracy->sizePolicy().hasHeightForWidth());
        RangedAccuracy->setSizePolicy(sizePolicy2);
        RangedAccuracy->setMinimumSize(QSize(303, 70));
        RangedAccuracy->setMaximumSize(QSize(303, 70));
        RangedAccuracy->setStyleSheet(QString::fromUtf8("background:black;"));
        RangedAccuracy->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(RangedAccuracy, 4, 1, 1, 1);

        ResistMagicDamage = new SecondarySkill(scrollAreaWidgetContents);
        ResistMagicDamage->setObjectName(QString::fromUtf8("ResistMagicDamage"));
        sizePolicy2.setHeightForWidth(ResistMagicDamage->sizePolicy().hasHeightForWidth());
        ResistMagicDamage->setSizePolicy(sizePolicy2);
        ResistMagicDamage->setMinimumSize(QSize(303, 70));
        ResistMagicDamage->setMaximumSize(QSize(303, 70));
        ResistMagicDamage->setStyleSheet(QString::fromUtf8("background:black;"));
        ResistMagicDamage->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ResistMagicDamage, 1, 1, 1, 1);

        Evasion = new SecondarySkill(scrollAreaWidgetContents);
        Evasion->setObjectName(QString::fromUtf8("Evasion"));
        sizePolicy2.setHeightForWidth(Evasion->sizePolicy().hasHeightForWidth());
        Evasion->setSizePolicy(sizePolicy2);
        Evasion->setMinimumSize(QSize(303, 70));
        Evasion->setMaximumSize(QSize(303, 70));
        Evasion->setStyleSheet(QString::fromUtf8("background:black;"));
        Evasion->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(Evasion, 0, 1, 1, 1);

        Stealth = new SecondarySkill(scrollAreaWidgetContents);
        Stealth->setObjectName(QString::fromUtf8("Stealth"));
        sizePolicy2.setHeightForWidth(Stealth->sizePolicy().hasHeightForWidth());
        Stealth->setSizePolicy(sizePolicy2);
        Stealth->setMinimumSize(QSize(303, 70));
        Stealth->setMaximumSize(QSize(303, 70));
        Stealth->setStyleSheet(QString::fromUtf8("background:black;"));
        Stealth->setProperty("FontSize", QVariant(20));

        SecondarySkills->addWidget(Stealth, 5, 1, 1, 1);

        MoveRange = new SecondarySkill(scrollAreaWidgetContents);
        MoveRange->setObjectName(QString::fromUtf8("MoveRange"));
        sizePolicy2.setHeightForWidth(MoveRange->sizePolicy().hasHeightForWidth());
        MoveRange->setSizePolicy(sizePolicy2);
        MoveRange->setMinimumSize(QSize(303, 70));
        MoveRange->setMaximumSize(QSize(303, 70));
        MoveRange->setStyleSheet(QString::fromUtf8("background:black;"));
        MoveRange->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(MoveRange, 8, 1, 1, 1);

        MagicCastChance = new SecondarySkill(scrollAreaWidgetContents);
        MagicCastChance->setObjectName(QString::fromUtf8("MagicCastChance"));
        sizePolicy2.setHeightForWidth(MagicCastChance->sizePolicy().hasHeightForWidth());
        MagicCastChance->setSizePolicy(sizePolicy2);
        MagicCastChance->setMinimumSize(QSize(303, 70));
        MagicCastChance->setMaximumSize(QSize(303, 70));
        MagicCastChance->setStyleSheet(QString::fromUtf8("background:black;"));
        MagicCastChance->setProperty("FontSize", QVariant(16));

        SecondarySkills->addWidget(MagicCastChance, 6, 0, 1, 1);

        ChanceOfUsingCombatTechnique = new SecondarySkill(scrollAreaWidgetContents);
        ChanceOfUsingCombatTechnique->setObjectName(QString::fromUtf8("ChanceOfUsingCombatTechnique"));
        sizePolicy2.setHeightForWidth(ChanceOfUsingCombatTechnique->sizePolicy().hasHeightForWidth());
        ChanceOfUsingCombatTechnique->setSizePolicy(sizePolicy2);
        ChanceOfUsingCombatTechnique->setMinimumSize(QSize(303, 70));
        ChanceOfUsingCombatTechnique->setMaximumSize(QSize(303, 70));
        ChanceOfUsingCombatTechnique->setStyleSheet(QString::fromUtf8("background:black;"));
        ChanceOfUsingCombatTechnique->setProperty("FontSize", QVariant(18));

        SecondarySkills->addWidget(ChanceOfUsingCombatTechnique, 6, 1, 1, 1);

        Initiative = new SecondarySkill(scrollAreaWidgetContents);
        Initiative->setObjectName(QString::fromUtf8("Initiative"));
        sizePolicy2.setHeightForWidth(Initiative->sizePolicy().hasHeightForWidth());
        Initiative->setSizePolicy(sizePolicy2);
        Initiative->setMinimumSize(QSize(303, 70));
        Initiative->setMaximumSize(QSize(303, 70));
        Initiative->setStyleSheet(QString::fromUtf8("background:black;"));
        Initiative->setProperty("FontSize", QVariant(19));

        SecondarySkills->addWidget(Initiative, 7, 1, 1, 1);

        Attentiveness = new SecondarySkill(scrollAreaWidgetContents);
        Attentiveness->setObjectName(QString::fromUtf8("Attentiveness"));
        sizePolicy2.setHeightForWidth(Attentiveness->sizePolicy().hasHeightForWidth());
        Attentiveness->setSizePolicy(sizePolicy2);
        Attentiveness->setMinimumSize(QSize(303, 70));
        Attentiveness->setMaximumSize(QSize(303, 70));
        Attentiveness->setStyleSheet(QString::fromUtf8("background:black;"));
        Attentiveness->setProperty("FontSize", QVariant(17));

        SecondarySkills->addWidget(Attentiveness, 8, 0, 1, 1);


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
        verticalScrollBar->setMaximum(299);
        verticalScrollBar->setSingleStep(76);
        verticalScrollBar->setPageStep(18);
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalScrollBar);


        verticalLayout->addWidget(SecondarySkillsWraper);

        ProgressBars = new QFrame(CharacterWindow);
        ProgressBars->setObjectName(QString::fromUtf8("ProgressBars"));
        ProgressBars->setGeometry(QRect(48, 676, 754, 379));
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
        Health->setProperty("FormulaFontSize", QVariant(23));

        verticalLayout_5->addWidget(Health);

        Endurance = new SecondarySkillProgressBar(ProgressBars);
        Endurance->setObjectName(QString::fromUtf8("Endurance"));
        Endurance->setMinimumSize(QSize(734, 87));
        Endurance->setMaximumSize(QSize(734, 87));
        Endurance->setProperty("FormulaFontSize", QVariant(24));

        verticalLayout_5->addWidget(Endurance);

        Mana = new SecondarySkillProgressBar(ProgressBars);
        Mana->setObjectName(QString::fromUtf8("Mana"));
        Mana->setMinimumSize(QSize(734, 87));
        Mana->setMaximumSize(QSize(734, 87));
        Mana->setProperty("FormulaFontSize", QVariant(24));

        verticalLayout_5->addWidget(Mana);

        MagicDefense = new MagicDefenseProgressBar(ProgressBars);
        MagicDefense->setObjectName(QString::fromUtf8("MagicDefense"));
        MagicDefense->setMinimumSize(QSize(734, 80));
        MagicDefense->setMaximumSize(QSize(734, 80));

        verticalLayout_5->addWidget(MagicDefense);

        BottomBoundWrapper = new QFrame(CharacterWindow);
        BottomBoundWrapper->setObjectName(QString::fromUtf8("BottomBoundWrapper"));
        BottomBoundWrapper->setGeometry(QRect(-1, 1055, 1922, 27));
        BottomBoundWrapper->setFrameShape(QFrame::StyledPanel);
        BottomBoundWrapper->setFrameShadow(QFrame::Raised);
        BottomBoundWrapper->setLineWidth(0);
        verticalLayout_4 = new QVBoxLayout(BottomBoundWrapper);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
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

        tooltip = new Tooltip(CharacterWindow);
        tooltip->setObjectName(QString::fromUtf8("tooltip"));
        tooltip->setGeometry(QRect(0, 0, 0, 0));
        Inventory = new CharacterWindowInventory(CharacterWindow);
        Inventory->setObjectName(QString::fromUtf8("Inventory"));
        Inventory->setGeometry(QRect(1129, 706, 785, 349));
        DecorativeElement1 = new QLabel(CharacterWindow);
        DecorativeElement1->setObjectName(QString::fromUtf8("DecorativeElement1"));
        DecorativeElement1->setGeometry(QRect(9, 1046, 43, 10));
        DecorativeElement1->setStyleSheet(QString::fromUtf8("background-image: url(:/Decorative-Elements/Textures PNG/DecorativeElement-1-L.png);"));
        DecorativeElement3 = new QLabel(CharacterWindow);
        DecorativeElement3->setObjectName(QString::fromUtf8("DecorativeElement3"));
        DecorativeElement3->setGeometry(QRect(1101, 1046, 43, 10));
        DecorativeElement3->setStyleSheet(QString::fromUtf8("background-image: url(:/Decorative-Elements/Textures PNG/DecorativeElement-1-L.png);"));
        DecorativeElement2 = new QLabel(CharacterWindow);
        DecorativeElement2->setObjectName(QString::fromUtf8("DecorativeElement2"));
        DecorativeElement2->setGeometry(QRect(776, 1046, 43, 10));
        DecorativeElement2->setStyleSheet(QString::fromUtf8("background-image: url(:/Decorative-Elements/Textures PNG/DecorativeElement-1-R.png);"));
        DecorativeElement4 = new QLabel(CharacterWindow);
        DecorativeElement4->setObjectName(QString::fromUtf8("DecorativeElement4"));
        DecorativeElement4->setGeometry(QRect(1868, 1046, 43, 10));
        DecorativeElement4->setStyleSheet(QString::fromUtf8("background-image: url(:/Decorative-Elements/Textures PNG/DecorativeElement-1-R.png);"));
        Equipment = new CharacterEquipment(CharacterWindow);
        Equipment->setObjectName(QString::fromUtf8("Equipment"));
        Equipment->setGeometry(QRect(1154, 100, 714, 472));
        widget = new OpenworkButton(CharacterWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(790, 240, 151, 81));
        TopMenuWrapper->raise();
        SkillsWraper->raise();
        BottomBoundWrapper->raise();
        ProgressBars->raise();
        Inventory->raise();
        DecorativeElement1->raise();
        DecorativeElement3->raise();
        DecorativeElement2->raise();
        DecorativeElement4->raise();
        tooltip->raise();
        Equipment->raise();
        widget->raise();

        retranslateUi(CharacterWindow);

        QMetaObject::connectSlotsByName(CharacterWindow);
    } // setupUi

    void retranslateUi(QWidget *CharacterWindow)
    {
        CharacterWindow->setWindowTitle(QCoreApplication::translate("CharacterWindow", "Dungeoner", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CharacterWindow", "\320\227\320\260\321\205\320\270\320\273\321\217\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\265\321\201\321\201\320\261\320\260\321\200\321\213", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 1</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\275\320\265\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 <span style=\" font-weight:700;\">\320\241\320\270\320\273\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("CharacterWindow", "1", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 2</p><p>\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\275\320\265\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 <span style=\" font-weight:700;\">\320\241\320\270\320\273\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QCoreApplication::translate("CharacterWindow", "2", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 3</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 <span style=\" font-weight:700;\">\320\233\320\276\320\262\320\272\320\276\321\201\321\202\320\270</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_3->setText(QCoreApplication::translate("CharacterWindow", "3", nullptr));
        SaveButton->setText(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        LoadButton->setText(QCoreApplication::translate("CharacterWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 4</p><p>\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 <span style=\" font-weight:700;\">\320\233\320\276\320\262\320\272\320\276\321\201\321\202\320\270</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_5->setWhatsThis(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 4</p><p><br/></p><p>\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 <span style=\" font-weight:700;\">\320\233\320\276\320\262\320\272\320\276\321\201\321\202\320\270</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_5->setText(QCoreApplication::translate("CharacterWindow", "4", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 5</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\275\320\265\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\264\320\265\320\261\320\260\321\204\320\260 <span style=\" font-weight:700;\">\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_6->setText(QCoreApplication::translate("CharacterWindow", "5", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_7->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 10</p><p>\320\243\320\264\320\260\320\273\321\217\320\265\321\202 \321\201\321\202\321\200\320\276\320\272\321\203 \320\270\320\275\320\262\320\265\320\275\321\202\320\260\321\200\321\217</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_7->setText(QCoreApplication::translate("CharacterWindow", "10", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_8->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 9</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202 \321\201\321\202\321\200\320\276\320\272\321\203 \320\270\320\275\320\262\320\265\320\275\321\202\320\260\321\200\321\217 \321\201 \321\202\320\265\321\201\321\202\320\276\320\262\320\276\320\271 \320\262\320\265\321\211\321\214\321\216 \320\262 \320\272\320\260\320\266\320\264\320\276\320\271 \321\217\321\207\320\265\320\271\320\272\320\265</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_8->setText(QCoreApplication::translate("CharacterWindow", "9", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_9->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 6</p><p>\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\275\320\265\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\264\320\265\320\261\320\260\321\204\320\260 <span style=\" font-weight:700;\">\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_9->setText(QCoreApplication::translate("CharacterWindow", "6", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_10->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 7</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\264\320\265\320\261\320\260\321\204\320\260 <span style=\" font-weight:700;\">\320\234\320\260\320\263\320\270\320\270</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_10->setText(QCoreApplication::translate("CharacterWindow", "7", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_11->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 8</p><p>\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\264\320\265\320\261\320\260\321\204\320\260 <span style=\" font-weight:700;\">\320\234\320\260\320\263\320\270\320\270</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_11->setText(QCoreApplication::translate("CharacterWindow", "8", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_12->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 19</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_12->setText(QCoreApplication::translate("CharacterWindow", "19", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_13->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 12</p><p>\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\262\321\201\320\265\321\205 \320\261\320\276\320\275\321\203\321\201\320\276\320\262 \320\270 \320\264\320\265\320\261\320\260\321\204\320\276\320\262 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\275\321\213\321\205 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 11</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_13->setText(QCoreApplication::translate("CharacterWindow", "12", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_14->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 20</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_14->setText(QCoreApplication::translate("CharacterWindow", "20", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_15->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 18</p><p>\320\221\320\276\320\275\321\203\321\201 \320\275\320\260 \321\217\321\207\320\265\320\271\320\272\320\270 2</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_15->setText(QCoreApplication::translate("CharacterWindow", "18", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_16->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 16</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 \320\272\320\276 <span style=\" font-weight:700;\">\320\262\321\201\320\265\320\274</span> \321\217\321\207\320\265\320\271\320\272\320\260\320\274 <span style=\" font-weight:700;\">\320\274\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\267\320\260\321\211\320\270\321\202\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_16->setText(QCoreApplication::translate("CharacterWindow", "16", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_17->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 11</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\261\320\276\320\273\321\214\321\210\320\276\320\263\320\276 \321\207\320\270\321\201\320\273\320\260 \320\261\320\276\320\275\321\203\321\201\320\276\320\262\320\276 \320\270 \320\264\320\265\320\261\320\260\321\204\320\276\320\262 \320\272 <span style=\" font-weight:700;\">\320\227\320\264\320\276\321\200\320\276\320\262\321\214\321\216</span> \320\264\320\273\321\217 \321\202\320\265\321\201\321\202\320\260 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270 \320\261\320\276\320\275\321\203\321\201\320\276\320\262</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_17->setText(QCoreApplication::translate("CharacterWindow", "11", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_18->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 14</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 \320\272 <span style=\" font-weight:700;\">\320\277\320\265\321\200\320\262\320\276\320\271</span> \321\217\321\207\320\265\320\271\320\272\320\265 <span style=\" font-weight:700;\">\320\274\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\267\320\260\321\211\320\270\321\202\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_18->setWhatsThis(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 4</p><p><br/></p><p>\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 <span style=\" font-weight:700;\">\320\233\320\276\320\262\320\272\320\276\321\201\321\202\320\270</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_18->setText(QCoreApplication::translate("CharacterWindow", "14", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_19->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 17</p><p>\320\221\320\276\320\275\321\203\321\201 \320\275\320\260 \321\217\321\207\320\265\320\271\320\272\320\270 1</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_19->setText(QCoreApplication::translate("CharacterWindow", "17", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_20->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 15</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\275\320\265\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 \320\272 <span style=\" font-weight:700;\">\321\202\321\200\320\265\321\202\320\265\320\271</span> \321\217\321\207\320\265\320\271\320\272\320\265 <span style=\" font-weight:700;\">\320\274\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\267\320\260\321\211\320\270\321\202\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_20->setText(QCoreApplication::translate("CharacterWindow", "15", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_21->setToolTip(QCoreApplication::translate("CharacterWindow", "<html><head/><body><p>\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 13</p><p>\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 <span style=\" font-weight:700;\">\320\275\320\265\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\276\320\263\320\276</span> \320\261\320\276\320\275\321\203\321\201\320\260 \320\272 <span style=\" font-weight:700;\">\321\206\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\276\320\271</span> \321\217\321\207\320\265\320\271\320\272\320\265 <span style=\" font-weight:700;\">\320\274\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\267\320\260\321\211\320\270\321\202\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_21->setText(QCoreApplication::translate("CharacterWindow", "13", nullptr));
        TopMenuBorder->setText(QString());
        PrimarySkillStrength->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\230\320\233\320\220", nullptr)));
        PrimarySkillStrength->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\270\320\273\320\260", nullptr)));
        PrimarySkillStrength->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        PrimarySkillAgility->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\233\320\236\320\222\320\232", nullptr)));
        PrimarySkillAgility->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\233\320\276\320\262\320\272\320\276\321\201\321\202\321\214", nullptr)));
        PrimarySkillAgility->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        PrimarySkillIntelligence->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\235\320\242", nullptr)));
        PrimarySkillIntelligence->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202", nullptr)));
        PrimarySkillIntelligence->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        PrimarySkillMagic->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\220\320\223", nullptr)));
        PrimarySkillMagic->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\263\320\270\321\217", nullptr)));
        PrimarySkillMagic->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        PrimarySkillBodyType->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\225\320\233", nullptr)));
        PrimarySkillBodyType->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\265\320\273\320\276\321\201\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr)));
        PrimarySkillBodyType->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        PrimarySkillWill->setProperty("Text", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\320\236\320\233", nullptr)));
        PrimarySkillWill->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\320\276\320\273\321\217", nullptr)));
        PrimarySkillWill->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        Separator4->setText(QString());
        Separator1->setText(QString());
        Separator5->setText(QString());
        Separator2->setText(QString());
        Separator3->setText(QString());
        ResistPhysicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\215\321\204\321\204\320\265\320\272\321\202\320\260\320\274", nullptr)));
        ResistPhysicalEffects->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\320\274 \321\215\321\204\321\204\320\265\320\272\321\202\320\260\320\274", nullptr)));
        ResistPhysicalEffects->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.1\303\227\320\222\320\276\320\273\321\217 + 10", nullptr)));
        ResistPhysicalEffects->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        StrengtheningPhysicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\321\201\320\270\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\215\321\204\321\204\320\265\320\272\321\202\320\276\320\262", nullptr)));
        StrengtheningPhysicalEffects->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\321\201\320\270\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\215\321\204\321\204\320\265\320\272\321\202\320\276\320\262", nullptr)));
        StrengtheningPhysicalEffects->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.1\303\227\320\241\320\270\320\273\320\260", nullptr)));
        StrengtheningPhysicalEffects->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        ResistMagicEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\215\321\204\321\204\320\265\320\272\321\202\320\260\320\274", nullptr)));
        ResistMagicEffects->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\274 \321\215\321\204\321\204\320\265\320\272\321\202\320\260\320\274", nullptr)));
        ResistMagicEffects->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.1\303\227\320\222\320\276\320\273\321\217 + 0.1\303\227\320\234\320\260\320\263 + 5", nullptr)));
        ResistMagicEffects->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        MeleeAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\261\320\273\320\270\320\266\320\275\320\265\320\263\320\276 \320\261\320\276\321\217", nullptr)));
        MeleeAccuracy->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\261\320\273\320\270\320\266\320\275\320\265\320\263\320\276 \320\261\320\276\321\217", nullptr)));
        MeleeAccuracy->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.1\303\227\320\233\320\276\320\262\320\272 + 20", nullptr)));
        MeleeAccuracy->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        StrengtheningMagicalEffects->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\321\201\320\270\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\215\321\204\321\204\320\265\320\272\321\202\320\276\320\262", nullptr)));
        StrengtheningMagicalEffects->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\321\201\320\270\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\215\321\204\321\204\320\265\320\272\321\202\320\276\320\262", nullptr)));
        StrengtheningMagicalEffects->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.1\303\227\320\230\320\275\321\202", nullptr)));
        StrengtheningMagicalEffects->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        ResistPhysicalDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267. \321\203\321\200\320\276\320\275\321\203", nullptr)));
        ResistPhysicalDamage->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \321\204\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\276\320\274\321\203 \321\203\321\200\320\276\320\275\321\203", nullptr)));
        ResistPhysicalDamage->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "1.5\303\227\320\222\320\276\320\273\321\217 + \320\242\320\265\320\273 + 0.5\303\227\320\234\320\260\320\263\320\270\321\217", nullptr)));
        ResistPhysicalDamage->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        MagicDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\203\321\200\320\276\320\275", nullptr)));
        MagicDamage->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\203\321\200\320\276\320\275", nullptr)));
        MagicDamage->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "1.5\303\227\320\234\320\260\320\263 + 1.5\303\227\320\230\320\275\321\202 + 0.5\303\227\320\222\320\276\320\273\321\217", nullptr)));
        MagicDamage->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        MagicAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\274\320\260\320\263\320\270\320\270", nullptr)));
        MagicAccuracy->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\274\320\260\320\263\320\270\320\270", nullptr)));
        MagicAccuracy->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.1\303\227\320\230\320\275\321\202 + 15", nullptr)));
        MagicAccuracy->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        LoadCapacity->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\223\321\200\321\203\320\267\320\276\320\277\320\276\320\264\321\212\321\221\320\274\320\275\320\276\321\201\321\202\321\214", nullptr)));
        LoadCapacity->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\223\321\200\321\203\320\267\320\276\320\277\320\276\320\264\321\212\321\221\320\274\320\275\320\276\321\201\321\202\321\214", nullptr)));
        LoadCapacity->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.5\303\227\320\241\320\270\320\273\320\260 + 0.5\303\227\320\242\320\265\320\273", nullptr)));
        LoadCapacity->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        RangedAccuracy->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\264\320\260\320\273\321\214\320\275\320\265\320\263\320\276 \320\261\320\276\321\217", nullptr)));
        RangedAccuracy->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\264\320\260\320\273\321\214\320\275\320\265\320\263\320\276 \320\261\320\276\321\217", nullptr)));
        RangedAccuracy->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.1\303\227\320\233\320\276\320\262\320\272 + 15", nullptr)));
        RangedAccuracy->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        ResistMagicDamage->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263. \321\203\321\200\320\276\320\275\321\203", nullptr)));
        ResistMagicDamage->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\276\320\274\321\203 \321\203\321\200\320\276\320\275\321\203", nullptr)));
        ResistMagicDamage->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "1.5\303\227\320\222\320\276\320\273\321\217 + \320\234\320\260\320\263 + 0.5\303\227\320\242\320\265\320\273", nullptr)));
        ResistMagicDamage->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        Evasion->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265", nullptr)));
        Evasion->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\243\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265", nullptr)));
        Evasion->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.5\303\227\320\233\320\276\320\262\320\272 + 0.1\303\227\320\242\320\265\320\273", nullptr)));
        Evasion->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        Stealth->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\272\321\200\321\213\321\202\320\275\320\276\321\201\321\202\321\214", nullptr)));
        Stealth->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\241\320\272\321\200\321\213\321\202\320\275\320\276\321\201\321\202\321\214", nullptr)));
        Stealth->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\275\321\202 + \320\233\320\276\320\262\320\272", nullptr)));
        Stealth->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        MoveRange->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\224\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", nullptr)));
        MoveRange->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\224\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", nullptr)));
        MoveRange->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "\320\242\320\265\320\273 + 0.75\303\227\320\233\320\276\320\262\320\272 + 0.5\303\227\320\241\320\270\320\273\320\260", nullptr)));
        MoveRange->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        MagicCastChance->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \321\201\320\276\321\202\320\262\320\276\321\200\320\265\320\275\320\270\321\217 \320\274\320\260\320\263\320\270\320\270", nullptr)));
        MagicCastChance->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \321\201\320\276\321\202\320\262\320\276\321\200\320\265\320\275\320\270\321\217 \320\274\320\260\320\263\320\270\320\270", nullptr)));
        MagicCastChance->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.3\303\227\320\230\320\275\321\202 + 0.2\303\227\320\234\320\260\320\263", nullptr)));
        MagicCastChance->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        ChanceOfUsingCombatTechnique->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \320\261\320\276\320\265\320\262\320\276\320\263\320\276  \320\277\321\200\320\270\321\221\320\274\320\260", nullptr)));
        ChanceOfUsingCombatTechnique->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\250\320\260\320\275\321\201 \320\277\321\200\320\270\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\261\320\276\320\265\320\262\320\276\320\263\320\276  \320\277\321\200\320\270\321\221\320\274\320\260", nullptr)));
        ChanceOfUsingCombatTechnique->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "0.2\303\227\320\233\320\276\320\262\320\272 + 20", nullptr)));
        ChanceOfUsingCombatTechnique->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        Initiative->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\275\320\270\321\206\320\270\320\260\321\202\320\270\320\262\320\260", nullptr)));
        Initiative->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\275\320\270\321\206\320\270\320\260\321\202\320\270\320\262\320\260", nullptr)));
        Initiative->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "5\303\227\320\233\320\276\320\262\320\272 + \320\230\320\275\321\202 + \320\222\320\276\320\273\321\217", nullptr)));
        Initiative->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        Attentiveness->setProperty("Inscription", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\320\275\320\270\320\274\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr)));
        Attentiveness->setProperty("FullName", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\320\275\320\270\320\274\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr)));
        Attentiveness->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "\320\230\320\275\321\202 + \320\233\320\276\320\262\320\272 + \320\222\320\276\320\273\321\217", nullptr)));
        Attentiveness->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        Health->setProperty("Color", QVariant(QCoreApplication::translate("CharacterWindow", "#dc0000", nullptr)));
        Health->setProperty("Name", QVariant(QCoreApplication::translate("CharacterWindow", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr)));
        Health->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "10\303\227\320\242\320\265\320\273 + 5\303\227\320\222\320\276\320\273\321\217 + 2\303\227\320\241\320\270\320\273\320\260 + \320\234\320\260\320\263", nullptr)));
        Health->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        Endurance->setProperty("Color", QVariant(QCoreApplication::translate("CharacterWindow", "#0fcd00", nullptr)));
        Endurance->setProperty("Name", QVariant(QCoreApplication::translate("CharacterWindow", "\320\222\321\213\320\275\320\276\321\201\320\273\320\270\320\262\320\276\321\201\321\202\321\214", nullptr)));
        Endurance->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "10\303\227\320\233\320\276\320\262\320\272 + \320\242\320\265\320\273", nullptr)));
        Endurance->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        Mana->setProperty("Color", QVariant(QCoreApplication::translate("CharacterWindow", "#1e55ff", nullptr)));
        Mana->setProperty("Name", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\275\320\260", nullptr)));
        Mana->setProperty("Formula", QVariant(QCoreApplication::translate("CharacterWindow", "10\303\227\320\234\320\260\320\263 + 2\303\227\320\230\320\275\321\202 + \320\222\320\276\320\273\321\217", nullptr)));
        Mana->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        MagicDefense->setProperty("Color", QVariant(QCoreApplication::translate("CharacterWindow", "#9e17cf", nullptr)));
        MagicDefense->setProperty("Name", QVariant(QCoreApplication::translate("CharacterWindow", "\320\234\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\267\320\260\321\211\320\270\321\202\320\260", nullptr)));
        MagicDefense->setProperty("Description", QVariant(QCoreApplication::translate("CharacterWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr)));
        MagicDefense->setProperty("NumberOfChunksFormula", QVariant(QCoreApplication::translate("CharacterWindow", "\320\237\320\265\321\200\320\262\321\213\320\271 \321\204\321\200\320\260\320\263\320\274\320\265\320\275\321\202 \320\267\320\260\321\211\320\270\321\202\321\213 \320\264\320\260\321\221\321\202\321\201\321\217 \320\277\321\200\320\270 5 \320\262\320\276\320\273\320\270, \320\270 \320\264\320\273\321\217 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\270\321\217 \320\272\320\260\320\266\320\264\320\276\320\263\320\276 \320\277\320\276\321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\263\320\276 \321\204\321\200\320\260\320\274\320\265\320\275\321\202\320\260 \321\202\321\200\320\265\320\261\321\203\320\265\321\202\321\201\321\217 \320\262 1.2 \321\200\320\260\320\267\320\260 \320\261\320\276\320\273\321\214\321\210\320\265 \320\262\320\276\320\273\320\270", nullptr)));
        MagicDefense->setProperty("ChunkValueFormula", QVariant(QCoreApplication::translate("CharacterWindow", "0.7\303\227\320\234\320\260\320\263 + 0.3\303\227\320\242\320\265\320\273", nullptr)));
        BottomBorder->setText(QString());
        BottomBound->setText(QString());
        DecorativeElement1->setText(QString());
        DecorativeElement3->setText(QString());
        DecorativeElement2->setText(QString());
        DecorativeElement4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CharacterWindow: public Ui_CharacterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERWINDOW_H

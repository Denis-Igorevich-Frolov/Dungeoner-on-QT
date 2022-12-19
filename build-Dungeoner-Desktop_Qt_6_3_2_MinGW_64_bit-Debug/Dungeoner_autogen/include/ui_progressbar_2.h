/********************************************************************************
** Form generated from reading UI file 'progressbar_2.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBAR_2_H
#define UI_PROGRESSBAR_2_H

#include <CustomWidgets/LabelWithTooltip/labelwithtooltip.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressBar_2
{
public:
    QFrame *SeparatorWrapper;
    QFrame *LabelWithTooltipWrapper;
    QVBoxLayout *verticalLayout_3;
    LabelWithTooltip *labelWithTooltip;
    QFrame *BordersWrapper;
    QVBoxLayout *verticalLayout;
    QLabel *BorderTop;
    QSpacerItem *verticalSpacer;
    QLabel *BorderBottom;
    QFrame *ChunkWrapper;
    QHBoxLayout *horizontalLayout;
    QLabel *ProgressBarChunk;
    QSpacerItem *ChunkShifter;
    QFrame *ShadowWrapper;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Shadow;
    QFrame *TipsWrapper;
    QGridLayout *gridLayout_2;
    QLabel *TipLeft;
    QLabel *TipRight;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ProgressBar_2)
    {
        if (ProgressBar_2->objectName().isEmpty())
            ProgressBar_2->setObjectName(QString::fromUtf8("ProgressBar_2"));
        ProgressBar_2->resize(262, 50);
        SeparatorWrapper = new QFrame(ProgressBar_2);
        SeparatorWrapper->setObjectName(QString::fromUtf8("SeparatorWrapper"));
        SeparatorWrapper->setGeometry(QRect(0, 2, 262, 43));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SeparatorWrapper->sizePolicy().hasHeightForWidth());
        SeparatorWrapper->setSizePolicy(sizePolicy);
        SeparatorWrapper->setMinimumSize(QSize(0, 43));
        SeparatorWrapper->setMaximumSize(QSize(16777215, 43));
        SeparatorWrapper->setFrameShape(QFrame::StyledPanel);
        SeparatorWrapper->setFrameShadow(QFrame::Raised);
        LabelWithTooltipWrapper = new QFrame(ProgressBar_2);
        LabelWithTooltipWrapper->setObjectName(QString::fromUtf8("LabelWithTooltipWrapper"));
        LabelWithTooltipWrapper->setGeometry(QRect(0, 2, 261, 46));
        LabelWithTooltipWrapper->setFrameShape(QFrame::StyledPanel);
        LabelWithTooltipWrapper->setFrameShadow(QFrame::Raised);
        LabelWithTooltipWrapper->setLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(LabelWithTooltipWrapper);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(12, 3, 12, 7);
        labelWithTooltip = new LabelWithTooltip(LabelWithTooltipWrapper);
        labelWithTooltip->setObjectName(QString::fromUtf8("labelWithTooltip"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelWithTooltip->sizePolicy().hasHeightForWidth());
        labelWithTooltip->setSizePolicy(sizePolicy1);
        labelWithTooltip->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(labelWithTooltip);

        BordersWrapper = new QFrame(ProgressBar_2);
        BordersWrapper->setObjectName(QString::fromUtf8("BordersWrapper"));
        BordersWrapper->setGeometry(QRect(0, 2, 261, 46));
        BordersWrapper->setStyleSheet(QString::fromUtf8(""));
        BordersWrapper->setFrameShape(QFrame::StyledPanel);
        BordersWrapper->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(BordersWrapper);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(45, 6, 45, 7);
        BorderTop = new QLabel(BordersWrapper);
        BorderTop->setObjectName(QString::fromUtf8("BorderTop"));
        BorderTop->setMinimumSize(QSize(0, 5));
        BorderTop->setMaximumSize(QSize(16777215, 5));
        BorderTop->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(BorderTop);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        BorderBottom = new QLabel(BordersWrapper);
        BorderBottom->setObjectName(QString::fromUtf8("BorderBottom"));
        BorderBottom->setMinimumSize(QSize(0, 5));
        BorderBottom->setMaximumSize(QSize(16777215, 5));
        BorderBottom->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(BorderBottom);

        ChunkWrapper = new QFrame(ProgressBar_2);
        ChunkWrapper->setObjectName(QString::fromUtf8("ChunkWrapper"));
        ChunkWrapper->setGeometry(QRect(0, 4, 261, 42));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ChunkWrapper->sizePolicy().hasHeightForWidth());
        ChunkWrapper->setSizePolicy(sizePolicy2);
        ChunkWrapper->setStyleSheet(QString::fromUtf8(""));
        ChunkWrapper->setFrameShape(QFrame::StyledPanel);
        ChunkWrapper->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(ChunkWrapper);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(42, 0, 42, 0);
        ProgressBarChunk = new QLabel(ChunkWrapper);
        ProgressBarChunk->setObjectName(QString::fromUtf8("ProgressBarChunk"));
        ProgressBarChunk->setMinimumSize(QSize(0, 27));
        ProgressBarChunk->setMaximumSize(QSize(16777215, 27));
        ProgressBarChunk->setStyleSheet(QString::fromUtf8(""));
        ProgressBarChunk->setLineWidth(0);
        ProgressBarChunk->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(ProgressBarChunk);

        ChunkShifter = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(ChunkShifter);

        ShadowWrapper = new QFrame(ProgressBar_2);
        ShadowWrapper->setObjectName(QString::fromUtf8("ShadowWrapper"));
        ShadowWrapper->setGeometry(QRect(0, 2, 261, 46));
        ShadowWrapper->setStyleSheet(QString::fromUtf8(""));
        ShadowWrapper->setFrameShape(QFrame::StyledPanel);
        ShadowWrapper->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(ShadowWrapper);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(43, 8, 43, 9);
        Shadow = new QLabel(ShadowWrapper);
        Shadow->setObjectName(QString::fromUtf8("Shadow"));
        Shadow->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(Shadow);

        TipsWrapper = new QFrame(ProgressBar_2);
        TipsWrapper->setObjectName(QString::fromUtf8("TipsWrapper"));
        TipsWrapper->setGeometry(QRect(0, 4, 261, 42));
        TipsWrapper->setStyleSheet(QString::fromUtf8(""));
        TipsWrapper->setFrameShape(QFrame::StyledPanel);
        TipsWrapper->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(TipsWrapper);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        TipLeft = new QLabel(TipsWrapper);
        TipLeft->setObjectName(QString::fromUtf8("TipLeft"));
        TipLeft->setMinimumSize(QSize(51, 42));
        TipLeft->setMaximumSize(QSize(40, 42));
        TipLeft->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(TipLeft, 0, 1, 1, 1);

        TipRight = new QLabel(TipsWrapper);
        TipRight->setObjectName(QString::fromUtf8("TipRight"));
        TipRight->setMinimumSize(QSize(51, 42));
        TipRight->setMaximumSize(QSize(51, 42));
        TipRight->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(TipRight, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        ChunkWrapper->raise();
        BordersWrapper->raise();
        ShadowWrapper->raise();
        SeparatorWrapper->raise();
        TipsWrapper->raise();
        LabelWithTooltipWrapper->raise();

        retranslateUi(ProgressBar_2);

        QMetaObject::connectSlotsByName(ProgressBar_2);
    } // setupUi

    void retranslateUi(QWidget *ProgressBar_2)
    {
        ProgressBar_2->setWindowTitle(QCoreApplication::translate("ProgressBar_2", "Form", nullptr));
        BorderTop->setText(QString());
        BorderBottom->setText(QString());
        ProgressBarChunk->setText(QString());
        Shadow->setText(QString());
        TipLeft->setText(QString());
        TipRight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProgressBar_2: public Ui_ProgressBar_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBAR_2_H

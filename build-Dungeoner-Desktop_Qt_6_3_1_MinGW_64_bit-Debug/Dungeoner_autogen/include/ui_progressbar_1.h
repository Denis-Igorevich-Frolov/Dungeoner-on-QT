/********************************************************************************
** Form generated from reading UI file 'progressbar_1.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBAR_1_H
#define UI_PROGRESSBAR_1_H

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

class Ui_ProgressBar_1
{
public:
    QFrame *TipsWrapper;
    QGridLayout *gridLayout_2;
    QLabel *TipLeft;
    QLabel *TipRight;
    QSpacerItem *horizontalSpacer_2;
    QFrame *ChunkWrapper;
    QHBoxLayout *horizontalLayout;
    QLabel *ProgressBarChunk;
    QSpacerItem *ChunkShifter;
    QFrame *BordersWrapper;
    QVBoxLayout *verticalLayout;
    QLabel *BorderTop;
    QSpacerItem *verticalSpacer;
    QLabel *BorderBottom;
    QFrame *ShadowWrapper;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Shadow;

    void setupUi(QWidget *ProgressBar_1)
    {
        if (ProgressBar_1->objectName().isEmpty())
            ProgressBar_1->setObjectName(QString::fromUtf8("ProgressBar_1"));
        ProgressBar_1->resize(307, 42);
        ProgressBar_1->setMinimumSize(QSize(0, 42));
        ProgressBar_1->setMaximumSize(QSize(16777215, 42));
        TipsWrapper = new QFrame(ProgressBar_1);
        TipsWrapper->setObjectName(QString::fromUtf8("TipsWrapper"));
        TipsWrapper->setGeometry(QRect(0, 0, 261, 42));
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
        TipLeft->setStyleSheet(QString::fromUtf8("background-image: url(:/Text-Block-1/Textures PNG/ProgressBarTip-L-1.png);\n"
"background-repeat: no-repeat;"));

        gridLayout_2->addWidget(TipLeft, 0, 1, 1, 1);

        TipRight = new QLabel(TipsWrapper);
        TipRight->setObjectName(QString::fromUtf8("TipRight"));
        TipRight->setMinimumSize(QSize(51, 42));
        TipRight->setMaximumSize(QSize(51, 42));
        TipRight->setStyleSheet(QString::fromUtf8("background-image: url(:/Text-Block-1/Textures PNG/ProgressBarTip-R-1.png);\n"
"background-repeat: no-repeat;"));

        gridLayout_2->addWidget(TipRight, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        ChunkWrapper = new QFrame(ProgressBar_1);
        ChunkWrapper->setObjectName(QString::fromUtf8("ChunkWrapper"));
        ChunkWrapper->setGeometry(QRect(0, 0, 261, 42));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChunkWrapper->sizePolicy().hasHeightForWidth());
        ChunkWrapper->setSizePolicy(sizePolicy);
        ChunkWrapper->setStyleSheet(QString::fromUtf8(""));
        ChunkWrapper->setFrameShape(QFrame::StyledPanel);
        ChunkWrapper->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(ChunkWrapper);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(43, 0, 43, 0);
        ProgressBarChunk = new QLabel(ChunkWrapper);
        ProgressBarChunk->setObjectName(QString::fromUtf8("ProgressBarChunk"));
        ProgressBarChunk->setMinimumSize(QSize(0, 27));
        ProgressBarChunk->setMaximumSize(QSize(16777215, 27));
        ProgressBarChunk->setStyleSheet(QString::fromUtf8("background: white;"));
        ProgressBarChunk->setLineWidth(0);
        ProgressBarChunk->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(ProgressBarChunk);

        ChunkShifter = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(ChunkShifter);

        BordersWrapper = new QFrame(ProgressBar_1);
        BordersWrapper->setObjectName(QString::fromUtf8("BordersWrapper"));
        BordersWrapper->setGeometry(QRect(0, 0, 261, 42));
        BordersWrapper->setFrameShape(QFrame::StyledPanel);
        BordersWrapper->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(BordersWrapper);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(47, 6, 47, 7);
        BorderTop = new QLabel(BordersWrapper);
        BorderTop->setObjectName(QString::fromUtf8("BorderTop"));
        BorderTop->setMinimumSize(QSize(0, 5));
        BorderTop->setMaximumSize(QSize(16777215, 5));
        BorderTop->setStyleSheet(QString::fromUtf8("background-image: url(:/Text-Block-1/Textures PNG/Border-T-1.png);"));

        verticalLayout->addWidget(BorderTop);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        BorderBottom = new QLabel(BordersWrapper);
        BorderBottom->setObjectName(QString::fromUtf8("BorderBottom"));
        BorderBottom->setMinimumSize(QSize(0, 5));
        BorderBottom->setMaximumSize(QSize(16777215, 5));
        BorderBottom->setStyleSheet(QString::fromUtf8("background-image: url(:/Text-Block-1/Textures PNG/Border-B-1.png);"));

        verticalLayout->addWidget(BorderBottom);

        ShadowWrapper = new QFrame(ProgressBar_1);
        ShadowWrapper->setObjectName(QString::fromUtf8("ShadowWrapper"));
        ShadowWrapper->setGeometry(QRect(0, 0, 261, 42));
        ShadowWrapper->setStyleSheet(QString::fromUtf8(""));
        ShadowWrapper->setFrameShape(QFrame::StyledPanel);
        ShadowWrapper->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(ShadowWrapper);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(43, 8, 43, 9);
        Shadow = new QLabel(ShadowWrapper);
        Shadow->setObjectName(QString::fromUtf8("Shadow"));
        Shadow->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 100), stop:0.5 rgba(116, 116, 116, 0), stop:1 rgba(0, 0, 0, 100));"));

        horizontalLayout_2->addWidget(Shadow);

        ChunkWrapper->raise();
        BordersWrapper->raise();
        ShadowWrapper->raise();
        TipsWrapper->raise();

        retranslateUi(ProgressBar_1);

        QMetaObject::connectSlotsByName(ProgressBar_1);
    } // setupUi

    void retranslateUi(QWidget *ProgressBar_1)
    {
        ProgressBar_1->setWindowTitle(QCoreApplication::translate("ProgressBar_1", "Form", nullptr));
        TipLeft->setText(QString());
        TipRight->setText(QString());
        ProgressBarChunk->setText(QString());
        BorderTop->setText(QString());
        BorderBottom->setText(QString());
        Shadow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProgressBar_1: public Ui_ProgressBar_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBAR_1_H

/********************************************************************************
** Form generated from reading UI file 'tooltip.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLTIP_H
#define UI_TOOLTIP_H

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

class Ui_Tooltip
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_8;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QWidget *Tooltip)
    {
        if (Tooltip->objectName().isEmpty())
            Tooltip->setObjectName(QString::fromUtf8("Tooltip"));
        Tooltip->resize(420, 273);
        gridLayout = new QGridLayout(Tooltip);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(Tooltip);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMaximumSize(QSize(16777215, 10));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(0, 1));
        label_5->setMaximumSize(QSize(16777215, 1));
        label_5->setStyleSheet(QString::fromUtf8("background: red;"));

        verticalLayout_2->addWidget(label_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        frame = new QFrame(Tooltip);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(16777215, 10));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(0, 1));
        label_7->setMaximumSize(QSize(16777215, 1));
        label_7->setStyleSheet(QString::fromUtf8("background: red;"));

        verticalLayout->addWidget(label_7);


        gridLayout->addWidget(frame, 3, 1, 1, 2);

        label_3 = new QLabel(Tooltip);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(9, 10));
        label_3->setMaximumSize(QSize(9, 10));
        label_3->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(Tooltip);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(9, 10));
        label_2->setMaximumSize(QSize(9, 10));
        label_2->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(Tooltip);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(9, 10));
        label_6->setMaximumSize(QSize(9, 10));
        label_6->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        label_8 = new QLabel(Tooltip);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(9, 10));
        label_8->setMaximumSize(QSize(9, 10));
        label_8->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout->addWidget(label_8, 3, 3, 1, 1);

        frame_3 = new QFrame(Tooltip);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setMaximumSize(QSize(9, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(1, 0));
        label_4->setMaximumSize(QSize(1, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("background: red;"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(frame_3, 1, 0, 2, 1);

        frame_4 = new QFrame(Tooltip);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy1.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy1);
        frame_4->setMaximumSize(QSize(9, 16777215));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(1, 0));
        label->setMaximumSize(QSize(1, 16777215));
        label->setStyleSheet(QString::fromUtf8("background: red;"));

        horizontalLayout_2->addWidget(label);


        gridLayout->addWidget(frame_4, 1, 3, 2, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);

        gridLayout->addLayout(verticalLayout_3, 1, 1, 2, 1);


        retranslateUi(Tooltip);

        QMetaObject::connectSlotsByName(Tooltip);
    } // setupUi

    void retranslateUi(QWidget *Tooltip)
    {
        Tooltip->setWindowTitle(QCoreApplication::translate("Tooltip", "Form", nullptr));
        label_5->setText(QString());
        label_7->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        label_6->setText(QString());
        label_8->setText(QString());
        label_4->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tooltip: public Ui_Tooltip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLTIP_H

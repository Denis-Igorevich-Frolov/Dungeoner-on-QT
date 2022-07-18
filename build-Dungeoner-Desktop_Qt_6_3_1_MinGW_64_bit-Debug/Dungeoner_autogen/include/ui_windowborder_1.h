/********************************************************************************
** Form generated from reading UI file 'windowborder_1.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWBORDER_1_H
#define UI_WINDOWBORDER_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowBorder_1
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_6;
    QLabel *BottomLeftCorner;
    QHBoxLayout *LeftWraper;
    QSpacerItem *horizontalSpacer;
    QLabel *LeftBorder;
    QSpacerItem *horizontalSpacer_2;
    QLabel *BottomRightCorner;
    QLabel *TopRightCorner;
    QLabel *TopLeftCorner;
    QHBoxLayout *RightWraper;
    QSpacerItem *horizontalSpacer_4;
    QLabel *RightBorder;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *TopWraper;
    QSpacerItem *verticalSpacer;
    QLabel *TopBorder;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *BottomWraper;
    QSpacerItem *verticalSpacer_4;
    QLabel *BottomBorder;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *WindowBorder_1)
    {
        if (WindowBorder_1->objectName().isEmpty())
            WindowBorder_1->setObjectName(QString::fromUtf8("WindowBorder_1"));
        WindowBorder_1->resize(870, 580);
        horizontalLayout = new QHBoxLayout(WindowBorder_1);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        BottomLeftCorner = new QLabel(WindowBorder_1);
        BottomLeftCorner->setObjectName(QString::fromUtf8("BottomLeftCorner"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BottomLeftCorner->sizePolicy().hasHeightForWidth());
        BottomLeftCorner->setSizePolicy(sizePolicy);
        BottomLeftCorner->setMinimumSize(QSize(25, 25));
        BottomLeftCorner->setMaximumSize(QSize(25, 25));
        BottomLeftCorner->setStyleSheet(QString::fromUtf8("background: black;"));
        BottomLeftCorner->setAlignment(Qt::AlignCenter);
        BottomLeftCorner->setIndent(0);

        gridLayout_6->addWidget(BottomLeftCorner, 3, 0, 1, 1);

        LeftWraper = new QHBoxLayout();
        LeftWraper->setSpacing(0);
        LeftWraper->setObjectName(QString::fromUtf8("LeftWraper"));
        LeftWraper->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        LeftWraper->addItem(horizontalSpacer);

        LeftBorder = new QLabel(WindowBorder_1);
        LeftBorder->setObjectName(QString::fromUtf8("LeftBorder"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LeftBorder->sizePolicy().hasHeightForWidth());
        LeftBorder->setSizePolicy(sizePolicy1);
        LeftBorder->setMinimumSize(QSize(4, 0));
        LeftBorder->setMaximumSize(QSize(4, 16777215));
        LeftBorder->setLayoutDirection(Qt::LeftToRight);
        LeftBorder->setStyleSheet(QString::fromUtf8("background: red;"));
        LeftBorder->setLineWidth(0);
        LeftBorder->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        LeftBorder->setWordWrap(false);
        LeftBorder->setMargin(0);
        LeftBorder->setIndent(0);

        LeftWraper->addWidget(LeftBorder);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        LeftWraper->addItem(horizontalSpacer_2);


        gridLayout_6->addLayout(LeftWraper, 1, 0, 2, 1);

        BottomRightCorner = new QLabel(WindowBorder_1);
        BottomRightCorner->setObjectName(QString::fromUtf8("BottomRightCorner"));
        sizePolicy.setHeightForWidth(BottomRightCorner->sizePolicy().hasHeightForWidth());
        BottomRightCorner->setSizePolicy(sizePolicy);
        BottomRightCorner->setMinimumSize(QSize(25, 25));
        BottomRightCorner->setMaximumSize(QSize(25, 25));
        BottomRightCorner->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout_6->addWidget(BottomRightCorner, 3, 2, 1, 1);

        TopRightCorner = new QLabel(WindowBorder_1);
        TopRightCorner->setObjectName(QString::fromUtf8("TopRightCorner"));
        sizePolicy.setHeightForWidth(TopRightCorner->sizePolicy().hasHeightForWidth());
        TopRightCorner->setSizePolicy(sizePolicy);
        TopRightCorner->setMinimumSize(QSize(25, 25));
        TopRightCorner->setMaximumSize(QSize(25, 25));
        TopRightCorner->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout_6->addWidget(TopRightCorner, 0, 2, 1, 1);

        TopLeftCorner = new QLabel(WindowBorder_1);
        TopLeftCorner->setObjectName(QString::fromUtf8("TopLeftCorner"));
        sizePolicy.setHeightForWidth(TopLeftCorner->sizePolicy().hasHeightForWidth());
        TopLeftCorner->setSizePolicy(sizePolicy);
        TopLeftCorner->setMinimumSize(QSize(25, 25));
        TopLeftCorner->setMaximumSize(QSize(25, 25));
        TopLeftCorner->setStyleSheet(QString::fromUtf8("background: black;"));
        TopLeftCorner->setAlignment(Qt::AlignCenter);
        TopLeftCorner->setIndent(0);

        gridLayout_6->addWidget(TopLeftCorner, 0, 0, 1, 1);

        RightWraper = new QHBoxLayout();
        RightWraper->setSpacing(0);
        RightWraper->setObjectName(QString::fromUtf8("RightWraper"));
        horizontalSpacer_4 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        RightWraper->addItem(horizontalSpacer_4);

        RightBorder = new QLabel(WindowBorder_1);
        RightBorder->setObjectName(QString::fromUtf8("RightBorder"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(RightBorder->sizePolicy().hasHeightForWidth());
        RightBorder->setSizePolicy(sizePolicy2);
        RightBorder->setMinimumSize(QSize(4, 0));
        RightBorder->setMaximumSize(QSize(4, 16777215));
        RightBorder->setStyleSheet(QString::fromUtf8("background: red;"));
        RightBorder->setAlignment(Qt::AlignCenter);
        RightBorder->setIndent(0);

        RightWraper->addWidget(RightBorder);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        RightWraper->addItem(horizontalSpacer_3);


        gridLayout_6->addLayout(RightWraper, 1, 2, 2, 1);

        TopWraper = new QVBoxLayout();
        TopWraper->setSpacing(0);
        TopWraper->setObjectName(QString::fromUtf8("TopWraper"));
        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        TopWraper->addItem(verticalSpacer);

        TopBorder = new QLabel(WindowBorder_1);
        TopBorder->setObjectName(QString::fromUtf8("TopBorder"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TopBorder->sizePolicy().hasHeightForWidth());
        TopBorder->setSizePolicy(sizePolicy3);
        TopBorder->setMinimumSize(QSize(0, 4));
        TopBorder->setMaximumSize(QSize(16777215, 4));
        TopBorder->setStyleSheet(QString::fromUtf8("background: green;"));
        TopBorder->setLineWidth(0);
        TopBorder->setAlignment(Qt::AlignCenter);
        TopBorder->setIndent(0);

        TopWraper->addWidget(TopBorder);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        TopWraper->addItem(verticalSpacer_2);


        gridLayout_6->addLayout(TopWraper, 0, 1, 1, 1);

        BottomWraper = new QVBoxLayout();
        BottomWraper->setSpacing(0);
        BottomWraper->setObjectName(QString::fromUtf8("BottomWraper"));
        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        BottomWraper->addItem(verticalSpacer_4);

        BottomBorder = new QLabel(WindowBorder_1);
        BottomBorder->setObjectName(QString::fromUtf8("BottomBorder"));
        sizePolicy3.setHeightForWidth(BottomBorder->sizePolicy().hasHeightForWidth());
        BottomBorder->setSizePolicy(sizePolicy3);
        BottomBorder->setMinimumSize(QSize(0, 4));
        BottomBorder->setMaximumSize(QSize(16777215, 4));
        BottomBorder->setStyleSheet(QString::fromUtf8("background: yellow;"));
        BottomBorder->setLineWidth(0);
        BottomBorder->setAlignment(Qt::AlignCenter);
        BottomBorder->setIndent(0);

        BottomWraper->addWidget(BottomBorder);

        verticalSpacer_5 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        BottomWraper->addItem(verticalSpacer_5);


        gridLayout_6->addLayout(BottomWraper, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_6);


        retranslateUi(WindowBorder_1);

        QMetaObject::connectSlotsByName(WindowBorder_1);
    } // setupUi

    void retranslateUi(QWidget *WindowBorder_1)
    {
        WindowBorder_1->setWindowTitle(QCoreApplication::translate("WindowBorder_1", "Form", nullptr));
        BottomLeftCorner->setText(QString());
        LeftBorder->setText(QString());
        BottomRightCorner->setText(QString());
        TopRightCorner->setText(QString());
        TopLeftCorner->setText(QString());
        RightBorder->setText(QString());
        TopBorder->setText(QString());
        BottomBorder->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindowBorder_1: public Ui_WindowBorder_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWBORDER_1_H

/********************************************************************************
** Form generated from reading UI file 'windowborder_2.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWBORDER_2_H
#define UI_WINDOWBORDER_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowBorder_2
{
public:
    QGridLayout *gridLayout;
    QLabel *BottomLeftCorner;
    QLabel *TopRightCorner;
    QLabel *BottomRightCorner;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *BottomBorder;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *LeftBorder;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *RightBorder;
    QLabel *TopLeftCorner;
    QVBoxLayout *verticalLayout_2;
    QLabel *TopBorder;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *WindowBorder_2)
    {
        if (WindowBorder_2->objectName().isEmpty())
            WindowBorder_2->setObjectName(QString::fromUtf8("WindowBorder_2"));
        WindowBorder_2->resize(286, 240);
        gridLayout = new QGridLayout(WindowBorder_2);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        BottomLeftCorner = new QLabel(WindowBorder_2);
        BottomLeftCorner->setObjectName(QString::fromUtf8("BottomLeftCorner"));
        BottomLeftCorner->setMinimumSize(QSize(9, 10));
        BottomLeftCorner->setMaximumSize(QSize(9, 10));
        BottomLeftCorner->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout->addWidget(BottomLeftCorner, 2, 0, 1, 1);

        TopRightCorner = new QLabel(WindowBorder_2);
        TopRightCorner->setObjectName(QString::fromUtf8("TopRightCorner"));
        TopRightCorner->setMinimumSize(QSize(9, 10));
        TopRightCorner->setMaximumSize(QSize(9, 10));
        TopRightCorner->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout->addWidget(TopRightCorner, 0, 2, 1, 1);

        BottomRightCorner = new QLabel(WindowBorder_2);
        BottomRightCorner->setObjectName(QString::fromUtf8("BottomRightCorner"));
        BottomRightCorner->setMinimumSize(QSize(9, 10));
        BottomRightCorner->setMaximumSize(QSize(9, 10));
        BottomRightCorner->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout->addWidget(BottomRightCorner, 2, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        BottomBorder = new QLabel(WindowBorder_2);
        BottomBorder->setObjectName(QString::fromUtf8("BottomBorder"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BottomBorder->sizePolicy().hasHeightForWidth());
        BottomBorder->setSizePolicy(sizePolicy);
        BottomBorder->setMinimumSize(QSize(0, 1));
        BottomBorder->setMaximumSize(QSize(16777215, 1));
        BottomBorder->setStyleSheet(QString::fromUtf8("background: red;"));

        verticalLayout_4->addWidget(BottomBorder);


        gridLayout->addLayout(verticalLayout_4, 2, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);

        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LeftBorder = new QLabel(WindowBorder_2);
        LeftBorder->setObjectName(QString::fromUtf8("LeftBorder"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LeftBorder->sizePolicy().hasHeightForWidth());
        LeftBorder->setSizePolicy(sizePolicy1);
        LeftBorder->setMinimumSize(QSize(1, 0));
        LeftBorder->setMaximumSize(QSize(1, 16777215));
        LeftBorder->setStyleSheet(QString::fromUtf8("background: red;"));

        horizontalLayout->addWidget(LeftBorder);

        horizontalSpacer = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        RightBorder = new QLabel(WindowBorder_2);
        RightBorder->setObjectName(QString::fromUtf8("RightBorder"));
        sizePolicy1.setHeightForWidth(RightBorder->sizePolicy().hasHeightForWidth());
        RightBorder->setSizePolicy(sizePolicy1);
        RightBorder->setMinimumSize(QSize(1, 0));
        RightBorder->setMaximumSize(QSize(1, 16777215));
        RightBorder->setStyleSheet(QString::fromUtf8("background: red;"));

        horizontalLayout_2->addWidget(RightBorder);


        gridLayout->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        TopLeftCorner = new QLabel(WindowBorder_2);
        TopLeftCorner->setObjectName(QString::fromUtf8("TopLeftCorner"));
        TopLeftCorner->setMinimumSize(QSize(9, 10));
        TopLeftCorner->setMaximumSize(QSize(9, 10));
        TopLeftCorner->setStyleSheet(QString::fromUtf8("background: black;"));

        gridLayout->addWidget(TopLeftCorner, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        TopBorder = new QLabel(WindowBorder_2);
        TopBorder->setObjectName(QString::fromUtf8("TopBorder"));
        sizePolicy.setHeightForWidth(TopBorder->sizePolicy().hasHeightForWidth());
        TopBorder->setSizePolicy(sizePolicy);
        TopBorder->setMinimumSize(QSize(0, 1));
        TopBorder->setMaximumSize(QSize(16777215, 1));
        TopBorder->setStyleSheet(QString::fromUtf8("background: red;"));

        verticalLayout_2->addWidget(TopBorder);

        verticalSpacer_2 = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        retranslateUi(WindowBorder_2);

        QMetaObject::connectSlotsByName(WindowBorder_2);
    } // setupUi

    void retranslateUi(QWidget *WindowBorder_2)
    {
        WindowBorder_2->setWindowTitle(QCoreApplication::translate("WindowBorder_2", "Form", nullptr));
        BottomLeftCorner->setText(QString());
        TopRightCorner->setText(QString());
        BottomRightCorner->setText(QString());
        BottomBorder->setText(QString());
        LeftBorder->setText(QString());
        RightBorder->setText(QString());
        TopLeftCorner->setText(QString());
        TopBorder->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindowBorder_2: public Ui_WindowBorder_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWBORDER_2_H

/********************************************************************************
** Form generated from reading UI file 'windowborder_3.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWBORDER_3_H
#define UI_WINDOWBORDER_3_H

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

class Ui_WindowBorder_3
{
public:
    QFrame *Wrapper1;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *TopLeftCorner;
    QLabel *TopRightCorner;
    QLabel *BottomRightCorner;
    QLabel *BottomLeftCorner;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QFrame *Wrapper2;
    QGridLayout *gridLayout_2;
    QFrame *OpenworkBorderWrapperTop;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *OpenworkBorderTop;
    QSpacerItem *verticalSpacer_4;
    QLabel *BottomRightSpacer;
    QLabel *TopLeftSpacer;
    QLabel *TopRightSpacer;
    QLabel *BottomLeftSpacer;
    QFrame *OpenworkBorderWrapperBottom;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_6;
    QLabel *OpenworkBorderBottom;
    QSpacerItem *verticalSpacer_5;
    QFrame *OpenworkBorderWrapperLeft;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *OpenworkBorderLeft;
    QSpacerItem *horizontalSpacer_4;
    QFrame *OpenworkBorderWrapperRight;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *OpenworkBorderRight;
    QSpacerItem *horizontalSpacer_5;
    QFrame *Wrapper3;
    QGridLayout *gridLayout_3;
    QLabel *SolidBorder1;
    QFrame *Wrapper4;
    QGridLayout *gridLayout_4;
    QLabel *SolidBorder2;

    void setupUi(QWidget *WindowBorder_3)
    {
        if (WindowBorder_3->objectName().isEmpty())
            WindowBorder_3->setObjectName(QString::fromUtf8("WindowBorder_3"));
        WindowBorder_3->resize(400, 300);
        Wrapper1 = new QFrame(WindowBorder_3);
        Wrapper1->setObjectName(QString::fromUtf8("Wrapper1"));
        Wrapper1->setGeometry(QRect(0, 0, 400, 301));
        Wrapper1->setFrameShape(QFrame::StyledPanel);
        Wrapper1->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(Wrapper1);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        TopLeftCorner = new QLabel(Wrapper1);
        TopLeftCorner->setObjectName(QString::fromUtf8("TopLeftCorner"));
        TopLeftCorner->setMinimumSize(QSize(23, 23));
        TopLeftCorner->setMaximumSize(QSize(23, 23));
        TopLeftCorner->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(TopLeftCorner, 0, 0, 1, 1);

        TopRightCorner = new QLabel(Wrapper1);
        TopRightCorner->setObjectName(QString::fromUtf8("TopRightCorner"));
        TopRightCorner->setMinimumSize(QSize(23, 23));
        TopRightCorner->setMaximumSize(QSize(23, 23));
        TopRightCorner->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(TopRightCorner, 0, 2, 1, 1);

        BottomRightCorner = new QLabel(Wrapper1);
        BottomRightCorner->setObjectName(QString::fromUtf8("BottomRightCorner"));
        BottomRightCorner->setMinimumSize(QSize(23, 23));
        BottomRightCorner->setMaximumSize(QSize(23, 23));
        BottomRightCorner->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(BottomRightCorner, 2, 2, 1, 1);

        BottomLeftCorner = new QLabel(Wrapper1);
        BottomLeftCorner->setObjectName(QString::fromUtf8("BottomLeftCorner"));
        BottomLeftCorner->setMinimumSize(QSize(23, 23));
        BottomLeftCorner->setMaximumSize(QSize(23, 23));
        BottomLeftCorner->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(BottomLeftCorner, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 1, 1);

        Wrapper2 = new QFrame(WindowBorder_3);
        Wrapper2->setObjectName(QString::fromUtf8("Wrapper2"));
        Wrapper2->setGeometry(QRect(0, 0, 400, 300));
        Wrapper2->setFrameShape(QFrame::StyledPanel);
        Wrapper2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(Wrapper2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        OpenworkBorderWrapperTop = new QFrame(Wrapper2);
        OpenworkBorderWrapperTop->setObjectName(QString::fromUtf8("OpenworkBorderWrapperTop"));
        OpenworkBorderWrapperTop->setMinimumSize(QSize(0, 21));
        OpenworkBorderWrapperTop->setMaximumSize(QSize(16777215, 21));
        OpenworkBorderWrapperTop->setFrameShape(QFrame::StyledPanel);
        OpenworkBorderWrapperTop->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(OpenworkBorderWrapperTop);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        OpenworkBorderTop = new QLabel(OpenworkBorderWrapperTop);
        OpenworkBorderTop->setObjectName(QString::fromUtf8("OpenworkBorderTop"));
        OpenworkBorderTop->setMinimumSize(QSize(0, 4));
        OpenworkBorderTop->setMaximumSize(QSize(16777215, 4));
        OpenworkBorderTop->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(OpenworkBorderTop);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        gridLayout_2->addWidget(OpenworkBorderWrapperTop, 0, 1, 1, 1);

        BottomRightSpacer = new QLabel(Wrapper2);
        BottomRightSpacer->setObjectName(QString::fromUtf8("BottomRightSpacer"));
        BottomRightSpacer->setMinimumSize(QSize(21, 21));
        BottomRightSpacer->setMaximumSize(QSize(21, 21));

        gridLayout_2->addWidget(BottomRightSpacer, 2, 2, 1, 1);

        TopLeftSpacer = new QLabel(Wrapper2);
        TopLeftSpacer->setObjectName(QString::fromUtf8("TopLeftSpacer"));
        TopLeftSpacer->setMinimumSize(QSize(21, 21));
        TopLeftSpacer->setMaximumSize(QSize(21, 21));

        gridLayout_2->addWidget(TopLeftSpacer, 0, 0, 1, 1);

        TopRightSpacer = new QLabel(Wrapper2);
        TopRightSpacer->setObjectName(QString::fromUtf8("TopRightSpacer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TopRightSpacer->sizePolicy().hasHeightForWidth());
        TopRightSpacer->setSizePolicy(sizePolicy);
        TopRightSpacer->setMinimumSize(QSize(21, 21));
        TopRightSpacer->setMaximumSize(QSize(21, 21));

        gridLayout_2->addWidget(TopRightSpacer, 0, 2, 1, 1);

        BottomLeftSpacer = new QLabel(Wrapper2);
        BottomLeftSpacer->setObjectName(QString::fromUtf8("BottomLeftSpacer"));
        BottomLeftSpacer->setMinimumSize(QSize(21, 21));
        BottomLeftSpacer->setMaximumSize(QSize(21, 21));

        gridLayout_2->addWidget(BottomLeftSpacer, 2, 0, 1, 1);

        OpenworkBorderWrapperBottom = new QFrame(Wrapper2);
        OpenworkBorderWrapperBottom->setObjectName(QString::fromUtf8("OpenworkBorderWrapperBottom"));
        OpenworkBorderWrapperBottom->setMinimumSize(QSize(0, 21));
        OpenworkBorderWrapperBottom->setMaximumSize(QSize(16777215, 21));
        OpenworkBorderWrapperBottom->setFrameShape(QFrame::StyledPanel);
        OpenworkBorderWrapperBottom->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(OpenworkBorderWrapperBottom);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        OpenworkBorderBottom = new QLabel(OpenworkBorderWrapperBottom);
        OpenworkBorderBottom->setObjectName(QString::fromUtf8("OpenworkBorderBottom"));
        OpenworkBorderBottom->setMinimumSize(QSize(0, 4));
        OpenworkBorderBottom->setMaximumSize(QSize(16777215, 4));
        OpenworkBorderBottom->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(OpenworkBorderBottom);

        verticalSpacer_5 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_5);


        gridLayout_2->addWidget(OpenworkBorderWrapperBottom, 2, 1, 1, 1);

        OpenworkBorderWrapperLeft = new QFrame(Wrapper2);
        OpenworkBorderWrapperLeft->setObjectName(QString::fromUtf8("OpenworkBorderWrapperLeft"));
        OpenworkBorderWrapperLeft->setMinimumSize(QSize(21, 0));
        OpenworkBorderWrapperLeft->setMaximumSize(QSize(21, 16777215));
        OpenworkBorderWrapperLeft->setFrameShape(QFrame::StyledPanel);
        OpenworkBorderWrapperLeft->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(OpenworkBorderWrapperLeft);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(1, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        OpenworkBorderLeft = new QLabel(OpenworkBorderWrapperLeft);
        OpenworkBorderLeft->setObjectName(QString::fromUtf8("OpenworkBorderLeft"));
        OpenworkBorderLeft->setMinimumSize(QSize(4, 0));
        OpenworkBorderLeft->setMaximumSize(QSize(4, 16777215));
        OpenworkBorderLeft->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(OpenworkBorderLeft);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        gridLayout_2->addWidget(OpenworkBorderWrapperLeft, 1, 0, 1, 1);

        OpenworkBorderWrapperRight = new QFrame(Wrapper2);
        OpenworkBorderWrapperRight->setObjectName(QString::fromUtf8("OpenworkBorderWrapperRight"));
        OpenworkBorderWrapperRight->setMinimumSize(QSize(21, 0));
        OpenworkBorderWrapperRight->setMaximumSize(QSize(21, 16777215));
        OpenworkBorderWrapperRight->setFrameShape(QFrame::StyledPanel);
        OpenworkBorderWrapperRight->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(OpenworkBorderWrapperRight);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        OpenworkBorderRight = new QLabel(OpenworkBorderWrapperRight);
        OpenworkBorderRight->setObjectName(QString::fromUtf8("OpenworkBorderRight"));
        OpenworkBorderRight->setMinimumSize(QSize(4, 0));
        OpenworkBorderRight->setMaximumSize(QSize(4, 16777215));
        OpenworkBorderRight->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(OpenworkBorderRight);

        horizontalSpacer_5 = new QSpacerItem(1, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        gridLayout_2->addWidget(OpenworkBorderWrapperRight, 1, 2, 1, 1);

        Wrapper3 = new QFrame(WindowBorder_3);
        Wrapper3->setObjectName(QString::fromUtf8("Wrapper3"));
        Wrapper3->setGeometry(QRect(0, 0, 400, 300));
        Wrapper3->setFrameShape(QFrame::StyledPanel);
        Wrapper3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(Wrapper3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        SolidBorder1 = new QLabel(Wrapper3);
        SolidBorder1->setObjectName(QString::fromUtf8("SolidBorder1"));
        SolidBorder1->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(SolidBorder1, 1, 1, 1, 1);

        Wrapper4 = new QFrame(WindowBorder_3);
        Wrapper4->setObjectName(QString::fromUtf8("Wrapper4"));
        Wrapper4->setGeometry(QRect(0, 0, 400, 300));
        Wrapper4->setFrameShape(QFrame::StyledPanel);
        Wrapper4->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(Wrapper4);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(7, 7, 7, 7);
        SolidBorder2 = new QLabel(Wrapper4);
        SolidBorder2->setObjectName(QString::fromUtf8("SolidBorder2"));
        SolidBorder2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(SolidBorder2, 1, 1, 1, 1);

        Wrapper2->raise();
        Wrapper1->raise();
        Wrapper3->raise();
        Wrapper4->raise();

        retranslateUi(WindowBorder_3);

        QMetaObject::connectSlotsByName(WindowBorder_3);
    } // setupUi

    void retranslateUi(QWidget *WindowBorder_3)
    {
        WindowBorder_3->setWindowTitle(QCoreApplication::translate("WindowBorder_3", "Form", nullptr));
        TopLeftCorner->setText(QString());
        TopRightCorner->setText(QString());
        BottomRightCorner->setText(QString());
        BottomLeftCorner->setText(QString());
        OpenworkBorderTop->setText(QString());
        BottomRightSpacer->setText(QString());
        TopLeftSpacer->setText(QString());
        TopRightSpacer->setText(QString());
        BottomLeftSpacer->setText(QString());
        OpenworkBorderBottom->setText(QString());
        OpenworkBorderLeft->setText(QString());
        OpenworkBorderRight->setText(QString());
        SolidBorder1->setText(QString());
        SolidBorder2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindowBorder_3: public Ui_WindowBorder_3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWBORDER_3_H

/********************************************************************************
** Form generated from reading UI file 'openworkbutton.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENWORKBUTTON_H
#define UI_OPENWORKBUTTON_H

#include <CustomWidgets/WindowBorder_3/windowborder_3.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenworkButton
{
public:
    WindowBorder_3 *Border;
    QFrame *DecorativeElementWraper;
    QGridLayout *gridLayout;
    QLabel *DecorativeElement;
    QFrame *BackgroundWraper;
    QGridLayout *gridLayout_3;
    QLabel *Background;
    QPushButton *pushButton;

    void setupUi(QWidget *OpenworkButton)
    {
        if (OpenworkButton->objectName().isEmpty())
            OpenworkButton->setObjectName(QString::fromUtf8("OpenworkButton"));
        OpenworkButton->resize(400, 300);
        Border = new WindowBorder_3(OpenworkButton);
        Border->setObjectName(QString::fromUtf8("Border"));
        Border->setGeometry(QRect(0, 0, 400, 300));
        DecorativeElementWraper = new QFrame(OpenworkButton);
        DecorativeElementWraper->setObjectName(QString::fromUtf8("DecorativeElementWraper"));
        DecorativeElementWraper->setGeometry(QRect(0, 0, 400, 300));
        DecorativeElementWraper->setFrameShape(QFrame::StyledPanel);
        DecorativeElementWraper->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(DecorativeElementWraper);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 10, 9, 10);
        DecorativeElement = new QLabel(DecorativeElementWraper);
        DecorativeElement->setObjectName(QString::fromUtf8("DecorativeElement"));
        DecorativeElement->setStyleSheet(QString::fromUtf8("border-image: url(:/OpenworkButton/Textures PNG/DecorativeButtonElement.png)  0 0 0 0 stretch stretch;"));

        gridLayout->addWidget(DecorativeElement, 0, 0, 1, 1);

        BackgroundWraper = new QFrame(OpenworkButton);
        BackgroundWraper->setObjectName(QString::fromUtf8("BackgroundWraper"));
        BackgroundWraper->setGeometry(QRect(0, 0, 400, 300));
        BackgroundWraper->setFrameShape(QFrame::StyledPanel);
        BackgroundWraper->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(BackgroundWraper);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(7, 7, 7, 7);
        Background = new QLabel(BackgroundWraper);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0.499764, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 9));"));

        gridLayout_3->addWidget(Background, 0, 0, 1, 1);

        pushButton = new QPushButton(OpenworkButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 400, 300));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: none;"));
        BackgroundWraper->raise();
        Border->raise();
        DecorativeElementWraper->raise();
        pushButton->raise();

        retranslateUi(OpenworkButton);

        QMetaObject::connectSlotsByName(OpenworkButton);
    } // setupUi

    void retranslateUi(QWidget *OpenworkButton)
    {
        OpenworkButton->setWindowTitle(QCoreApplication::translate("OpenworkButton", "Form", nullptr));
        DecorativeElement->setText(QString());
        Background->setText(QString());
        pushButton->setText(QCoreApplication::translate("OpenworkButton", "Non", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenworkButton: public Ui_OpenworkButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENWORKBUTTON_H

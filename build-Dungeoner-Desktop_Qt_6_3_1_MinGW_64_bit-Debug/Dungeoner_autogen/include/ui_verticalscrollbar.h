/********************************************************************************
** Form generated from reading UI file 'verticalscrollbar.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERTICALSCROLLBAR_H
#define UI_VERTICALSCROLLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerticalScrollBar
{
public:
    QVBoxLayout *verticalLayout;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *VerticalScrollBar)
    {
        if (VerticalScrollBar->objectName().isEmpty())
            VerticalScrollBar->setObjectName(QString::fromUtf8("VerticalScrollBar"));
        VerticalScrollBar->resize(457, 492);
        VerticalScrollBar->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(VerticalScrollBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalScrollBar = new QScrollBar(VerticalScrollBar);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
"margin: 33px 0px 33px 0px;\n"
"background-color: none;\n"
"border:none;\n"
"width: 24px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"background: none;\n"
"background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Button.png);\n"
"background-position: center ;\n"
"background-repeat: no-repeat;\n"
"min-height: 49px;\n"
"max-height: 49px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical {\n"
"background-color: none;\n"
"}\n"
"\n"
"QScrollBar::sub-page:vertical {\n"
"background-color: none;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"subcontrol-origin: margin;\n"
"border: none;\n"
"height: 33px;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical {\n"
"background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Pike-T.png);\n"
"height:33px;\n"
"}\n"
"\n"
"QScrollBar::down-arrow:vertical { \n"
"background-image: url(:/Text-Block-1/Textures PNG/Vertical-Slider-Pike-B.png);\n"
"height:33px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"subcontrol-origin: margin;\n"
"borde"
                        "r: none;\n"
"height:33px;\n"
"}"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(verticalScrollBar);


        retranslateUi(VerticalScrollBar);

        QMetaObject::connectSlotsByName(VerticalScrollBar);
    } // setupUi

    void retranslateUi(QWidget *VerticalScrollBar)
    {
        VerticalScrollBar->setWindowTitle(QCoreApplication::translate("VerticalScrollBar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerticalScrollBar: public Ui_VerticalScrollBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERTICALSCROLLBAR_H

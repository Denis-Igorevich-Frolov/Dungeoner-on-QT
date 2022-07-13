/********************************************************************************
** Form generated from reading UI file 'characterwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERWINDOW_H
#define UI_CHARACTERWINDOW_H

#include <CustomWidget/PrimarySkillSignature/primaryskillsignature.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterWindow
{
public:
    QFrame *frame;
    PrimarySkillSignature *widget;
    PrimarySkillSignature *widget_2;
    PrimarySkillSignature *widget_3;
    PrimarySkillSignature *widget_4;
    PrimarySkillSignature *widget_6;
    PrimarySkillSignature *widget_5;

    void setupUi(QWidget *CharacterWindow)
    {
        if (CharacterWindow->objectName().isEmpty())
            CharacterWindow->setObjectName(QString::fromUtf8("CharacterWindow"));
        CharacterWindow->resize(1920, 1080);
        CharacterWindow->setStyleSheet(QString::fromUtf8("background-color: #130a0f;"));
        frame = new QFrame(CharacterWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(100, 80, 611, 58));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new PrimarySkillSignature(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 111, 58));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(111, 58));
        widget->setMaximumSize(QSize(111, 58));
        widget->setStyleSheet(QString::fromUtf8("background: black;"));
        widget_2 = new PrimarySkillSignature(frame);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(100, 0, 111, 58));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(111, 58));
        widget_2->setMaximumSize(QSize(111, 58));
        widget_2->setStyleSheet(QString::fromUtf8("background: black;"));
        widget_3 = new PrimarySkillSignature(frame);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(200, 0, 111, 58));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setMinimumSize(QSize(111, 58));
        widget_3->setMaximumSize(QSize(111, 58));
        widget_3->setStyleSheet(QString::fromUtf8("background: black;"));
        widget_4 = new PrimarySkillSignature(frame);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(300, 0, 111, 58));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        widget_4->setMinimumSize(QSize(111, 58));
        widget_4->setMaximumSize(QSize(111, 58));
        widget_4->setStyleSheet(QString::fromUtf8("background: black;"));
        widget_6 = new PrimarySkillSignature(frame);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(400, 0, 111, 58));
        sizePolicy.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy);
        widget_6->setMinimumSize(QSize(111, 58));
        widget_6->setMaximumSize(QSize(111, 58));
        widget_6->setStyleSheet(QString::fromUtf8("background: black;"));
        widget_5 = new PrimarySkillSignature(frame);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(500, 0, 111, 58));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setMinimumSize(QSize(111, 58));
        widget_5->setMaximumSize(QSize(111, 58));
        widget_5->setStyleSheet(QString::fromUtf8("background: black;"));

        retranslateUi(CharacterWindow);

        QMetaObject::connectSlotsByName(CharacterWindow);
    } // setupUi

    void retranslateUi(QWidget *CharacterWindow)
    {
        CharacterWindow->setWindowTitle(QCoreApplication::translate("CharacterWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharacterWindow: public Ui_CharacterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERWINDOW_H

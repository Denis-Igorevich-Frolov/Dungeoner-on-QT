/********************************************************************************
** Form generated from reading UI file 'tooltip.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLTIP_H
#define UI_TOOLTIP_H

#include <CustomWidgets/WindowBorder_2/windowborder_2.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tooltip
{
public:
    WindowBorder_2 *Border;
    QLabel *Background;
    QFrame *Content;

    void setupUi(QWidget *Tooltip)
    {
        if (Tooltip->objectName().isEmpty())
            Tooltip->setObjectName(QString::fromUtf8("Tooltip"));
        Tooltip->resize(271, 271);
        Border = new WindowBorder_2(Tooltip);
        Border->setObjectName(QString::fromUtf8("Border"));
        Border->setGeometry(QRect(0, 0, 271, 271));
        Background = new QLabel(Tooltip);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 271, 271));
        Background->setStyleSheet(QString::fromUtf8(""));
        Content = new QFrame(Tooltip);
        Content->setObjectName(QString::fromUtf8("Content"));
        Content->setGeometry(QRect(0, 0, 271, 271));
        Content->setFrameShape(QFrame::StyledPanel);
        Content->setFrameShadow(QFrame::Raised);
        Background->raise();
        Border->raise();
        Content->raise();

        retranslateUi(Tooltip);

        QMetaObject::connectSlotsByName(Tooltip);
    } // setupUi

    void retranslateUi(QWidget *Tooltip)
    {
        Tooltip->setWindowTitle(QCoreApplication::translate("Tooltip", "Form", nullptr));
        Background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tooltip: public Ui_Tooltip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLTIP_H

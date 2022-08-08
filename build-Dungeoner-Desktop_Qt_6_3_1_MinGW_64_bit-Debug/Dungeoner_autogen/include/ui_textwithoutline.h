/********************************************************************************
** Form generated from reading UI file 'textwithoutline.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTWITHOUTLINE_H
#define UI_TEXTWITHOUTLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextWithOutline
{
public:

    void setupUi(QWidget *TextWithOutline)
    {
        if (TextWithOutline->objectName().isEmpty())
            TextWithOutline->setObjectName(QString::fromUtf8("TextWithOutline"));
        TextWithOutline->resize(400, 300);

        retranslateUi(TextWithOutline);

        QMetaObject::connectSlotsByName(TextWithOutline);
    } // setupUi

    void retranslateUi(QWidget *TextWithOutline)
    {
        TextWithOutline->setWindowTitle(QCoreApplication::translate("TextWithOutline", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextWithOutline: public Ui_TextWithOutline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTWITHOUTLINE_H

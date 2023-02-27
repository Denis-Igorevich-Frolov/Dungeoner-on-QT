/********************************************************************************
** Form generated from reading UI file 'animationinseparatethread.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATIONINSEPARATETHREAD_H
#define UI_ANIMATIONINSEPARATETHREAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnimationInSeparateThread
{
public:
    QLabel *AnimationLabel;

    void setupUi(QWidget *AnimationInSeparateThread)
    {
        if (AnimationInSeparateThread->objectName().isEmpty())
            AnimationInSeparateThread->setObjectName(QString::fromUtf8("AnimationInSeparateThread"));
        AnimationInSeparateThread->resize(100, 100);
        AnimationLabel = new QLabel(AnimationInSeparateThread);
        AnimationLabel->setObjectName(QString::fromUtf8("AnimationLabel"));
        AnimationLabel->setGeometry(QRect(0, 0, 100, 100));

        retranslateUi(AnimationInSeparateThread);

        QMetaObject::connectSlotsByName(AnimationInSeparateThread);
    } // setupUi

    void retranslateUi(QWidget *AnimationInSeparateThread)
    {
        AnimationInSeparateThread->setWindowTitle(QCoreApplication::translate("AnimationInSeparateThread", "Form", nullptr));
        AnimationLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AnimationInSeparateThread: public Ui_AnimationInSeparateThread {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATIONINSEPARATETHREAD_H

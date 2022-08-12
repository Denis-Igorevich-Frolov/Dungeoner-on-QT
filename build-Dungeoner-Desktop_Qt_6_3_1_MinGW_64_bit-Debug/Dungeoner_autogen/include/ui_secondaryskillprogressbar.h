/********************************************************************************
** Form generated from reading UI file 'secondaryskillprogressbar.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDARYSKILLPROGRESSBAR_H
#define UI_SECONDARYSKILLPROGRESSBAR_H

#include <CustomWidgets/ProgressBar_1/progressbar_1.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondarySkillProgressBar
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    ProgressBar_1 *progressBar;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *TipLeft;
    QLabel *Border;
    QLabel *TipRight;

    void setupUi(QWidget *SecondarySkillProgressBar)
    {
        if (SecondarySkillProgressBar->objectName().isEmpty())
            SecondarySkillProgressBar->setObjectName(QString::fromUtf8("SecondarySkillProgressBar"));
        SecondarySkillProgressBar->resize(734, 80);
        verticalLayout = new QVBoxLayout(SecondarySkillProgressBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Name = new QLabel(SecondarySkillProgressBar);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setMinimumSize(QSize(0, 25));
        Name->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(25);
        Name->setFont(font);

        verticalLayout->addWidget(Name, 0, Qt::AlignHCenter);

        progressBar = new ProgressBar_1(SecondarySkillProgressBar);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(734, 42));
        progressBar->setMaximumSize(QSize(734, 42));
        progressBar->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(progressBar);

        frame = new QFrame(SecondarySkillProgressBar);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(474, 13));
        frame->setMaximumSize(QSize(474, 13));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        TipLeft = new QLabel(frame);
        TipLeft->setObjectName(QString::fromUtf8("TipLeft"));
        TipLeft->setMinimumSize(QSize(19, 11));
        TipLeft->setMaximumSize(QSize(19, 11));
        TipLeft->setStyleSheet(QString::fromUtf8("background: black;"));

        horizontalLayout->addWidget(TipLeft, 0, Qt::AlignVCenter);

        Border = new QLabel(frame);
        Border->setObjectName(QString::fromUtf8("Border"));
        Border->setMinimumSize(QSize(0, 1));
        Border->setMaximumSize(QSize(16777215, 1));
        Border->setStyleSheet(QString::fromUtf8("background: black;"));

        horizontalLayout->addWidget(Border, 0, Qt::AlignVCenter);

        TipRight = new QLabel(frame);
        TipRight->setObjectName(QString::fromUtf8("TipRight"));
        TipRight->setMinimumSize(QSize(19, 11));
        TipRight->setMaximumSize(QSize(19, 11));
        TipRight->setStyleSheet(QString::fromUtf8("background: black;"));

        horizontalLayout->addWidget(TipRight, 0, Qt::AlignVCenter);


        verticalLayout->addWidget(frame, 0, Qt::AlignHCenter);


        retranslateUi(SecondarySkillProgressBar);

        QMetaObject::connectSlotsByName(SecondarySkillProgressBar);
    } // setupUi

    void retranslateUi(QWidget *SecondarySkillProgressBar)
    {
        SecondarySkillProgressBar->setWindowTitle(QCoreApplication::translate("SecondarySkillProgressBar", "Form", nullptr));
        Name->setText(QCoreApplication::translate("SecondarySkillProgressBar", "NON", nullptr));
        TipLeft->setText(QString());
        Border->setText(QString());
        TipRight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SecondarySkillProgressBar: public Ui_SecondarySkillProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDARYSKILLPROGRESSBAR_H

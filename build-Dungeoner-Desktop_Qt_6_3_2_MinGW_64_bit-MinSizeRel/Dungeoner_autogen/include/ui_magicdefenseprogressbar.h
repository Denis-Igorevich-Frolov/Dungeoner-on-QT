/********************************************************************************
** Form generated from reading UI file 'magicdefenseprogressbar.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGICDEFENSEPROGRESSBAR_H
#define UI_MAGICDEFENSEPROGRESSBAR_H

#include <CustomWidgets/ProgressBar_2/progressbar_2.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MagicDefenseProgressBar
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    ProgressBar_2 *progressBar;

    void setupUi(QWidget *MagicDefenseProgressBar)
    {
        if (MagicDefenseProgressBar->objectName().isEmpty())
            MagicDefenseProgressBar->setObjectName(QString::fromUtf8("MagicDefenseProgressBar"));
        MagicDefenseProgressBar->resize(734, 80);
        verticalLayout = new QVBoxLayout(MagicDefenseProgressBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Name = new QLabel(MagicDefenseProgressBar);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setMinimumSize(QSize(0, 25));
        Name->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(25);
        Name->setFont(font);

        verticalLayout->addWidget(Name, 0, Qt::AlignHCenter);

        progressBar = new ProgressBar_2(MagicDefenseProgressBar);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(734, 50));
        progressBar->setMaximumSize(QSize(734, 50));
        progressBar->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(progressBar, 0, Qt::AlignBottom);


        retranslateUi(MagicDefenseProgressBar);

        QMetaObject::connectSlotsByName(MagicDefenseProgressBar);
    } // setupUi

    void retranslateUi(QWidget *MagicDefenseProgressBar)
    {
        MagicDefenseProgressBar->setWindowTitle(QCoreApplication::translate("MagicDefenseProgressBar", "Form", nullptr));
        Name->setText(QCoreApplication::translate("MagicDefenseProgressBar", "NON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MagicDefenseProgressBar: public Ui_MagicDefenseProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGICDEFENSEPROGRESSBAR_H

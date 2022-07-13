/********************************************************************************
** Form generated from reading UI file 'primaryskillsignature.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMARYSKILLSIGNATURE_H
#define UI_PRIMARYSKILLSIGNATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimarySkillSignature
{
public:
    QLabel *labelLeft;
    QLabel *labelRight;
    QPushButton *ButtonTop;
    QPushButton *ButtonBottom;
    QLabel *labelCenter;
    QPushButton *ButtonText;

    void setupUi(QWidget *PrimarySkillSignature)
    {
        if (PrimarySkillSignature->objectName().isEmpty())
            PrimarySkillSignature->setObjectName(QString::fromUtf8("PrimarySkillSignature"));
        PrimarySkillSignature->resize(111, 58);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrimarySkillSignature->sizePolicy().hasHeightForWidth());
        PrimarySkillSignature->setSizePolicy(sizePolicy);
        PrimarySkillSignature->setMinimumSize(QSize(111, 58));
        PrimarySkillSignature->setMaximumSize(QSize(111, 58));
        labelLeft = new QLabel(PrimarySkillSignature);
        labelLeft->setObjectName(QString::fromUtf8("labelLeft"));
        labelLeft->setGeometry(QRect(0, 13, 26, 32));
        sizePolicy.setHeightForWidth(labelLeft->sizePolicy().hasHeightForWidth());
        labelLeft->setSizePolicy(sizePolicy);
        labelLeft->setMinimumSize(QSize(26, 32));
        labelLeft->setMaximumSize(QSize(26, 32));
        labelRight = new QLabel(PrimarySkillSignature);
        labelRight->setObjectName(QString::fromUtf8("labelRight"));
        labelRight->setGeometry(QRect(85, 13, 26, 32));
        sizePolicy.setHeightForWidth(labelRight->sizePolicy().hasHeightForWidth());
        labelRight->setSizePolicy(sizePolicy);
        labelRight->setMinimumSize(QSize(26, 32));
        labelRight->setMaximumSize(QSize(26, 32));
        ButtonTop = new QPushButton(PrimarySkillSignature);
        ButtonTop->setObjectName(QString::fromUtf8("ButtonTop"));
        ButtonTop->setGeometry(QRect(21, 0, 71, 17));
        sizePolicy.setHeightForWidth(ButtonTop->sizePolicy().hasHeightForWidth());
        ButtonTop->setSizePolicy(sizePolicy);
        ButtonTop->setMinimumSize(QSize(71, 17));
        ButtonTop->setMaximumSize(QSize(71, 17));
        ButtonTop->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonTop->setStyleSheet(QString::fromUtf8(""));
        ButtonBottom = new QPushButton(PrimarySkillSignature);
        ButtonBottom->setObjectName(QString::fromUtf8("ButtonBottom"));
        ButtonBottom->setGeometry(QRect(21, 41, 71, 17));
        sizePolicy.setHeightForWidth(ButtonBottom->sizePolicy().hasHeightForWidth());
        ButtonBottom->setSizePolicy(sizePolicy);
        ButtonBottom->setMinimumSize(QSize(71, 17));
        ButtonBottom->setMaximumSize(QSize(71, 17));
        ButtonBottom->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonBottom->setStyleSheet(QString::fromUtf8(""));
        labelCenter = new QLabel(PrimarySkillSignature);
        labelCenter->setObjectName(QString::fromUtf8("labelCenter"));
        labelCenter->setGeometry(QRect(18, 17, 75, 24));
        sizePolicy.setHeightForWidth(labelCenter->sizePolicy().hasHeightForWidth());
        labelCenter->setSizePolicy(sizePolicy);
        labelCenter->setMinimumSize(QSize(75, 24));
        labelCenter->setMaximumSize(QSize(75, 24));
        ButtonText = new QPushButton(PrimarySkillSignature);
        ButtonText->setObjectName(QString::fromUtf8("ButtonText"));
        ButtonText->setGeometry(QRect(18, 17, 75, 24));
        sizePolicy.setHeightForWidth(ButtonText->sizePolicy().hasHeightForWidth());
        ButtonText->setSizePolicy(sizePolicy);
        ButtonText->setMaximumSize(QSize(75, 24));
        ButtonText->setCursor(QCursor(Qt::WhatsThisCursor));

        retranslateUi(PrimarySkillSignature);

        QMetaObject::connectSlotsByName(PrimarySkillSignature);
    } // setupUi

    void retranslateUi(QWidget *PrimarySkillSignature)
    {
        PrimarySkillSignature->setWindowTitle(QCoreApplication::translate("PrimarySkillSignature", "Form", nullptr));
        labelLeft->setText(QString());
        labelRight->setText(QString());
        ButtonTop->setText(QString());
        ButtonBottom->setText(QString());
        labelCenter->setText(QString());
        ButtonText->setText(QCoreApplication::translate("PrimarySkillSignature", "Non", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrimarySkillSignature: public Ui_PrimarySkillSignature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMARYSKILLSIGNATURE_H

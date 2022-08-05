/********************************************************************************
** Form generated from reading UI file 'paragraphwithborder.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAGRAPHWITHBORDER_H
#define UI_PARAGRAPHWITHBORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParagraphWithBorder
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *TopSpacer;
    QFrame *wrapper;
    QSpacerItem *BottomSpacer;

    void setupUi(QWidget *ParagraphWithBorder)
    {
        if (ParagraphWithBorder->objectName().isEmpty())
            ParagraphWithBorder->setObjectName(QString::fromUtf8("ParagraphWithBorder"));
        ParagraphWithBorder->resize(402, 261);
        verticalLayout_2 = new QVBoxLayout(ParagraphWithBorder);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        TopSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(TopSpacer);

        wrapper = new QFrame(ParagraphWithBorder);
        wrapper->setObjectName(QString::fromUtf8("wrapper"));
        wrapper->setFrameShape(QFrame::StyledPanel);
        wrapper->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(wrapper);

        BottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(BottomSpacer);


        retranslateUi(ParagraphWithBorder);

        QMetaObject::connectSlotsByName(ParagraphWithBorder);
    } // setupUi

    void retranslateUi(QWidget *ParagraphWithBorder)
    {
        ParagraphWithBorder->setWindowTitle(QCoreApplication::translate("ParagraphWithBorder", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParagraphWithBorder: public Ui_ParagraphWithBorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAGRAPHWITHBORDER_H

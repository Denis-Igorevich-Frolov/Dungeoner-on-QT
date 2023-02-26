/********************************************************************************
** Form generated from reading UI file 'item.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEM_H
#define UI_ITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Item
{
public:
    QLabel *Image;
    QLabel *Quantity;
    QPushButton *pushButton;
    QWidget *StyleButtonsWrapper;
    QVBoxLayout *verticalLayout_2;
    QPushButton *StyleButton_1;
    QPushButton *StyleButton_2;
    QPushButton *StyleButton_3;
    QPushButton *StyleButton_4;
    QPushButton *StyleButton_5;

    void setupUi(QWidget *Item)
    {
        if (Item->objectName().isEmpty())
            Item->setObjectName(QString::fromUtf8("Item"));
        Item->resize(68, 68);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Item->sizePolicy().hasHeightForWidth());
        Item->setSizePolicy(sizePolicy);
        Item->setCursor(QCursor(Qt::PointingHandCursor));
        Item->setMouseTracking(true);
        Item->setFocusPolicy(Qt::StrongFocus);
        Image = new QLabel(Item);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(0, 0, 68, 68));
        Quantity = new QLabel(Item);
        Quantity->setObjectName(QString::fromUtf8("Quantity"));
        Quantity->setGeometry(QRect(6, 46, 56, 20));
        Quantity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(Item);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 68, 68));
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: none;"));
        StyleButtonsWrapper = new QWidget(Item);
        StyleButtonsWrapper->setObjectName(QString::fromUtf8("StyleButtonsWrapper"));
        StyleButtonsWrapper->setGeometry(QRect(0, 0, 12, 68));
        sizePolicy.setHeightForWidth(StyleButtonsWrapper->sizePolicy().hasHeightForWidth());
        StyleButtonsWrapper->setSizePolicy(sizePolicy);
        StyleButtonsWrapper->setMouseTracking(true);
        StyleButtonsWrapper->setFocusPolicy(Qt::StrongFocus);
        verticalLayout_2 = new QVBoxLayout(StyleButtonsWrapper);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 0, 0, 0);
        StyleButton_1 = new QPushButton(StyleButtonsWrapper);
        StyleButton_1->setObjectName(QString::fromUtf8("StyleButton_1"));
        sizePolicy.setHeightForWidth(StyleButton_1->sizePolicy().hasHeightForWidth());
        StyleButton_1->setSizePolicy(sizePolicy);
        StyleButton_1->setMinimumSize(QSize(9, 12));
        StyleButton_1->setMaximumSize(QSize(9, 12));
        StyleButton_1->setLayoutDirection(Qt::LeftToRight);
        StyleButton_1->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(StyleButton_1);

        StyleButton_2 = new QPushButton(StyleButtonsWrapper);
        StyleButton_2->setObjectName(QString::fromUtf8("StyleButton_2"));
        sizePolicy.setHeightForWidth(StyleButton_2->sizePolicy().hasHeightForWidth());
        StyleButton_2->setSizePolicy(sizePolicy);
        StyleButton_2->setMinimumSize(QSize(9, 12));
        StyleButton_2->setMaximumSize(QSize(9, 12));
        StyleButton_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(StyleButton_2);

        StyleButton_3 = new QPushButton(StyleButtonsWrapper);
        StyleButton_3->setObjectName(QString::fromUtf8("StyleButton_3"));
        sizePolicy.setHeightForWidth(StyleButton_3->sizePolicy().hasHeightForWidth());
        StyleButton_3->setSizePolicy(sizePolicy);
        StyleButton_3->setMinimumSize(QSize(9, 12));
        StyleButton_3->setMaximumSize(QSize(9, 12));
        StyleButton_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(StyleButton_3);

        StyleButton_4 = new QPushButton(StyleButtonsWrapper);
        StyleButton_4->setObjectName(QString::fromUtf8("StyleButton_4"));
        sizePolicy.setHeightForWidth(StyleButton_4->sizePolicy().hasHeightForWidth());
        StyleButton_4->setSizePolicy(sizePolicy);
        StyleButton_4->setMinimumSize(QSize(9, 12));
        StyleButton_4->setMaximumSize(QSize(9, 12));
        StyleButton_4->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(StyleButton_4);

        StyleButton_5 = new QPushButton(StyleButtonsWrapper);
        StyleButton_5->setObjectName(QString::fromUtf8("StyleButton_5"));
        sizePolicy.setHeightForWidth(StyleButton_5->sizePolicy().hasHeightForWidth());
        StyleButton_5->setSizePolicy(sizePolicy);
        StyleButton_5->setMinimumSize(QSize(9, 12));
        StyleButton_5->setMaximumSize(QSize(9, 12));
        StyleButton_5->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(StyleButton_5);


        retranslateUi(Item);

        QMetaObject::connectSlotsByName(Item);
    } // setupUi

    void retranslateUi(QWidget *Item)
    {
        Item->setWindowTitle(QCoreApplication::translate("Item", "Form", nullptr));
        Image->setText(QString());
        Quantity->setText(QString());
        pushButton->setText(QString());
        StyleButton_1->setText(QCoreApplication::translate("Item", "I", nullptr));
        StyleButton_2->setText(QCoreApplication::translate("Item", "II", nullptr));
        StyleButton_3->setText(QCoreApplication::translate("Item", "III", nullptr));
        StyleButton_4->setText(QCoreApplication::translate("Item", "IV", nullptr));
        StyleButton_5->setText(QCoreApplication::translate("Item", "V", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Item: public Ui_Item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEM_H

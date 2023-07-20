/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *mianlineEdit;
    QGridLayout *gridLayout;
    QPushButton *minButton;
    QPushButton *fourButton;
    QPushButton *threeButton;
    QPushButton *delButton;
    QPushButton *addButton;
    QPushButton *eightButton;
    QPushButton *zeroButton;
    QPushButton *cleanButton;
    QPushButton *sevenButton;
    QPushButton *leftButton;
    QPushButton *twoButton;
    QPushButton *mulButton;
    QPushButton *fiveButton;
    QPushButton *divButton;
    QPushButton *oneButton;
    QPushButton *sixButton;
    QPushButton *nineButton;
    QPushButton *rightButton;
    QPushButton *equalButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(263, 408);
        QFont font;
        font.setPointSize(20);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mianlineEdit = new QLineEdit(Widget);
        mianlineEdit->setObjectName(QString::fromUtf8("mianlineEdit"));

        verticalLayout->addWidget(mianlineEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        minButton = new QPushButton(Widget);
        minButton->setObjectName(QString::fromUtf8("minButton"));
        minButton->setMinimumSize(QSize(50, 50));
        minButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(minButton, 0, 2, 1, 1);

        fourButton = new QPushButton(Widget);
        fourButton->setObjectName(QString::fromUtf8("fourButton"));
        fourButton->setMinimumSize(QSize(50, 50));
        fourButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(fourButton, 2, 0, 1, 1);

        threeButton = new QPushButton(Widget);
        threeButton->setObjectName(QString::fromUtf8("threeButton"));
        threeButton->setMinimumSize(QSize(50, 50));
        threeButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(threeButton, 3, 2, 1, 1);

        delButton = new QPushButton(Widget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setMinimumSize(QSize(50, 50));
        delButton->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8("pic/\345\210\240\351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        delButton->setIcon(icon);
        delButton->setIconSize(QSize(18, 18));

        gridLayout->addWidget(delButton, 0, 3, 1, 1);

        addButton = new QPushButton(Widget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setMinimumSize(QSize(50, 50));
        addButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(addButton, 0, 1, 1, 1);

        eightButton = new QPushButton(Widget);
        eightButton->setObjectName(QString::fromUtf8("eightButton"));
        eightButton->setMinimumSize(QSize(50, 50));
        eightButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(eightButton, 1, 1, 1, 1);

        zeroButton = new QPushButton(Widget);
        zeroButton->setObjectName(QString::fromUtf8("zeroButton"));
        zeroButton->setMinimumSize(QSize(50, 50));
        zeroButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(zeroButton, 4, 0, 1, 1);

        cleanButton = new QPushButton(Widget);
        cleanButton->setObjectName(QString::fromUtf8("cleanButton"));
        cleanButton->setMinimumSize(QSize(50, 50));
        cleanButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(cleanButton, 0, 0, 1, 1);

        sevenButton = new QPushButton(Widget);
        sevenButton->setObjectName(QString::fromUtf8("sevenButton"));
        sevenButton->setMinimumSize(QSize(50, 50));
        sevenButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(sevenButton, 1, 0, 1, 1);

        leftButton = new QPushButton(Widget);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));
        leftButton->setMinimumSize(QSize(50, 50));
        leftButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(leftButton, 4, 1, 1, 1);

        twoButton = new QPushButton(Widget);
        twoButton->setObjectName(QString::fromUtf8("twoButton"));
        twoButton->setMinimumSize(QSize(50, 50));
        twoButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(twoButton, 3, 1, 1, 1);

        mulButton = new QPushButton(Widget);
        mulButton->setObjectName(QString::fromUtf8("mulButton"));
        mulButton->setMinimumSize(QSize(50, 50));
        mulButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(mulButton, 1, 3, 1, 1);

        fiveButton = new QPushButton(Widget);
        fiveButton->setObjectName(QString::fromUtf8("fiveButton"));
        fiveButton->setMinimumSize(QSize(50, 50));
        fiveButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(fiveButton, 2, 1, 1, 1);

        divButton = new QPushButton(Widget);
        divButton->setObjectName(QString::fromUtf8("divButton"));
        divButton->setMinimumSize(QSize(50, 50));
        divButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(divButton, 2, 3, 1, 1);

        oneButton = new QPushButton(Widget);
        oneButton->setObjectName(QString::fromUtf8("oneButton"));
        oneButton->setMinimumSize(QSize(50, 50));
        oneButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(oneButton, 3, 0, 1, 1);

        sixButton = new QPushButton(Widget);
        sixButton->setObjectName(QString::fromUtf8("sixButton"));
        sixButton->setMinimumSize(QSize(50, 50));
        sixButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(sixButton, 2, 2, 1, 1);

        nineButton = new QPushButton(Widget);
        nineButton->setObjectName(QString::fromUtf8("nineButton"));
        nineButton->setMinimumSize(QSize(50, 50));
        nineButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(nineButton, 1, 2, 1, 1);

        rightButton = new QPushButton(Widget);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));
        rightButton->setMinimumSize(QSize(50, 50));
        rightButton->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(rightButton, 4, 2, 1, 1);

        equalButton = new QPushButton(Widget);
        equalButton->setObjectName(QString::fromUtf8("equalButton"));
        equalButton->setMinimumSize(QSize(50, 50));
        equalButton->setMaximumSize(QSize(50, 150));

        gridLayout->addWidget(equalButton, 3, 3, 2, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\256\241\347\256\227\346\234\272", nullptr));
        minButton->setText(QCoreApplication::translate("Widget", "-", nullptr));
        fourButton->setText(QCoreApplication::translate("Widget", "4", nullptr));
        threeButton->setText(QCoreApplication::translate("Widget", "3", nullptr));
        delButton->setText(QString());
        addButton->setText(QCoreApplication::translate("Widget", "+", nullptr));
        eightButton->setText(QCoreApplication::translate("Widget", "8", nullptr));
        zeroButton->setText(QCoreApplication::translate("Widget", "0", nullptr));
        cleanButton->setText(QCoreApplication::translate("Widget", "C", nullptr));
        sevenButton->setText(QCoreApplication::translate("Widget", "7", nullptr));
        leftButton->setText(QCoreApplication::translate("Widget", "(", nullptr));
        twoButton->setText(QCoreApplication::translate("Widget", "2", nullptr));
        mulButton->setText(QCoreApplication::translate("Widget", "*", nullptr));
        fiveButton->setText(QCoreApplication::translate("Widget", "5", nullptr));
        divButton->setText(QCoreApplication::translate("Widget", "/", nullptr));
        oneButton->setText(QCoreApplication::translate("Widget", "1", nullptr));
        sixButton->setText(QCoreApplication::translate("Widget", "6", nullptr));
        nineButton->setText(QCoreApplication::translate("Widget", "9", nullptr));
        rightButton->setText(QCoreApplication::translate("Widget", ")", nullptr));
        equalButton->setText(QCoreApplication::translate("Widget", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

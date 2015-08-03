/********************************************************************************
** Form generated from reading UI file 'genericbutton.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERICBUTTON_H
#define UI_GENERICBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_genericButton
{
public:
    QLabel *label;
    QWidget *backgroundWidget;

    void setupUi(QWidget *genericButton)
    {
        if (genericButton->objectName().isEmpty())
            genericButton->setObjectName(QStringLiteral("genericButton"));
        genericButton->resize(100, 30);
        genericButton->setStyleSheet(QStringLiteral(""));
        label = new QLabel(genericButton);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 100, 30));
        label->setStyleSheet(QStringLiteral(""));
        backgroundWidget = new QWidget(genericButton);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        backgroundWidget->setGeometry(QRect(0, 0, 100, 30));

        retranslateUi(genericButton);

        QMetaObject::connectSlotsByName(genericButton);
    } // setupUi

    void retranslateUi(QWidget *genericButton)
    {
        genericButton->setWindowTitle(QApplication::translate("genericButton", "Form", 0));
        label->setText(QApplication::translate("genericButton", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class genericButton: public Ui_genericButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERICBUTTON_H

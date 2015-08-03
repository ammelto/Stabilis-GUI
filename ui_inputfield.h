/********************************************************************************
** Form generated from reading UI file 'inputfield.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTFIELD_H
#define UI_INPUTFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inputField
{
public:
    QWidget *selectionBar;
    QLineEdit *lineEdit;

    void setupUi(QWidget *inputField)
    {
        if (inputField->objectName().isEmpty())
            inputField->setObjectName(QStringLiteral("inputField"));
        inputField->resize(60, 20);
        selectionBar = new QWidget(inputField);
        selectionBar->setObjectName(QStringLiteral("selectionBar"));
        selectionBar->setGeometry(QRect(0, 18, 60, 2));
        lineEdit = new QLineEdit(inputField);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 0, 60, 20));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 0px\n"
"}"));
        lineEdit->raise();
        selectionBar->raise();

        retranslateUi(inputField);

        QMetaObject::connectSlotsByName(inputField);
    } // setupUi

    void retranslateUi(QWidget *inputField)
    {
        inputField->setWindowTitle(QApplication::translate("inputField", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class inputField: public Ui_inputField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTFIELD_H

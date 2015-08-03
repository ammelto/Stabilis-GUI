/********************************************************************************
** Form generated from reading UI file 'terminalwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINALWINDOW_H
#define UI_TERMINALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TerminalWindow
{
public:

    void setupUi(QWidget *TerminalWindow)
    {
        if (TerminalWindow->objectName().isEmpty())
            TerminalWindow->setObjectName(QStringLiteral("TerminalWindow"));
        TerminalWindow->resize(704, 578);
        TerminalWindow->setStyleSheet(QStringLiteral(""));

        retranslateUi(TerminalWindow);

        QMetaObject::connectSlotsByName(TerminalWindow);
    } // setupUi

    void retranslateUi(QWidget *TerminalWindow)
    {
        TerminalWindow->setWindowTitle(QApplication::translate("TerminalWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class TerminalWindow: public Ui_TerminalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINALWINDOW_H

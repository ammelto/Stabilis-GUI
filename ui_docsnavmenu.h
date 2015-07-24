/********************************************************************************
** Form generated from reading UI file 'docsnavmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCSNAVMENU_H
#define UI_DOCSNAVMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocsNavMenu
{
public:

    void setupUi(QWidget *DocsNavMenu)
    {
        if (DocsNavMenu->objectName().isEmpty())
            DocsNavMenu->setObjectName(QStringLiteral("DocsNavMenu"));
        DocsNavMenu->resize(200, 578);

        retranslateUi(DocsNavMenu);

        QMetaObject::connectSlotsByName(DocsNavMenu);
    } // setupUi

    void retranslateUi(QWidget *DocsNavMenu)
    {
        DocsNavMenu->setWindowTitle(QApplication::translate("DocsNavMenu", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class DocsNavMenu: public Ui_DocsNavMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCSNAVMENU_H

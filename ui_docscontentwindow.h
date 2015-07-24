/********************************************************************************
** Form generated from reading UI file 'docscontentwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCSCONTENTWINDOW_H
#define UI_DOCSCONTENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocsContentWindow
{
public:

    void setupUi(QWidget *DocsContentWindow)
    {
        if (DocsContentWindow->objectName().isEmpty())
            DocsContentWindow->setObjectName(QStringLiteral("DocsContentWindow"));
        DocsContentWindow->resize(489, 578);

        retranslateUi(DocsContentWindow);

        QMetaObject::connectSlotsByName(DocsContentWindow);
    } // setupUi

    void retranslateUi(QWidget *DocsContentWindow)
    {
        DocsContentWindow->setWindowTitle(QApplication::translate("DocsContentWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class DocsContentWindow: public Ui_DocsContentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCSCONTENTWINDOW_H

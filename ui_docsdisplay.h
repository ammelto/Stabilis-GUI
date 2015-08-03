/********************************************************************************
** Form generated from reading UI file 'docsdisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCSDISPLAY_H
#define UI_DOCSDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_docsdisplay
{
public:
    QWidget *mainPage;
    QWidget *navWindow;

    void setupUi(QWidget *docsdisplay)
    {
        if (docsdisplay->objectName().isEmpty())
            docsdisplay->setObjectName(QStringLiteral("docsdisplay"));
        docsdisplay->resize(800, 634);
        mainPage = new QWidget(docsdisplay);
        mainPage->setObjectName(QStringLiteral("mainPage"));
        mainPage->setGeometry(QRect(263, 28, 489, 578));
        navWindow = new QWidget(docsdisplay);
        navWindow->setObjectName(QStringLiteral("navWindow"));
        navWindow->setGeometry(QRect(48, 28, 200, 578));

        retranslateUi(docsdisplay);

        QMetaObject::connectSlotsByName(docsdisplay);
    } // setupUi

    void retranslateUi(QWidget *docsdisplay)
    {
        docsdisplay->setWindowTitle(QApplication::translate("docsdisplay", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class docsdisplay: public Ui_docsdisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCSDISPLAY_H

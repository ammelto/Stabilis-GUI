/********************************************************************************
** Form generated from reading UI file 'consoledisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLEDISPLAY_H
#define UI_CONSOLEDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_consoledisplay
{
public:
    QWidget *console;

    void setupUi(QWidget *consoledisplay)
    {
        if (consoledisplay->objectName().isEmpty())
            consoledisplay->setObjectName(QStringLiteral("consoledisplay"));
        consoledisplay->resize(800, 634);
        console = new QWidget(consoledisplay);
        console->setObjectName(QStringLiteral("console"));
        console->setGeometry(QRect(48, 28, 704, 578));

        retranslateUi(consoledisplay);

        QMetaObject::connectSlotsByName(consoledisplay);
    } // setupUi

    void retranslateUi(QWidget *consoledisplay)
    {
        consoledisplay->setWindowTitle(QApplication::translate("consoledisplay", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class consoledisplay: public Ui_consoledisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLEDISPLAY_H

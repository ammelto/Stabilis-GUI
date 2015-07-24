/********************************************************************************
** Form generated from reading UI file 'windowdisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWDISPLAY_H
#define UI_WINDOWDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowdisplay
{
public:
    QLabel *label;

    void setupUi(QWidget *windowdisplay)
    {
        if (windowdisplay->objectName().isEmpty())
            windowdisplay->setObjectName(QStringLiteral("windowdisplay"));
        windowdisplay->resize(672, 552);
        label = new QLabel(windowdisplay);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 180, 421, 131));

        retranslateUi(windowdisplay);

        QMetaObject::connectSlotsByName(windowdisplay);
    } // setupUi

    void retranslateUi(QWidget *windowdisplay)
    {
        windowdisplay->setWindowTitle(QApplication::translate("windowdisplay", "Form", 0));
        label->setText(QApplication::translate("windowdisplay", "<html><head/><body><p><span style=\" font-size:72pt;\">WINDOW</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class windowdisplay: public Ui_windowdisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWDISPLAY_H

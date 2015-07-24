/********************************************************************************
** Form generated from reading UI file 'homedisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEDISPLAY_H
#define UI_HOMEDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homedisplay
{
public:
    QLabel *label;

    void setupUi(QWidget *homedisplay)
    {
        if (homedisplay->objectName().isEmpty())
            homedisplay->setObjectName(QStringLiteral("homedisplay"));
        homedisplay->resize(672, 552);
        label = new QLabel(homedisplay);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 0, 271, 131));

        retranslateUi(homedisplay);

        QMetaObject::connectSlotsByName(homedisplay);
    } // setupUi

    void retranslateUi(QWidget *homedisplay)
    {
        homedisplay->setWindowTitle(QApplication::translate("homedisplay", "Form", 0));
        label->setText(QApplication::translate("homedisplay", "<html><head/><body><p><span style=\" font-size:72pt;\">HOME</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class homedisplay: public Ui_homedisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEDISPLAY_H

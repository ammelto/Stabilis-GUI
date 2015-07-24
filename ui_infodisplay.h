/********************************************************************************
** Form generated from reading UI file 'infodisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODISPLAY_H
#define UI_INFODISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infodisplay
{
public:
    QLabel *label;

    void setupUi(QWidget *infodisplay)
    {
        if (infodisplay->objectName().isEmpty())
            infodisplay->setObjectName(QStringLiteral("infodisplay"));
        infodisplay->resize(672, 552);
        label = new QLabel(infodisplay);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 180, 271, 131));

        retranslateUi(infodisplay);

        QMetaObject::connectSlotsByName(infodisplay);
    } // setupUi

    void retranslateUi(QWidget *infodisplay)
    {
        infodisplay->setWindowTitle(QApplication::translate("infodisplay", "Form", 0));
        label->setText(QApplication::translate("infodisplay", "<html><head/><body><p><span style=\" font-size:72pt;\">INFO</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class infodisplay: public Ui_infodisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODISPLAY_H

/********************************************************************************
** Form generated from reading UI file 'slider.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDER_H
#define UI_SLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_slider
{
public:

    void setupUi(QWidget *slider)
    {
        if (slider->objectName().isEmpty())
            slider->setObjectName(QStringLiteral("slider"));
        slider->resize(60, 20);

        retranslateUi(slider);

        QMetaObject::connectSlotsByName(slider);
    } // setupUi

    void retranslateUi(QWidget *slider)
    {
        slider->setWindowTitle(QApplication::translate("slider", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class slider: public Ui_slider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDER_H

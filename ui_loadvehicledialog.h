/********************************************************************************
** Form generated from reading UI file 'loadvehicledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADVEHICLEDIALOG_H
#define UI_LOADVEHICLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadVehicleDialog
{
public:
    QListWidget *fileList;

    void setupUi(QWidget *LoadVehicleDialog)
    {
        if (LoadVehicleDialog->objectName().isEmpty())
            LoadVehicleDialog->setObjectName(QStringLiteral("LoadVehicleDialog"));
        LoadVehicleDialog->resize(308, 468);
        fileList = new QListWidget(LoadVehicleDialog);
        fileList->setObjectName(QStringLiteral("fileList"));
        fileList->setGeometry(QRect(0, 0, 308, 463));
        fileList->setStyleSheet(QStringLiteral(""));

        retranslateUi(LoadVehicleDialog);

        QMetaObject::connectSlotsByName(LoadVehicleDialog);
    } // setupUi

    void retranslateUi(QWidget *LoadVehicleDialog)
    {
        LoadVehicleDialog->setWindowTitle(QApplication::translate("LoadVehicleDialog", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadVehicleDialog: public Ui_LoadVehicleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADVEHICLEDIALOG_H

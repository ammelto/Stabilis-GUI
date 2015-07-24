/********************************************************************************
** Form generated from reading UI file 'newvehicledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWVEHICLEDIALOG_H
#define UI_NEWVEHICLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newVehicleDialog
{
public:
    QLabel *templateLabel;
    QLabel *templateDetail;
    QComboBox *VIDBox;

    void setupUi(QWidget *newVehicleDialog)
    {
        if (newVehicleDialog->objectName().isEmpty())
            newVehicleDialog->setObjectName(QStringLiteral("newVehicleDialog"));
        newVehicleDialog->resize(308, 468);
        templateLabel = new QLabel(newVehicleDialog);
        templateLabel->setObjectName(QStringLiteral("templateLabel"));
        templateLabel->setGeometry(QRect(0, 0, 251, 22));
        templateLabel->setStyleSheet(QStringLiteral(""));
        templateDetail = new QLabel(newVehicleDialog);
        templateDetail->setObjectName(QStringLiteral("templateDetail"));
        templateDetail->setGeometry(QRect(0, 20, 200, 15));
        templateDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        VIDBox = new QComboBox(newVehicleDialog);
        VIDBox->setObjectName(QStringLiteral("VIDBox"));
        VIDBox->setGeometry(QRect(200, 15, 101, 20));
        VIDBox->setStyleSheet(QStringLiteral(""));

        retranslateUi(newVehicleDialog);

        QMetaObject::connectSlotsByName(newVehicleDialog);
    } // setupUi

    void retranslateUi(QWidget *newVehicleDialog)
    {
        newVehicleDialog->setWindowTitle(QApplication::translate("newVehicleDialog", "Form", 0));
        templateLabel->setText(QApplication::translate("newVehicleDialog", "New Template", 0));
        templateDetail->setText(QApplication::translate("newVehicleDialog", "Vehicle Type", 0));
        VIDBox->clear();
        VIDBox->insertItems(0, QStringList()
         << QApplication::translate("newVehicleDialog", "Airplane", 0)
         << QApplication::translate("newVehicleDialog", "Car", 0)
         << QApplication::translate("newVehicleDialog", "Copter", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class newVehicleDialog: public Ui_newVehicleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWVEHICLEDIALOG_H

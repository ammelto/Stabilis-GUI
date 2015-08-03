/********************************************************************************
** Form generated from reading UI file 'configvehiclesettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGVEHICLESETTINGS_H
#define UI_CONFIGVEHICLESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configvehiclesettings
{
public:
    QLabel *windowLabel;
    QLabel *loadedVehicle;
    QWidget *advancedButton;
    QWidget *loadVehicleButton;
    QWidget *saveVehicleButton;
    QWidget *settingsArea;
    QLabel *overlay;

    void setupUi(QWidget *configvehiclesettings)
    {
        if (configvehiclesettings->objectName().isEmpty())
            configvehiclesettings->setObjectName(QStringLiteral("configvehiclesettings"));
        configvehiclesettings->resize(338, 528);
        windowLabel = new QLabel(configvehiclesettings);
        windowLabel->setObjectName(QStringLiteral("windowLabel"));
        windowLabel->setGeometry(QRect(5, 5, 100, 20));
        windowLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #616161\n"
"}"));
        loadedVehicle = new QLabel(configvehiclesettings);
        loadedVehicle->setObjectName(QStringLiteral("loadedVehicle"));
        loadedVehicle->setGeometry(QRect(90, 5, 243, 20));
        loadedVehicle->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #616161\n"
"}"));
        advancedButton = new QWidget(configvehiclesettings);
        advancedButton->setObjectName(QStringLiteral("advancedButton"));
        advancedButton->setGeometry(QRect(0, 498, 113, 30));
        advancedButton->setStyleSheet(QStringLiteral(""));
        loadVehicleButton = new QWidget(configvehiclesettings);
        loadVehicleButton->setObjectName(QStringLiteral("loadVehicleButton"));
        loadVehicleButton->setGeometry(QRect(113, 498, 113, 30));
        loadVehicleButton->setStyleSheet(QStringLiteral(""));
        saveVehicleButton = new QWidget(configvehiclesettings);
        saveVehicleButton->setObjectName(QStringLiteral("saveVehicleButton"));
        saveVehicleButton->setGeometry(QRect(226, 498, 113, 30));
        saveVehicleButton->setStyleSheet(QStringLiteral(""));
        settingsArea = new QWidget(configvehiclesettings);
        settingsArea->setObjectName(QStringLiteral("settingsArea"));
        settingsArea->setGeometry(QRect(15, 30, 308, 468));
        overlay = new QLabel(configvehiclesettings);
        overlay->setObjectName(QStringLiteral("overlay"));
        overlay->setGeometry(QRect(0, 0, 338, 30));
        windowLabel->raise();
        loadedVehicle->raise();
        saveVehicleButton->raise();
        loadVehicleButton->raise();
        advancedButton->raise();
        settingsArea->raise();
        overlay->raise();

        retranslateUi(configvehiclesettings);

        QMetaObject::connectSlotsByName(configvehiclesettings);
    } // setupUi

    void retranslateUi(QWidget *configvehiclesettings)
    {
        configvehiclesettings->setWindowTitle(QApplication::translate("configvehiclesettings", "Form", 0));
        windowLabel->setText(QApplication::translate("configvehiclesettings", "Vehicle", 0));
        loadedVehicle->setText(QApplication::translate("configvehiclesettings", "<html><head/><body><p align=\"right\">Skyhunter</p></body></html>", 0));
        overlay->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class configvehiclesettings: public Ui_configvehiclesettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGVEHICLESETTINGS_H

/********************************************************************************
** Form generated from reading UI file 'configgeneralsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGGENERALSETTINGS_H
#define UI_CONFIGGENERALSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configGeneralSettings
{
public:
    QSlider *simulationToggle;
    QLabel *windowLabel;
    QLabel *simulationLabel;
    QLabel *htlLabel;
    QSlider *htlToggle;
    QLabel *gcsCommsLabel;
    QSlider *gcsToggle;
    QLabel *dataLoggingLabel;
    QSlider *dataToggle;
    QLabel *simDetailLabel;
    QLabel *htlDetailLabel;
    QLabel *gcsDetailLabel;
    QLabel *dataDetailLabel;

    void setupUi(QWidget *configGeneralSettings)
    {
        if (configGeneralSettings->objectName().isEmpty())
            configGeneralSettings->setObjectName(QStringLiteral("configGeneralSettings"));
        configGeneralSettings->resize(355, 220);
        simulationToggle = new QSlider(configGeneralSettings);
        simulationToggle->setObjectName(QStringLiteral("simulationToggle"));
        simulationToggle->setGeometry(QRect(320, 45, 31, 22));
        simulationToggle->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"background: #9E9E9E;\n"
"height: 14px;\n"
"border-radius: 7px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background:white;\n"
"width: 12px;\n"
"height: 14px;\n"
"margin: 1px;\n"
"border-radius: 5px;\n"
"}\n"
""));
        simulationToggle->setMaximum(1);
        simulationToggle->setSingleStep(1);
        simulationToggle->setPageStep(100);
        simulationToggle->setOrientation(Qt::Horizontal);
        windowLabel = new QLabel(configGeneralSettings);
        windowLabel->setObjectName(QStringLiteral("windowLabel"));
        windowLabel->setGeometry(QRect(5, 5, 345, 20));
        windowLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #616161\n"
"}"));
        simulationLabel = new QLabel(configGeneralSettings);
        simulationLabel->setObjectName(QStringLiteral("simulationLabel"));
        simulationLabel->setGeometry(QRect(15, 30, 251, 22));
        simulationLabel->setStyleSheet(QStringLiteral(""));
        htlLabel = new QLabel(configGeneralSettings);
        htlLabel->setObjectName(QStringLiteral("htlLabel"));
        htlLabel->setGeometry(QRect(15, 78, 251, 22));
        htlLabel->setStyleSheet(QStringLiteral(""));
        htlToggle = new QSlider(configGeneralSettings);
        htlToggle->setObjectName(QStringLiteral("htlToggle"));
        htlToggle->setGeometry(QRect(320, 92, 31, 22));
        htlToggle->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"background: #9E9E9E;\n"
"height: 14px;\n"
"border-radius: 7px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background:white;\n"
"width: 12px;\n"
"height: 14px;\n"
"margin: 1px;\n"
"border-radius: 5px;\n"
"}\n"
""));
        htlToggle->setMaximum(1);
        htlToggle->setSingleStep(1);
        htlToggle->setPageStep(100);
        htlToggle->setOrientation(Qt::Horizontal);
        gcsCommsLabel = new QLabel(configGeneralSettings);
        gcsCommsLabel->setObjectName(QStringLiteral("gcsCommsLabel"));
        gcsCommsLabel->setGeometry(QRect(15, 124, 251, 22));
        gcsCommsLabel->setStyleSheet(QStringLiteral(""));
        gcsToggle = new QSlider(configGeneralSettings);
        gcsToggle->setObjectName(QStringLiteral("gcsToggle"));
        gcsToggle->setGeometry(QRect(320, 139, 31, 22));
        gcsToggle->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"background: #9E9E9E;\n"
"height: 14px;\n"
"border-radius: 7px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background:white;\n"
"width: 12px;\n"
"height: 14px;\n"
"margin: 1px;\n"
"border-radius: 5px;\n"
"}\n"
""));
        gcsToggle->setMaximum(1);
        gcsToggle->setSingleStep(1);
        gcsToggle->setPageStep(100);
        gcsToggle->setOrientation(Qt::Horizontal);
        dataLoggingLabel = new QLabel(configGeneralSettings);
        dataLoggingLabel->setObjectName(QStringLiteral("dataLoggingLabel"));
        dataLoggingLabel->setGeometry(QRect(15, 172, 251, 22));
        dataLoggingLabel->setStyleSheet(QStringLiteral(""));
        dataToggle = new QSlider(configGeneralSettings);
        dataToggle->setObjectName(QStringLiteral("dataToggle"));
        dataToggle->setGeometry(QRect(320, 186, 31, 22));
        dataToggle->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"background: #9E9E9E;\n"
"height: 14px;\n"
"border-radius: 7px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background:white;\n"
"width: 12px;\n"
"height: 14px;\n"
"margin: 1px;\n"
"border-radius: 5px;\n"
"}\n"
""));
        dataToggle->setMaximum(1);
        dataToggle->setSingleStep(1);
        dataToggle->setPageStep(100);
        dataToggle->setOrientation(Qt::Horizontal);
        simDetailLabel = new QLabel(configGeneralSettings);
        simDetailLabel->setObjectName(QStringLiteral("simDetailLabel"));
        simDetailLabel->setGeometry(QRect(15, 50, 301, 15));
        simDetailLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        htlDetailLabel = new QLabel(configGeneralSettings);
        htlDetailLabel->setObjectName(QStringLiteral("htlDetailLabel"));
        htlDetailLabel->setGeometry(QRect(15, 97, 301, 15));
        htlDetailLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        gcsDetailLabel = new QLabel(configGeneralSettings);
        gcsDetailLabel->setObjectName(QStringLiteral("gcsDetailLabel"));
        gcsDetailLabel->setGeometry(QRect(15, 144, 301, 15));
        gcsDetailLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        dataDetailLabel = new QLabel(configGeneralSettings);
        dataDetailLabel->setObjectName(QStringLiteral("dataDetailLabel"));
        dataDetailLabel->setGeometry(QRect(15, 191, 301, 15));
        dataDetailLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));

        retranslateUi(configGeneralSettings);

        QMetaObject::connectSlotsByName(configGeneralSettings);
    } // setupUi

    void retranslateUi(QWidget *configGeneralSettings)
    {
        configGeneralSettings->setWindowTitle(QApplication::translate("configGeneralSettings", "Form", 0));
        windowLabel->setText(QApplication::translate("configGeneralSettings", "General", 0));
        simulationLabel->setText(QApplication::translate("configGeneralSettings", "Simulation mode", 0));
        htlLabel->setText(QApplication::translate("configGeneralSettings", "HIL mode", 0));
        gcsCommsLabel->setText(QApplication::translate("configGeneralSettings", "UART communication", 0));
        dataLoggingLabel->setText(QApplication::translate("configGeneralSettings", "Data logging", 0));
        simDetailLabel->setText(QApplication::translate("configGeneralSettings", "Enables simulation mode for XPlane", 0));
        htlDetailLabel->setText(QApplication::translate("configGeneralSettings", "Propellers should be disabled for copter simulation", 0));
        gcsDetailLabel->setText(QApplication::translate("configGeneralSettings", "Disabling defaults comms mode to UDP", 0));
        dataDetailLabel->setText(QApplication::translate("configGeneralSettings", "Stores data logs in your Stabilis folder", 0));
    } // retranslateUi

};

namespace Ui {
    class configGeneralSettings: public Ui_configGeneralSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGGENERALSETTINGS_H

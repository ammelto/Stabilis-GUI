/********************************************************************************
** Form generated from reading UI file 'configcontrollersettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGCONTROLLERSETTINGS_H
#define UI_CONFIGCONTROLLERSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configcontrollersettings
{
public:
    QLabel *windowLabel;
    QLabel *sensorBusDetail;
    QLabel *sensorLabel;
    QLabel *sensorAddressDetail;
    QLabel *barometerAddressDetail;
    QLabel *barometerBusDetail;
    QLabel *IMUDetail;
    QLabel *radioDetail;
    QLabel *oneDetail;
    QLabel *twoDetail;
    QLabel *fiveDetail;
    QLabel *fourLabel;
    QLabel *threeLabel;
    QWidget *F00;
    QWidget *F01;
    QWidget *F04;
    QWidget *F02;
    QWidget *F03;
    QWidget *F14;
    QWidget *F12;
    QWidget *F13;
    QWidget *F10;
    QWidget *F11;
    QWidget *F24;
    QWidget *F22;
    QWidget *F23;
    QWidget *F20;
    QWidget *F21;
    QWidget *F34;
    QWidget *F32;
    QWidget *F33;
    QWidget *F30;
    QWidget *F31;
    QWidget *F44;
    QWidget *F42;
    QWidget *F43;
    QWidget *F40;
    QWidget *F41;
    QWidget *F54;
    QWidget *F52;
    QWidget *F53;
    QWidget *F50;
    QWidget *F51;
    QLabel *controllerLabel;
    QLabel *aileronDetail;
    QLabel *elevatorDetail;
    QLabel *rudderDetail;
    QLabel *throttleDetail;
    QLabel *flapDetail;
    QLabel *auxilleryDetail;
    QLabel *modeDetail;
    QLabel *triggerDetail;
    QLabel *inDetail;
    QLabel *outDetail;
    QWidget *c00;
    QWidget *c10;
    QWidget *c20;
    QWidget *c40;
    QWidget *c60;
    QWidget *c30;
    QWidget *c50;
    QWidget *c70;
    QWidget *c01;
    QWidget *c11;
    QWidget *c21;
    QWidget *c31;
    QWidget *c41;
    QWidget *c51;
    QWidget *c61;
    QWidget *c71;
    QLabel *limitLabel;
    QLabel *aileronLimitDetail;
    QLabel *rudderLimitDetail;
    QLabel *elevatorLimitDetail;
    QWidget *rudderLimitValue;
    QWidget *elevatorLimitValue;
    QWidget *aileronLimitValue;

    void setupUi(QWidget *configcontrollersettings)
    {
        if (configcontrollersettings->objectName().isEmpty())
            configcontrollersettings->setObjectName(QStringLiteral("configcontrollersettings"));
        configcontrollersettings->resize(704, 300);
        windowLabel = new QLabel(configcontrollersettings);
        windowLabel->setObjectName(QStringLiteral("windowLabel"));
        windowLabel->setGeometry(QRect(5, 5, 200, 20));
        windowLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #616161\n"
"}"));
        sensorBusDetail = new QLabel(configcontrollersettings);
        sensorBusDetail->setObjectName(QStringLiteral("sensorBusDetail"));
        sensorBusDetail->setGeometry(QRect(15, 50, 140, 15));
        sensorBusDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        sensorLabel = new QLabel(configcontrollersettings);
        sensorLabel->setObjectName(QStringLiteral("sensorLabel"));
        sensorLabel->setGeometry(QRect(15, 30, 140, 22));
        sensorLabel->setStyleSheet(QStringLiteral(""));
        sensorAddressDetail = new QLabel(configcontrollersettings);
        sensorAddressDetail->setObjectName(QStringLiteral("sensorAddressDetail"));
        sensorAddressDetail->setGeometry(QRect(15, 70, 120, 15));
        sensorAddressDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        barometerAddressDetail = new QLabel(configcontrollersettings);
        barometerAddressDetail->setObjectName(QStringLiteral("barometerAddressDetail"));
        barometerAddressDetail->setGeometry(QRect(15, 110, 120, 15));
        barometerAddressDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        barometerBusDetail = new QLabel(configcontrollersettings);
        barometerBusDetail->setObjectName(QStringLiteral("barometerBusDetail"));
        barometerBusDetail->setGeometry(QRect(15, 90, 120, 15));
        barometerBusDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        IMUDetail = new QLabel(configcontrollersettings);
        IMUDetail->setObjectName(QStringLiteral("IMUDetail"));
        IMUDetail->setGeometry(QRect(15, 130, 120, 15));
        IMUDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        radioDetail = new QLabel(configcontrollersettings);
        radioDetail->setObjectName(QStringLiteral("radioDetail"));
        radioDetail->setGeometry(QRect(15, 150, 120, 15));
        radioDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        oneDetail = new QLabel(configcontrollersettings);
        oneDetail->setObjectName(QStringLiteral("oneDetail"));
        oneDetail->setGeometry(QRect(175, 35, 15, 15));
        oneDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        twoDetail = new QLabel(configcontrollersettings);
        twoDetail->setObjectName(QStringLiteral("twoDetail"));
        twoDetail->setGeometry(QRect(225, 35, 15, 15));
        twoDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        fiveDetail = new QLabel(configcontrollersettings);
        fiveDetail->setObjectName(QStringLiteral("fiveDetail"));
        fiveDetail->setGeometry(QRect(375, 35, 15, 15));
        fiveDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        fourLabel = new QLabel(configcontrollersettings);
        fourLabel->setObjectName(QStringLiteral("fourLabel"));
        fourLabel->setGeometry(QRect(325, 35, 15, 15));
        fourLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        threeLabel = new QLabel(configcontrollersettings);
        threeLabel->setObjectName(QStringLiteral("threeLabel"));
        threeLabel->setGeometry(QRect(275, 35, 15, 15));
        threeLabel->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        F00 = new QWidget(configcontrollersettings);
        F00->setObjectName(QStringLiteral("F00"));
        F00->setGeometry(QRect(155, 50, 50, 15));
        F01 = new QWidget(configcontrollersettings);
        F01->setObjectName(QStringLiteral("F01"));
        F01->setGeometry(QRect(205, 50, 50, 15));
        F04 = new QWidget(configcontrollersettings);
        F04->setObjectName(QStringLiteral("F04"));
        F04->setGeometry(QRect(355, 50, 50, 15));
        F02 = new QWidget(configcontrollersettings);
        F02->setObjectName(QStringLiteral("F02"));
        F02->setGeometry(QRect(255, 50, 50, 15));
        F03 = new QWidget(configcontrollersettings);
        F03->setObjectName(QStringLiteral("F03"));
        F03->setGeometry(QRect(305, 50, 50, 15));
        F14 = new QWidget(configcontrollersettings);
        F14->setObjectName(QStringLiteral("F14"));
        F14->setGeometry(QRect(355, 70, 50, 15));
        F12 = new QWidget(configcontrollersettings);
        F12->setObjectName(QStringLiteral("F12"));
        F12->setGeometry(QRect(255, 70, 50, 15));
        F13 = new QWidget(configcontrollersettings);
        F13->setObjectName(QStringLiteral("F13"));
        F13->setGeometry(QRect(305, 70, 50, 15));
        F10 = new QWidget(configcontrollersettings);
        F10->setObjectName(QStringLiteral("F10"));
        F10->setGeometry(QRect(155, 70, 50, 15));
        F11 = new QWidget(configcontrollersettings);
        F11->setObjectName(QStringLiteral("F11"));
        F11->setGeometry(QRect(205, 70, 50, 15));
        F24 = new QWidget(configcontrollersettings);
        F24->setObjectName(QStringLiteral("F24"));
        F24->setGeometry(QRect(355, 90, 50, 15));
        F22 = new QWidget(configcontrollersettings);
        F22->setObjectName(QStringLiteral("F22"));
        F22->setGeometry(QRect(255, 90, 50, 15));
        F23 = new QWidget(configcontrollersettings);
        F23->setObjectName(QStringLiteral("F23"));
        F23->setGeometry(QRect(305, 90, 50, 15));
        F20 = new QWidget(configcontrollersettings);
        F20->setObjectName(QStringLiteral("F20"));
        F20->setGeometry(QRect(155, 90, 50, 15));
        F21 = new QWidget(configcontrollersettings);
        F21->setObjectName(QStringLiteral("F21"));
        F21->setGeometry(QRect(205, 90, 50, 15));
        F34 = new QWidget(configcontrollersettings);
        F34->setObjectName(QStringLiteral("F34"));
        F34->setGeometry(QRect(355, 110, 50, 15));
        F32 = new QWidget(configcontrollersettings);
        F32->setObjectName(QStringLiteral("F32"));
        F32->setGeometry(QRect(255, 110, 50, 15));
        F33 = new QWidget(configcontrollersettings);
        F33->setObjectName(QStringLiteral("F33"));
        F33->setGeometry(QRect(305, 110, 50, 15));
        F30 = new QWidget(configcontrollersettings);
        F30->setObjectName(QStringLiteral("F30"));
        F30->setGeometry(QRect(155, 110, 50, 15));
        F31 = new QWidget(configcontrollersettings);
        F31->setObjectName(QStringLiteral("F31"));
        F31->setGeometry(QRect(205, 110, 50, 15));
        F44 = new QWidget(configcontrollersettings);
        F44->setObjectName(QStringLiteral("F44"));
        F44->setGeometry(QRect(355, 130, 50, 15));
        F42 = new QWidget(configcontrollersettings);
        F42->setObjectName(QStringLiteral("F42"));
        F42->setGeometry(QRect(255, 130, 50, 15));
        F43 = new QWidget(configcontrollersettings);
        F43->setObjectName(QStringLiteral("F43"));
        F43->setGeometry(QRect(305, 130, 50, 15));
        F40 = new QWidget(configcontrollersettings);
        F40->setObjectName(QStringLiteral("F40"));
        F40->setGeometry(QRect(155, 130, 50, 15));
        F41 = new QWidget(configcontrollersettings);
        F41->setObjectName(QStringLiteral("F41"));
        F41->setGeometry(QRect(205, 130, 50, 15));
        F54 = new QWidget(configcontrollersettings);
        F54->setObjectName(QStringLiteral("F54"));
        F54->setGeometry(QRect(355, 150, 50, 15));
        F52 = new QWidget(configcontrollersettings);
        F52->setObjectName(QStringLiteral("F52"));
        F52->setGeometry(QRect(255, 150, 50, 15));
        F53 = new QWidget(configcontrollersettings);
        F53->setObjectName(QStringLiteral("F53"));
        F53->setGeometry(QRect(305, 150, 50, 15));
        F50 = new QWidget(configcontrollersettings);
        F50->setObjectName(QStringLiteral("F50"));
        F50->setGeometry(QRect(155, 150, 50, 15));
        F51 = new QWidget(configcontrollersettings);
        F51->setObjectName(QStringLiteral("F51"));
        F51->setGeometry(QRect(205, 150, 50, 15));
        controllerLabel = new QLabel(configcontrollersettings);
        controllerLabel->setObjectName(QStringLiteral("controllerLabel"));
        controllerLabel->setGeometry(QRect(450, 30, 100, 22));
        controllerLabel->setStyleSheet(QStringLiteral(""));
        aileronDetail = new QLabel(configcontrollersettings);
        aileronDetail->setObjectName(QStringLiteral("aileronDetail"));
        aileronDetail->setGeometry(QRect(450, 50, 100, 15));
        aileronDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        elevatorDetail = new QLabel(configcontrollersettings);
        elevatorDetail->setObjectName(QStringLiteral("elevatorDetail"));
        elevatorDetail->setGeometry(QRect(450, 70, 100, 15));
        elevatorDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        rudderDetail = new QLabel(configcontrollersettings);
        rudderDetail->setObjectName(QStringLiteral("rudderDetail"));
        rudderDetail->setGeometry(QRect(450, 90, 100, 15));
        rudderDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        throttleDetail = new QLabel(configcontrollersettings);
        throttleDetail->setObjectName(QStringLiteral("throttleDetail"));
        throttleDetail->setGeometry(QRect(450, 110, 100, 15));
        throttleDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        flapDetail = new QLabel(configcontrollersettings);
        flapDetail->setObjectName(QStringLiteral("flapDetail"));
        flapDetail->setGeometry(QRect(450, 130, 100, 15));
        flapDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        auxilleryDetail = new QLabel(configcontrollersettings);
        auxilleryDetail->setObjectName(QStringLiteral("auxilleryDetail"));
        auxilleryDetail->setGeometry(QRect(450, 150, 100, 15));
        auxilleryDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        modeDetail = new QLabel(configcontrollersettings);
        modeDetail->setObjectName(QStringLiteral("modeDetail"));
        modeDetail->setGeometry(QRect(450, 170, 100, 15));
        modeDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        triggerDetail = new QLabel(configcontrollersettings);
        triggerDetail->setObjectName(QStringLiteral("triggerDetail"));
        triggerDetail->setGeometry(QRect(450, 190, 100, 15));
        triggerDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        inDetail = new QLabel(configcontrollersettings);
        inDetail->setObjectName(QStringLiteral("inDetail"));
        inDetail->setGeometry(QRect(575, 35, 15, 15));
        inDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        outDetail = new QLabel(configcontrollersettings);
        outDetail->setObjectName(QStringLiteral("outDetail"));
        outDetail->setGeometry(QRect(625, 35, 20, 15));
        outDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        c00 = new QWidget(configcontrollersettings);
        c00->setObjectName(QStringLiteral("c00"));
        c00->setGeometry(QRect(555, 50, 50, 15));
        c10 = new QWidget(configcontrollersettings);
        c10->setObjectName(QStringLiteral("c10"));
        c10->setGeometry(QRect(555, 70, 50, 15));
        c20 = new QWidget(configcontrollersettings);
        c20->setObjectName(QStringLiteral("c20"));
        c20->setGeometry(QRect(555, 90, 50, 15));
        c40 = new QWidget(configcontrollersettings);
        c40->setObjectName(QStringLiteral("c40"));
        c40->setGeometry(QRect(555, 130, 50, 15));
        c60 = new QWidget(configcontrollersettings);
        c60->setObjectName(QStringLiteral("c60"));
        c60->setGeometry(QRect(555, 170, 50, 15));
        c30 = new QWidget(configcontrollersettings);
        c30->setObjectName(QStringLiteral("c30"));
        c30->setGeometry(QRect(555, 110, 50, 15));
        c50 = new QWidget(configcontrollersettings);
        c50->setObjectName(QStringLiteral("c50"));
        c50->setGeometry(QRect(555, 150, 50, 15));
        c70 = new QWidget(configcontrollersettings);
        c70->setObjectName(QStringLiteral("c70"));
        c70->setGeometry(QRect(555, 190, 50, 15));
        c01 = new QWidget(configcontrollersettings);
        c01->setObjectName(QStringLiteral("c01"));
        c01->setGeometry(QRect(610, 50, 50, 15));
        c11 = new QWidget(configcontrollersettings);
        c11->setObjectName(QStringLiteral("c11"));
        c11->setGeometry(QRect(610, 70, 50, 15));
        c21 = new QWidget(configcontrollersettings);
        c21->setObjectName(QStringLiteral("c21"));
        c21->setGeometry(QRect(610, 90, 50, 15));
        c31 = new QWidget(configcontrollersettings);
        c31->setObjectName(QStringLiteral("c31"));
        c31->setGeometry(QRect(610, 110, 50, 15));
        c41 = new QWidget(configcontrollersettings);
        c41->setObjectName(QStringLiteral("c41"));
        c41->setGeometry(QRect(610, 130, 50, 15));
        c51 = new QWidget(configcontrollersettings);
        c51->setObjectName(QStringLiteral("c51"));
        c51->setGeometry(QRect(610, 150, 50, 15));
        c61 = new QWidget(configcontrollersettings);
        c61->setObjectName(QStringLiteral("c61"));
        c61->setGeometry(QRect(610, 170, 50, 15));
        c71 = new QWidget(configcontrollersettings);
        c71->setObjectName(QStringLiteral("c71"));
        c71->setGeometry(QRect(610, 190, 50, 15));
        limitLabel = new QLabel(configcontrollersettings);
        limitLabel->setObjectName(QStringLiteral("limitLabel"));
        limitLabel->setGeometry(QRect(450, 210, 140, 22));
        limitLabel->setStyleSheet(QStringLiteral(""));
        aileronLimitDetail = new QLabel(configcontrollersettings);
        aileronLimitDetail->setObjectName(QStringLiteral("aileronLimitDetail"));
        aileronLimitDetail->setGeometry(QRect(450, 230, 100, 15));
        aileronLimitDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        rudderLimitDetail = new QLabel(configcontrollersettings);
        rudderLimitDetail->setObjectName(QStringLiteral("rudderLimitDetail"));
        rudderLimitDetail->setGeometry(QRect(450, 270, 100, 15));
        rudderLimitDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        elevatorLimitDetail = new QLabel(configcontrollersettings);
        elevatorLimitDetail->setObjectName(QStringLiteral("elevatorLimitDetail"));
        elevatorLimitDetail->setGeometry(QRect(450, 250, 100, 15));
        elevatorLimitDetail->setStyleSheet(QLatin1String("QLabel{\n"
"	color: #424242\n"
"}"));
        rudderLimitValue = new QWidget(configcontrollersettings);
        rudderLimitValue->setObjectName(QStringLiteral("rudderLimitValue"));
        rudderLimitValue->setGeometry(QRect(555, 270, 100, 15));
        elevatorLimitValue = new QWidget(configcontrollersettings);
        elevatorLimitValue->setObjectName(QStringLiteral("elevatorLimitValue"));
        elevatorLimitValue->setGeometry(QRect(555, 250, 100, 15));
        aileronLimitValue = new QWidget(configcontrollersettings);
        aileronLimitValue->setObjectName(QStringLiteral("aileronLimitValue"));
        aileronLimitValue->setGeometry(QRect(555, 230, 100, 15));

        retranslateUi(configcontrollersettings);

        QMetaObject::connectSlotsByName(configcontrollersettings);
    } // setupUi

    void retranslateUi(QWidget *configcontrollersettings)
    {
        configcontrollersettings->setWindowTitle(QApplication::translate("configcontrollersettings", "Form", 0));
        windowLabel->setText(QApplication::translate("configcontrollersettings", "Peripherals", 0));
        sensorBusDetail->setText(QApplication::translate("configcontrollersettings", "Sensor Buses", 0));
        sensorLabel->setText(QApplication::translate("configcontrollersettings", "Sensor details", 0));
        sensorAddressDetail->setText(QApplication::translate("configcontrollersettings", "Sensor Address", 0));
        barometerAddressDetail->setText(QApplication::translate("configcontrollersettings", "Barometer Addresses", 0));
        barometerBusDetail->setText(QApplication::translate("configcontrollersettings", "Barometer Buses", 0));
        IMUDetail->setText(QApplication::translate("configcontrollersettings", "IMU", 0));
        radioDetail->setText(QApplication::translate("configcontrollersettings", "Radio", 0));
        oneDetail->setText(QApplication::translate("configcontrollersettings", "<html><head/><body><p align=\"center\">1</p></body></html>", 0));
        twoDetail->setText(QApplication::translate("configcontrollersettings", "<html><head/><body><p align=\"center\">2</p></body></html>", 0));
        fiveDetail->setText(QApplication::translate("configcontrollersettings", "<html><head/><body><p align=\"center\">5</p></body></html>", 0));
        fourLabel->setText(QApplication::translate("configcontrollersettings", "<html><head/><body><p align=\"center\">4</p></body></html>", 0));
        threeLabel->setText(QApplication::translate("configcontrollersettings", "<html><head/><body><p align=\"center\">3</p></body></html>", 0));
        controllerLabel->setText(QApplication::translate("configcontrollersettings", "Controller", 0));
        aileronDetail->setText(QApplication::translate("configcontrollersettings", "Aileron", 0));
        elevatorDetail->setText(QApplication::translate("configcontrollersettings", "Elevator", 0));
        rudderDetail->setText(QApplication::translate("configcontrollersettings", "Rudder", 0));
        throttleDetail->setText(QApplication::translate("configcontrollersettings", "Throttle", 0));
        flapDetail->setText(QApplication::translate("configcontrollersettings", "Flap", 0));
        auxilleryDetail->setText(QApplication::translate("configcontrollersettings", "Auxillery", 0));
        modeDetail->setText(QApplication::translate("configcontrollersettings", "Mode", 0));
        triggerDetail->setText(QApplication::translate("configcontrollersettings", "Trigger", 0));
        inDetail->setText(QApplication::translate("configcontrollersettings", "<html><head/><body><p align=\"center\">In</p></body></html>", 0));
        outDetail->setText(QApplication::translate("configcontrollersettings", "<html><head/><body><p align=\"center\">Out</p></body></html>", 0));
        limitLabel->setText(QApplication::translate("configcontrollersettings", "Servo limits", 0));
        aileronLimitDetail->setText(QApplication::translate("configcontrollersettings", "Aileron limit", 0));
        rudderLimitDetail->setText(QApplication::translate("configcontrollersettings", "Rudder limit", 0));
        elevatorLimitDetail->setText(QApplication::translate("configcontrollersettings", "Elevator limit", 0));
    } // retranslateUi

};

namespace Ui {
    class configcontrollersettings: public Ui_configcontrollersettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGCONTROLLERSETTINGS_H

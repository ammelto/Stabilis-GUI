#include "../headers/configcontrollersettings.h"
#include "../headers/configcreator.h"
#include "ui_configcontrollersettings.h"
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QtCore>
#include <QDebug>

configcontrollersettings::configcontrollersettings(QWidget *parent, configcreator *config) :
    QWidget(parent),
    ui(new Ui::configcontrollersettings)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(6);
    shadow->setColor(QColor(0,0,0,200));
    shadow->setOffset(0);
    this->setGraphicsEffect(shadow);
    //
    QPalette pal = this->palette();
    pal.setColor(this->backgroundRole(), QColor(255,255,255));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    QFontDatabase::addApplicationFont("qrc:/fonts/Resources/fonts/Roboto-Bold.ttf");
    ui->windowLabel->setFont(QFont("Roboto",11));
    ui->sensorLabel->setFont(QFont("Roboto",11));
    ui->controllerLabel->setFont(QFont("Roboto",11));
    ui->limitLabel->setFont(QFont("Roboto",11));
    //
    ui->barometerAddressDetail->setFont(QFont("Roboto",9));
    ui->barometerBusDetail->setFont(QFont("Roboto",9));
    ui->fiveDetail->setFont(QFont("Roboto",9));
    ui->fourLabel->setFont(QFont("Roboto",9));
    ui->threeLabel->setFont(QFont("Roboto",9));
    ui->twoDetail->setFont(QFont("Roboto",9));
    ui->oneDetail->setFont(QFont("Roboto",9));
    ui->IMUDetail->setFont(QFont("Roboto",9));
    ui->radioDetail->setFont(QFont("Roboto",9));
    ui->sensorAddressDetail->setFont(QFont("Roboto",9));
    ui->sensorBusDetail->setFont(QFont("Roboto",9));
    ui->aileronDetail->setFont(QFont("Roboto",9));
    ui->auxilleryDetail->setFont(QFont("Roboto",9));
    ui->elevatorDetail->setFont(QFont("Roboto",9));
    ui->rudderDetail->setFont(QFont("Roboto",9));
    ui->throttleDetail->setFont(QFont("Roboto",9));
    ui->flapDetail->setFont(QFont("Roboto",9));
    ui->modeDetail->setFont(QFont("Roboto",9));
    ui->triggerDetail->setFont(QFont("Roboto",9));
    ui->inDetail->setFont(QFont("Roboto",9));
    ui->outDetail->setFont(QFont("Roboto",9));
    ui->aileronLimitDetail->setFont(QFont("Roboto",9));
    ui->elevatorLimitDetail->setFont(QFont("Roboto",9));
    ui->rudderLimitDetail->setFont(QFont("Roboto",9));

    //Array assignments
    //There's at least a million better ways to do this.
    //This is just a quick solution for now, didn't want to fiddle with the grid layout
    sensors[0][0] = new inputField(ui->F00,ui->F00->geometry(),"","");
    sensors[0][1] = new inputField(ui->F01,ui->F00->geometry(),"","");
    sensors[0][2] = new inputField(ui->F02,ui->F00->geometry(),"","");
    sensors[0][3] = new inputField(ui->F03,ui->F00->geometry(),"","");
    sensors[0][4] = new inputField(ui->F04,ui->F00->geometry(),"","");
    sensors[1][0] = new inputField(ui->F10,ui->F00->geometry(),"","");
    sensors[1][1] = new inputField(ui->F11,ui->F00->geometry(),"","");
    sensors[1][2] = new inputField(ui->F12,ui->F00->geometry(),"","");
    sensors[1][3] = new inputField(ui->F13,ui->F00->geometry(),"","");
    sensors[1][4] = new inputField(ui->F14,ui->F00->geometry(),"","");
    sensors[2][0] = new inputField(ui->F20,ui->F00->geometry(),"","");
    sensors[2][1] = new inputField(ui->F21,ui->F00->geometry(),"","");
    sensors[2][2] = new inputField(ui->F22,ui->F00->geometry(),"","");
    sensors[2][3] = new inputField(ui->F23,ui->F00->geometry(),"","");
    sensors[2][4] = new inputField(ui->F24,ui->F00->geometry(),"","");
    sensors[3][0] = new inputField(ui->F30,ui->F00->geometry(),"","");
    sensors[3][1] = new inputField(ui->F31,ui->F00->geometry(),"","");
    sensors[3][2] = new inputField(ui->F32,ui->F00->geometry(),"","");
    sensors[3][3] = new inputField(ui->F33,ui->F00->geometry(),"","");
    sensors[3][4] = new inputField(ui->F34,ui->F00->geometry(),"","");
    sensors[4][0] = new inputField(ui->F40,ui->F00->geometry(),"","");
    sensors[4][1] = new inputField(ui->F41,ui->F00->geometry(),"","");
    sensors[4][2] = new inputField(ui->F42,ui->F00->geometry(),"","");
    sensors[4][3] = new inputField(ui->F43,ui->F00->geometry(),"","");
    sensors[4][4] = new inputField(ui->F44,ui->F00->geometry(),"","");
    sensors[5][0] = new inputField(ui->F50,ui->F00->geometry(),"","");
    sensors[5][1] = new inputField(ui->F51,ui->F00->geometry(),"","");
    sensors[5][2] = new inputField(ui->F52,ui->F00->geometry(),"","");
    sensors[5][3] = new inputField(ui->F53,ui->F00->geometry(),"","");
    sensors[5][4] = new inputField(ui->F54,ui->F00->geometry(),"","");
    //
    controller[0][0] = new inputField(ui->c00,ui->c00->geometry(),"","");
    controller[0][1] = new inputField(ui->c01,ui->c00->geometry(),"","");
    controller[1][0] = new inputField(ui->c10,ui->c00->geometry(),"","");
    controller[1][1] = new inputField(ui->c11,ui->c00->geometry(),"","");
    controller[2][0] = new inputField(ui->c20,ui->c00->geometry(),"","");
    controller[2][1] = new inputField(ui->c21,ui->c00->geometry(),"","");
    controller[3][0] = new inputField(ui->c30,ui->c00->geometry(),"","");
    controller[3][1] = new inputField(ui->c31,ui->c00->geometry(),"","");
    controller[4][0] = new inputField(ui->c40,ui->c00->geometry(),"","");
    controller[4][1] = new inputField(ui->c41,ui->c00->geometry(),"","");
    controller[5][0] = new inputField(ui->c50,ui->c00->geometry(),"","");
    controller[5][1] = new inputField(ui->c51,ui->c00->geometry(),"","");
    controller[6][0] = new inputField(ui->c60,ui->c00->geometry(),"","");
    controller[6][1] = new inputField(ui->c61,ui->c00->geometry(),"","");
    controller[7][0] = new inputField(ui->c70,ui->c00->geometry(),"","");
    controller[7][1] = new inputField(ui->c71,ui->c00->geometry(),"","");
    //
    limits[0] = new inputField(ui->aileronLimitValue,ui->aileronLimitValue->geometry(),"","");
    limits[1] = new inputField(ui->elevatorLimitValue,ui->aileronLimitValue->geometry(),"","");
    limits[2] = new inputField(ui->rudderLimitValue,ui->aileronLimitValue->geometry(),"","");

    conf = config;
    connect(conf,SIGNAL(update()),this,SLOT(update()));

}

void configcontrollersettings::save(){
    conf->setSensorBus1(sensors[0][0]->getValue());
    conf->setSensorBus2(sensors[0][1]->getValue());
    conf->setSensorAddress1(sensors[1][0]->getValue());
    conf->setSensorAddress2(sensors[1][1]->getValue());
    conf->setBaroBus1(sensors[2][0]->getValue());
    conf->setBaroBus2(sensors[2][1]->getValue());
    conf->setBaroAddress1(sensors[3][0]->getValue());
    conf->setBaroAddress2(sensors[3][1]->getValue());
    conf->setVN(sensors[4][0]->getValue());
    conf->setRadio(sensors[5][0]->getValue());

    conf->setAileronIn(controller[0][0]->getValue());
    conf->setAileronOut(controller[0][1]->getValue());
    conf->setElevatorIn(controller[1][0]->getValue());
    conf->setElevatorOut(controller[1][1]->getValue());
    conf->setRudderIn(controller[2][0]->getValue());
    conf->setRudderOut(controller[2][1]->getValue());
    conf->setThrottleIn(controller[3][0]->getValue());
    conf->setThrottleOut(controller[3][1]->getValue());
    conf->setFlapIn(controller[4][0]->getValue());
    conf->setFlapOut(controller[4][1]->getValue());
    conf->setAuxIn(controller[5][0]->getValue());
    conf->setAuxOut(controller[5][1]->getValue());
    conf->setModeIn(controller[6][0]->getValue());
    conf->setModeOut(controller[6][1]->getValue());
    conf->setTriggerIn(controller[7][0]->getValue());
    conf->setTriggerOut(controller[7][1]->getValue());

    conf->setServoLimitAll(limits[0]->getValue());
    conf->setServoLimitElev(limits[1]->getValue());
    conf->setServoLimitRudder(limits[2]->getValue());
}

void configcontrollersettings::update(){
    sensors[0][0]->setValue(conf->getValue("Sensor Bus 1"));
    sensors[0][1]->setValue(conf->getValue("Sensor Bus 2"));
    sensors[1][0]->setValue(conf->getValue("Sensor Bus Address 1"));
    sensors[1][1]->setValue(conf->getValue("Sensor Bus Address 2"));
    sensors[2][0]->setValue(conf->getValue("Baro Bus 1"));
    sensors[2][1]->setValue(conf->getValue("Baro Bus 2"));
    sensors[3][0]->setValue(conf->getValue("Baro Bus Address 1"));
    sensors[3][1]->setValue(conf->getValue("Baro Bus Address 2"));
    sensors[4][0]->setValue(conf->getValue("VN200"));
    sensors[5][0]->setValue(conf->getValue("Radio"));

    controller[0][0]->setValue(conf->getValue("Aileron in"));
    controller[0][1]->setValue(conf->getValue("Aileron out"));
    controller[1][0]->setValue(conf->getValue("Elevator in"));
    controller[1][1]->setValue(conf->getValue("Elevator out"));
    controller[2][0]->setValue(conf->getValue("Rudder in"));
    controller[2][1]->setValue(conf->getValue("Rudder out"));
    controller[3][0]->setValue(conf->getValue("Throttle in"));
    controller[3][1]->setValue(conf->getValue("Throttle out"));
    controller[4][0]->setValue(conf->getValue("Flap in"));
    controller[4][1]->setValue(conf->getValue("Flap out"));
    controller[5][0]->setValue(conf->getValue("Aux in"));
    controller[5][1]->setValue(conf->getValue("Aux out"));
    controller[6][0]->setValue(conf->getValue("Mode in"));
    controller[6][1]->setValue(conf->getValue("Mode out"));
    controller[7][0]->setValue(conf->getValue("Trigger in"));
    controller[7][1]->setValue(conf->getValue("Trigger out"));

    limits[0]->setValue(conf->getValue("Servo Limit ALL"));
    limits[1]->setValue(conf->getValue("Servo Limit ELEV"));
    limits[2]->setValue(conf->getValue("Servo Limit RUDDER"));

}

configcontrollersettings::~configcontrollersettings()
{
    delete ui;
}

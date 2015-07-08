#include "../headers/airplanetemplate.h"
#include "../headers/configcreator.h"
#include "ui_airplanetemplate.h"
#include <QFontDatabase>
#include <QDebug>

airplaneTemplate::airplaneTemplate(QWidget *parent, configcreator *config) :
    QWidget(parent),
    ui(new Ui::airplaneTemplate)
{
    conf = config;
    ui->setupUi(this);
    QFontDatabase::addApplicationFont("qrc:/fonts/Resources/fonts/Roboto-Bold.ttf");
    ui->bankPitchLimit->setFont(QFont("Roboto",11));
    ui->innerLoopLabel->setFont(QFont("Roboto",11));
    ui->outerLoopLabel->setFont(QFont("Roboto",11));
    ui->referencesLabel->setFont(QFont("Roboto",11));
    ui->stallLabel->setFont(QFont("Roboto",11));
    //
    ui->bankPitchPhiDetail->setFont(QFont("Roboto",9));
    ui->bankPitchThetaDetail->setFont(QFont("Roboto",9));
    ui->bankPitchThtrottleDetail->setFont(QFont("Roboto",9));
    ui->hLongitudeDetail->setFont(QFont("Roboto",9));
    ui->kThrottleDetail->setFont(QFont("Roboto",9));
    ui->referenceOneDetail->setFont(QFont("Roboto",9));
    ui->referenceTwoDetail->setFont(QFont("Roboto",9));
    ui->referenceThreeDetail->setFont(QFont("Roboto",9));
    ui->stallDetail->setFont(QFont("Roboto",9));
    ui->xPIDDetail->setFont(QFont("Roboto",9));
    ui->xyLatitudeDetail->setFont(QFont("Roboto",9));
    ui->yPIDDetail->setFont(QFont("Roboto",9));
    ui->zPIDDetail->setFont(QFont("Roboto",9));

    pathField = new inputField(ui->pathValue,ui->pathValue->geometry(),"Path Value", conf->getValue("Path"));
    infField = new inputField(ui->infValue,ui->infValue->geometry(),"Inference Value", conf->getValue("Inf"));
    orbitField = new inputField(ui->orbitValue,ui->orbitValue->geometry(),"Orbit Value", conf->getValue("Orbit"));
    throttleP = new inputField(ui->throttleP,ui->throttleP->geometry(),"P", conf->getValue("Throttle P"));
    throttleI = new inputField(ui->throttleI,ui->throttleI->geometry(),"I", conf->getValue("Throttle I"));
    throttleD = new inputField(ui->throttleD,ui->throttleD->geometry(),"D", conf->getValue("Throttle D"));
    longitudeP = new inputField(ui->longitudeP,ui->longitudeP->geometry(),"P", conf->getValue("Longitude P"));
    longitudeI = new inputField(ui->longitudeI,ui->longitudeI->geometry(),"I", conf->getValue("Longitude I"));
    longitudeD = new inputField(ui->longitudeD,ui->longitudeD->geometry(),"D", conf->getValue("Longitude D"));
    lattitudeP = new inputField(ui->lattitudeP,ui->lattitudeP->geometry(),"P", conf->getValue("Lateral P"));
    lattitudeI = new inputField(ui->lattitudeI,ui->lattitudeI->geometry(),"I", conf->getValue("Lateral I"));
    lattitudeD = new inputField(ui->lattitudeD,ui->lattitudeD->geometry(),"D", conf->getValue("Lateral D"));
    xP = new inputField(ui->xP,ui->xP->geometry(),"P", conf->getValue("XP"));
    xI = new inputField(ui->xI,ui->xI->geometry(),"I", conf->getValue("XI"));
    xD = new inputField(ui->xD,ui->xD->geometry(),"D", conf->getValue("XD"));
    yP = new inputField(ui->yP,ui->yP->geometry(),"P", conf->getValue("YP"));
    yI = new inputField(ui->yI,ui->yI->geometry(),"I", conf->getValue("YI"));
    yD = new inputField(ui->yD,ui->yD->geometry(),"D", conf->getValue("YD"));
    zP = new inputField(ui->zP,ui->zP->geometry(),"P", conf->getValue("YP"));
    zI = new inputField(ui->zI,ui->zI->geometry(),"I", conf->getValue("YI"));
    zD = new inputField(ui->zD,ui->zD->geometry(),"D", conf->getValue("YD"));
    throttleValue = new inputField(ui->throttleValue,ui->throttleValue->geometry(),"Throttle limit", conf->getValue("Throttle"));
    phiValue = new inputField(ui->phiValue,ui->phiValue->geometry(),"Phi limit in radians", conf->getValue("Phi"));
    thetaValue = new inputField(ui->thetaValue,ui->thetaValue->geometry(),"Theta limit in radians", conf->getValue("Theta"));
    stallValue = new inputField(ui->stallValue,ui->stallValue->geometry(),"Stall", conf->getValue("Stall"));

    connect(conf,SIGNAL(update()),this,SLOT(update()));
}

void airplaneTemplate::save(){
    conf->setPath(pathField->getValue());
    conf->setInf(infField->getValue());
    conf->setOrbit(orbitField->getValue());
    conf->setThrottleX(throttleP->getValue());
    conf->setThrottleY(throttleI->getValue());
    conf->setThrottleZ(throttleD->getValue());
    conf->setLongitudeX(longitudeP->getValue());
    conf->setLongitudeY(longitudeI->getValue());
    conf->setLongitudeZ(longitudeD->getValue());
    conf->setLattitudeX(lattitudeP->getValue());
    conf->setLattitudeY(lattitudeI->getValue());
    conf->setLattitudeZ(lattitudeD->getValue());
    conf->setXP(xP->getValue());
    conf->setXI(xI->getValue());
    conf->setXD(xD->getValue());
    conf->setYP(yP->getValue());
    conf->setYI(yI->getValue());
    conf->setYD(yD->getValue());
    conf->setZP(zP->getValue());
    conf->setZI(zI->getValue());
    conf->setZD(zD->getValue());
    conf->setThrottle(throttleValue->getValue());
    conf->setPhi(phiValue->getValue());
    conf->setTheta(thetaValue->getValue());
    conf->setStall(stallValue->getValue());
}

void airplaneTemplate::update(){
    pathField->setValue(conf->getValue("Path"));
    infField->setValue(conf->getValue("Inf"));
    orbitField->setValue(conf->getValue("Orbit"));
    throttleP->setValue(conf->getValue("Throttle P"));
    throttleI->setValue(conf->getValue("Throttle I"));
    throttleD->setValue(conf->getValue("Throttle D"));
    longitudeP->setValue(conf->getValue("Longitude P"));
    longitudeI->setValue(conf->getValue("Longitude I"));
    longitudeD->setValue(conf->getValue("Longitude D"));
    lattitudeP->setValue(conf->getValue("Lateral P"));
    lattitudeI->setValue(conf->getValue("Lateral I"));
    lattitudeD->setValue(conf->getValue("Lateral D"));
    xP->setValue(conf->getValue("XP"));
    xI->setValue(conf->getValue("XI"));
    xD->setValue(conf->getValue("XD"));
    yP->setValue(conf->getValue("YP"));
    yI->setValue(conf->getValue("YI"));
    yD->setValue(conf->getValue("YD"));
    zP->setValue(conf->getValue("YP"));
    zI->setValue(conf->getValue("YI"));
    zD->setValue(conf->getValue("YD"));
    throttleValue->setValue(conf->getValue("Throttle"));
    phiValue->setValue(conf->getValue("Phi"));
    thetaValue->setValue(conf->getValue("Theta"));
    stallValue->setValue(conf->getValue("Stall"));
}

airplaneTemplate::~airplaneTemplate()
{
    delete ui;
}

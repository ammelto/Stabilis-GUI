#include "../headers/airplanetemplate.h"
#include "../headers/configcreator.h"
#include "ui_airplanetemplate.h"
#include <QFontDatabase>
#include <QDebug>

airplaneTemplate::airplaneTemplate(QWidget *parent, configcreator *config) :
    QWidget(parent),
    ui(new Ui::airplaneTemplate)
{
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

    pathField = new inputField(ui->pathValue,ui->pathValue->geometry(),"Path Value", config->getValue("Path"));
    infField = new inputField(ui->infValue,ui->infValue->geometry(),"Inference Value", config->getValue("Inf"));
    orbitField = new inputField(ui->orbitValue,ui->orbitValue->geometry(),"Orbit Value", config->getValue("Orbit"));
    throttleP = new inputField(ui->throttleP,ui->throttleP->geometry(),"P", config->getValue("Throttle P"));
    throttleI = new inputField(ui->throttleI,ui->throttleI->geometry(),"I", config->getValue("Throttle I"));
    throttleD = new inputField(ui->throttleD,ui->throttleD->geometry(),"D", config->getValue("Throttle D"));
    longitudeP = new inputField(ui->longitudeP,ui->longitudeP->geometry(),"P", config->getValue("Longitude P"));
    longitudeI = new inputField(ui->longitudeI,ui->longitudeI->geometry(),"I", config->getValue("Longitude I"));
    longitudeD = new inputField(ui->longitudeD,ui->longitudeD->geometry(),"D", config->getValue("Longitude D"));
    lattitudeP = new inputField(ui->lattitudeP,ui->lattitudeP->geometry(),"P", config->getValue("Lateral P"));
    lattitudeI = new inputField(ui->lattitudeI,ui->lattitudeI->geometry(),"I", config->getValue("Lateral I"));
    lattitudeD = new inputField(ui->lattitudeD,ui->lattitudeD->geometry(),"D", config->getValue("Lateral D"));
    xP = new inputField(ui->xP,ui->xP->geometry(),"P", config->getValue("XP"));
    xI = new inputField(ui->xI,ui->xI->geometry(),"I", config->getValue("XI"));
    xD = new inputField(ui->xD,ui->xD->geometry(),"D", config->getValue("XD"));
    yP = new inputField(ui->yP,ui->yP->geometry(),"P", config->getValue("YP"));
    yI = new inputField(ui->yI,ui->yI->geometry(),"I", config->getValue("YI"));
    yD = new inputField(ui->yD,ui->yD->geometry(),"D", config->getValue("YD"));
    zP = new inputField(ui->zP,ui->zP->geometry(),"P", config->getValue("YP"));
    zI = new inputField(ui->zI,ui->zI->geometry(),"I", config->getValue("YI"));
    zD = new inputField(ui->zD,ui->zD->geometry(),"D", config->getValue("YD"));
    throttleValue = new inputField(ui->throttleValue,ui->throttleValue->geometry(),"Throttle limit", config->getValue("Throttle"));
    phiValue = new inputField(ui->phiValue,ui->phiValue->geometry(),"Phi limit in radians", config->getValue("Phi"));
    thetaValue = new inputField(ui->thetaValue,ui->thetaValue->geometry(),"Theta limit in radians", config->getValue("Theta"));
    stallValue = new inputField(ui->stallValue,ui->stallValue->geometry(),"Stall", config->getValue("Stall"));

}

void airplaneTemplate::setTheme(QColor p, QColor s, QColor f){
    pathField->setTheme(s);
    infField->setTheme(s);
    orbitField->setTheme(s);
    throttleP->setTheme(s);
    throttleI->setTheme(s);
    throttleD->setTheme(s);
    longitudeP->setTheme(s);
    longitudeI->setTheme(s);
    longitudeD->setTheme(s);
    lattitudeP->setTheme(s);
    lattitudeI->setTheme(s);
    lattitudeD->setTheme(s);
    xP->setTheme(s);
    xI->setTheme(s);
    xD->setTheme(s);
    yP->setTheme(s);
    yI->setTheme(s);
    yD->setTheme(s);
    zP->setTheme(s);
    zI->setTheme(s);
    zD->setTheme(s);
    throttleValue->setTheme(s);
    phiValue->setTheme(s);
    thetaValue->setTheme(s);
    stallValue->setTheme(s);
}

void airplaneTemplate::save(){

}

airplaneTemplate::~airplaneTemplate()
{
    delete ui;
}

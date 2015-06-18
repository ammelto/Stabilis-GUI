#include "../headers/configvehiclesettings.h"
#include "./genericbutton.h"
#include "ui_configvehiclesettings.h"
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>

configvehiclesettings::configvehiclesettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configvehiclesettings)
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
    ui->loadedVehicle->setFont(QFont("Roboto",11));
    ui->bankPitchLimit->setFont(QFont("Roboto",11));
    ui->IDLabel->setFont(QFont("Roboto",11));
    ui->innerLoopLabel->setFont(QFont("Roboto",11));
    ui->outerLoopLabel->setFont(QFont("Roboto",11));
    ui->referencesLabel->setFont(QFont("Roboto",11));
    ui->stallLabel->setFont(QFont("Roboto",11));
    //
    ui->bankPitchPhiDetail->setFont(QFont("Roboto",9));
    ui->bankPitchThetaDetail->setFont(QFont("Roboto",9));
    ui->bankPitchThtrottleDetail->setFont(QFont("Roboto",9));
    ui->hLongitudeDetail->setFont(QFont("Roboto",9));
    ui->IDDetailLabel->setFont(QFont("Roboto",9));
    ui->kThrottleDetail->setFont(QFont("Roboto",9));
    ui->referenceOneDetail->setFont(QFont("Roboto",9));
    ui->referenceTwoDetail->setFont(QFont("Roboto",9));
    ui->referenceThreeDetail->setFont(QFont("Roboto",9));
    ui->stallDetail->setFont(QFont("Roboto",9));
    ui->xPIDDetail->setFont(QFont("Roboto",9));
    ui->xyLatitudeDetail->setFont(QFont("Roboto",9));
    ui->yPIDDetail->setFont(QFont("Roboto",9));
    ui->zPIDDetail->setFont(QFont("Roboto",9));

}

void configvehiclesettings::setTheme(QColor p, QColor s, QColor f){
    genericButton *advancedButton = new genericButton(ui->advancedButton);
    genericButton *loadButton = new genericButton(ui->loadVehicleButton);
    genericButton *newButton = new genericButton(ui->newVehicleButton);

    advancedButton->setButtonText("Advanced...");
    loadButton->setButtonText("Load vehicle");
    newButton->setButtonText("New vehicle");

    advancedButton->setTheme(p,s,f);
    loadButton->setTheme(p,s,f);
    newButton->setTheme(p,s,f);
}

configvehiclesettings::~configvehiclesettings()
{
    delete ui;
}

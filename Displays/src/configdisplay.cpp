#include "../headers/configdisplay.h"
#include "../config_materials/headers/configcontrollersettings.h"
#include "../config_materials/headers/configgeneralsettings.h"
#include "../config_materials/headers/confignetworksettings.h"
#include "../config_materials/headers/configvehiclesettings.h"
#include "../config_materials/headers/configcreator.h"
#include "ui_configdisplay.h"
#include <QDebug>
#include <QGraphicsDropShadowEffect>

configdisplay::configdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configdisplay)
{

    ui->setupUi(this);
    configcreator *config = new configcreator;

    controllerSettings = new configcontrollersettings(ui->controllerSettings, config);
    generalSettings = new configGeneralSettings(ui->generalSettings, config);
    networkSettings = new confignetworksettings(ui->networkSettings, config);
    vehicleSettings = new configvehiclesettings(ui->vehicleSettings, config);
}

void configdisplay::setTheme(QColor p, QColor s, QColor f){
    vehicleSettings->setTheme(p,s,f);
    generalSettings->setTheme(p,s,f);
}

void configdisplay::save(){

}

configdisplay::~configdisplay()
{
    delete ui;
}

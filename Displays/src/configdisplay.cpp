#include "../headers/configdisplay.h"
#include "../config_materials/headers/configcontrollersettings.h"
#include "../config_materials/headers/configgeneralsettings.h"
#include "../config_materials/headers/confignetworksettings.h"
#include "../config_materials/headers/configvehiclesettings.h"
#include "ui_configdisplay.h"
#include <QDebug>
#include <QGraphicsDropShadowEffect>

configdisplay::configdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configdisplay)
{

    ui->setupUi(this);

    controllerSettings = new configcontrollersettings(ui->controllerSettings);
    generalSettings = new configGeneralSettings(ui->generalSettings);
    networkSettings = new confignetworksettings(ui->networkSettings);
    vehicleSettings = new configvehiclesettings(ui->vehicleSettings);
}

void configdisplay::setTheme(QColor p, QColor s, QColor f){
    vehicleSettings->setTheme(p,s,f);
    generalSettings->setTheme(p,s,f);
}

configdisplay::~configdisplay()
{
    delete ui;
}

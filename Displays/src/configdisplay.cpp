#include "../headers/configdisplay.h"
#include "../config_materials/headers/configcontrollersettings.h"
#include "../config_materials/headers/configgeneralsettings.h"
#include "../config_materials/headers/confignetworksettings.h"
#include "../config_materials/headers/configvehiclesettings.h"
#include "../config_materials/headers/configcreator.h"
#include "ui_configdisplay.h"
#include <QSettings>
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

    connect(config,SIGNAL(update()),this,SLOT(update()));

}

void configdisplay::setTheme(QColor p, QColor s, QColor f){
    vehicleSettings->setTheme(p,s,f);
}

void configdisplay::save(){

}

void configdisplay::update(){
    QSettings settings(":/files/Stabilis.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    setTheme(QColor(settings.value("primary").toString()), QColor(settings.value("secondary").toString()), QColor(settings.value("font").toString()));
    settings.endGroup();
}

configdisplay::~configdisplay()
{
    delete ui;
}

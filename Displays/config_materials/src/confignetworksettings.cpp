#include "../headers/confignetworksettings.h"
#include "../headers/configcreator.h"
#include "ui_confignetworksettings.h"
#include <QGraphicsDropShadowEffect>

confignetworksettings::confignetworksettings(QWidget *parent, configcreator *config) :
    QWidget(parent),
    ui(new Ui::confignetworksettings)
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
}

void confignetworksettings::save(){

}

confignetworksettings::~confignetworksettings()
{
    delete ui;
}

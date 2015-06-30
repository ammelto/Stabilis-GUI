#include "../headers/configgeneralsettings.h"
#include "../headers/configcreator.h"
#include "ui_configgeneralsettings.h"
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QDebug>
#include <QBrush>
#include <QPainter>

configGeneralSettings::configGeneralSettings(QWidget *parent, configcreator *config) :
    QWidget(parent),
    ui(new Ui::configGeneralSettings)
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
    ui->simulationLabel->setFont(QFont("Roboto",11));
    ui->simDetailLabel->setFont(QFont("Roboto",9));
    ui->htlLabel->setFont(QFont("Roboto",11));
    ui->htlDetailLabel->setFont(QFont("Roboto",9));
    ui->gcsCommsLabel->setFont(QFont("Roboto",11));
    ui->gcsDetailLabel->setFont(QFont("Roboto",9));
    ui->dataLoggingLabel->setFont(QFont("Roboto",11));
    ui->dataDetailLabel->setFont(QFont("Roboto",9));

    connect(ui->simulationToggle,SIGNAL(valueChanged(int)),this,SLOT(toggleListener(int)));
    connect(ui->htlToggle,SIGNAL(valueChanged(int)),this,SLOT(toggleListener(int)));
    connect(ui->dataToggle,SIGNAL(valueChanged(int)),this,SLOT(toggleListener(int)));
    connect(ui->gcsToggle,SIGNAL(valueChanged(int)),this,SLOT(toggleListener(int)));
}

void configGeneralSettings::toggleListener(int value){
    QObject* obj = sender();

    if(obj == ui->simulationToggle){
        if(value == 1){
           ui->simulationToggle->setStyleSheet("QSlider::groove:horizontal { background: "+ secondary.name() +"; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
           qDebug("Simulation on");
        }else if(value == 0){
           ui->simulationToggle->setStyleSheet("QSlider::groove:horizontal { background:#9E9E9E;  height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
           qDebug("Simulation off");
        }
    }else if(obj == ui->htlToggle){
        if(value == 1){
           ui->htlToggle->setStyleSheet("QSlider::groove:horizontal { background: "+ secondary.name() +"; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
           qDebug("HTL on");
        }else if(value == 0){
           ui->htlToggle->setStyleSheet("QSlider::groove:horizontal { background: #9E9E9E; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
           qDebug("HTL off");
        }
    }else if(obj == ui->gcsToggle){
        if(value == 1){
           ui->gcsToggle->setStyleSheet("QSlider::groove:horizontal { background: "+ secondary.name() +"; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
           qDebug("GCS on");
        }else if(value == 0){
           ui->gcsToggle->setStyleSheet("QSlider::groove:horizontal { background: #9E9E9E; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
           qDebug("GCS off");
        }
    }else if(obj == ui->dataToggle){
        if(value == 1){
           ui->dataToggle->setStyleSheet("QSlider::groove:horizontal { background: "+ secondary.name() +"; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
           qDebug("Logging on");
        }else if(value == 0){
           ui->dataToggle->setStyleSheet("QSlider::groove:horizontal { background: #9E9E9E; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
           qDebug("Logging off");
        }
    }
}

void configGeneralSettings::setTheme(QColor p, QColor s, QColor f){
    primary = p;
    secondary = s;
    font = f;
}

void configGeneralSettings::save(){

}

configGeneralSettings::~configGeneralSettings()
{
    delete ui;
}

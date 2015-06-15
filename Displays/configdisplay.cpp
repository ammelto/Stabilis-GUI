#include "configdisplay.h"
#include "ui_configdisplay.h"
#include <QDebug>
#include <QGraphicsDropShadowEffect>

configdisplay::configdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configdisplay)
{

    ui->setupUi(this);

    connect(ui->sliderbutton,SIGNAL(valueChanged(int)),this,SLOT(toggleListener(int)));

    QGraphicsDropShadowEffect* generalShadow = new QGraphicsDropShadowEffect();
    generalShadow->setBlurRadius(6);
    generalShadow->setColor(QColor(0,0,0,200));
    generalShadow->setOffset(0);
    ui->generalSettings->setGraphicsEffect(generalShadow);
    //
    QPalette pal = ui->generalSettings->palette();
    pal.setColor(ui->generalSettings->backgroundRole(), QColor(255,255,255));
    ui->generalSettings->setPalette(pal);
    ui->generalSettings->setAutoFillBackground(true);

    QGraphicsDropShadowEffect* networkShadow = new QGraphicsDropShadowEffect();
    networkShadow->setBlurRadius(6);
    networkShadow->setColor(QColor(0,0,0,200));
    networkShadow->setOffset(0);
    ui->networkSettings->setGraphicsEffect(networkShadow);
    //
    pal = ui->networkSettings->palette();
    pal.setColor(ui->networkSettings->backgroundRole(), QColor(255,255,255));
    ui->networkSettings->setPalette(pal);
    ui->networkSettings->setAutoFillBackground(true);

    QGraphicsDropShadowEffect* vehicleShadow = new QGraphicsDropShadowEffect();
    vehicleShadow->setBlurRadius(6);
    vehicleShadow->setColor(QColor(0,0,0,200));
    vehicleShadow->setOffset(0);
    ui->vehicleSettings->setGraphicsEffect(vehicleShadow);
    //
    pal = ui->vehicleSettings->palette();
    pal.setColor(ui->vehicleSettings->backgroundRole(), QColor(255,255,255));
    ui->vehicleSettings->setPalette(pal);
    ui->vehicleSettings->setAutoFillBackground(true);

}

void configdisplay::toggleListener(int value){
    QObject* obj = sender();

    int temp;
    if(obj == ui->sliderbutton){
        qDebug() << value;
        if(value == 1){
           ui->sliderbutton->setStyleSheet("QSlider::groove:horizontal { background: green; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
        }else if(value == 0){
           ui->sliderbutton->setStyleSheet("QSlider::groove:horizontal { background: grey; height: 14px; border-radius: 7px; } "
                                           "QSlider::handle:horizontal { background:white; width: 12px; height: 14px; margin: 1px; border-radius: 5px; }");
        }
    }
}

configdisplay::~configdisplay()
{
    delete ui;
}

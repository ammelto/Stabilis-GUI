#include "../headers/confignetworksettings.h"
#include "../headers/configcreator.h"
#include "./inputfield.h"
#include "./genericbutton.h"
#include "ui_confignetworksettings.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QFontDatabase>

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

    QFontDatabase::addApplicationFont("qrc:/fonts/Resources/fonts/Roboto-Bold.ttf");
    ui->windowLabel->setFont(QFont("Roboto",11));
    ui->addressLabel->setFont(QFont("Roboto",11));
    ui->userLabel->setFont(QFont("Roboto",11));
    ui->connectionLabel->setFont(QFont("Roboto",11));
    //
    ui->addressDetail->setFont(QFont("Roboto",9));
    ui->portDetail->setFont(QFont("Roboto",9));
    ui->userName->setFont(QFont("Roboto",9));
    ui->userPassword->setFont(QFont("Roboto",9));

    addressField = new inputField(ui->addressValue,ui->addressValue->geometry(),"Host Name","");
    portField = new inputField(ui->portValue,ui->portValue->geometry(),"Port","");
    nameField = new inputField(ui->userNameValue, ui->userNameValue->geometry(),"Username","");
    passField = new inputField(ui->userPasswordValue, ui->userPasswordValue->geometry(),"Password","$PASSFIELD");

    connectButton = new genericButton(ui->connectButton);
    connectButton->setButtonText("Connect");

    connect(connectButton,SIGNAL(pressed()),this,SLOT(connectButtonHandler()));

}

void confignetworksettings::setTheme(QColor p, QColor s, QColor f){
    connectButton->setTheme(p,s,f);
}

void confignetworksettings::connectButtonHandler(){
    qDebug() << "Connecting...";
    startConnection(addressField->getValue(),portField->getValue(),nameField->getValue(),passField->getValue());
    connectButton->disable();
    connectButton->setButtonText("Connecting...");
}

void confignetworksettings::returnCode(int code){
    switch(code){
    case 0:
        connectButton->enable();
        connectButton->setButtonText("Connecting...");
        ui->connectionLabel->setText("Connected");
        break;
    case 1:
        ui->connectionLabel->setText("Disconnected");
        // Generic Error
        break;
    case 2:
        ui->connectionLabel->setText("Disconnected");
        //Remote host connection failure
        break;
    }
}

confignetworksettings::~confignetworksettings()
{
    delete ui;
}

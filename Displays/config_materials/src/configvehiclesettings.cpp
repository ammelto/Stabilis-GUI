#include "../headers/configvehiclesettings.h"
#include "../headers/loadvehicledialog.h"
#include "../headers/configcreator.h"
#include "ui_configvehiclesettings.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QListWidget>
#include <QFileDialog>
#include <QFormLayout>
#include <QFontDatabase>
#include <QSettings>
#include <QErrorMessage>

configvehiclesettings::configvehiclesettings(QWidget *parent, configcreator *config) :
    QWidget(parent),
    ui(new Ui::configvehiclesettings)
{
    ui->setupUi(this);
    conf = config;

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
    ui->windowLabel->setFont(QFont("Roboto",13));
    ui->loadedVehicle->setFont(QFont("Roboto",13));
    ui->overlay->setFont(QFont("Roboto",13));

    advancedButton = new genericButton(ui->advancedButton);
    loadButton = new genericButton(ui->loadVehicleButton);
    saveButton = new genericButton(ui->saveVehicleButton);
    //
    advancedButton->setButtonText("Advanced...");
    loadButton->setButtonText("Load vehicle");
    saveButton->setButtonText("Save vehicle");

    QSettings settings("../Stabilis-GUI/Stabilis.ini", QSettings::IniFormat);
    settings.beginGroup("Vehicle");
    load(settings.value("load").toString());
    settings.endGroup();

    connect(saveButton,SIGNAL(pressed()),this,SLOT(buttonHandler()));
    connect(loadButton,SIGNAL(pressed()),this,SLOT(buttonHandler()));
    connect(advancedButton,SIGNAL(pressed()),this,SLOT(buttonHandler()));

}

void configvehiclesettings::load(QString file){
    if(!file.contains(".stb")){
        file.append(".stb");
    }
    qDebug() << file;
    conf->loadFile(file);
    QString s = conf->getValue("Vehicle ID");
    qDebug() << s;

    ui->loadedVehicle->setText(conf->getValue("Name"));
    ui->loadedVehicle->setAlignment(Qt::AlignRight);

    if(s == "5"){
        if(fileList != NULL) fileList->hide();

        if(airplaneSheet == NULL){
            airplaneSheet = new airplaneTemplate(ui->settingsArea, conf);
        }
        currentTemplate = airplaneSheet;
        ui->overlay->setText("");
        ui->windowLabel->setText("Airplane");

        currentTemplate->show();
        setDefaultState();
    }else if(s == "" && state != loadState){
        currentTemplate = NULL;
        setLoadState();
    }else{
        QErrorMessage *msg = new QErrorMessage(this);
        ui->loadedVehicle->setText("");
        msg->showMessage("File not recognized. Check your vehicle ID and try again.");
    }
}

void configvehiclesettings::select(QListWidgetItem *item){
    load("../Userdata/" + item->text());
}

void configvehiclesettings::setTheme(QColor p, QColor s, QColor f){
    advancedButton->setTheme(p,s,f);
    loadButton->setTheme(p,s,f);
    saveButton->setTheme(p,s,f);
}

void configvehiclesettings::save(){
    if(airplaneSheet != NULL){
        airplaneSheet->save();
        qDebug() << "SAVED";
    }
}

void configvehiclesettings::buttonHandler(){
    QObject* obj = sender();
    if(obj == saveButton){
        if(state == defaultState){
            this->save();
            qDebug() << "Save";
        }else if(state == advancedState){
            qDebug() << "OK";
            setDefaultState();
        }else if(state == loadState){
            qDebug() << "Select";
            setDefaultState();
            load("../Userdata/" + fileList->getSelected());
        }
    }else if(obj == advancedButton){
        if(state == defaultState){
            qDebug() << "Advanced";
            setAdvancedState();
        }else if(state == advancedState){
            qDebug() << "Back";
            setDefaultState();
        }else if(state == loadState){
            qDebug() << "New Vehicle";

        }
    }else if(obj == loadButton){
        if(state == defaultState){
            qDebug() << "Load";
            setLoadState();
        }else if(state == advancedState){
            qDebug() << "Apply";
        }else if(state == loadState){
            qDebug() << "Browse...";
            QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"../Userdata",tr("Stb Files (*.stb)"));
            load(fileName);
        }
    }
}

void configvehiclesettings::setDefaultState(){
    advancedButton->setButtonText("Advanced...");
    loadButton->setButtonText("Load");
    saveButton->setButtonText("Save");
    state = defaultState;
}

void configvehiclesettings::setAdvancedState(){
    advancedButton->setButtonText("Back");
    loadButton->setButtonText("Apply");
    saveButton->setButtonText("OK");
    state = advancedState;
    currentTemplate->hide();
}

void configvehiclesettings::setLoadState(){
    state = loadState;

    advancedButton->setButtonText("New Vehicle");
    loadButton->setButtonText("Browse...");
    saveButton->setButtonText("Select");

    ui->overlay->setText("Load or create a vehicle");
    ui->overlay->setAlignment(Qt::AlignCenter);
    ui->windowLabel->setText("");
    ui->loadedVehicle->setText("");

    if(fileList == NULL){
        fileList = new LoadVehicleDialog(ui->settingsArea, conf);
        connect(fileList->getListWidget(), SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(select(QListWidgetItem*)));
        fileList->show();
    }else{
        fileList->show();
    }

    if(currentTemplate != NULL){
        currentTemplate->hide();
    }
}

void configvehiclesettings::setNewState(){

}

configvehiclesettings::~configvehiclesettings()
{
    delete ui;
}

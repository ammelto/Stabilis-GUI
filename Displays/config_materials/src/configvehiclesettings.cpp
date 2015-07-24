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

//Since the vehicle settings model has multiple views, each view is controlled by a seperate state.
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

    //These object names do not imply their
    //only functionality, but rather reference the default button they represent.
    //This is clearer than saying button1, button2, button3 but can be a little misleading.
    advancedButton = new genericButton(ui->advancedButton);
    loadButton = new genericButton(ui->loadVehicleButton);
    saveButton = new genericButton(ui->saveVehicleButton);
    //
    advancedButton->setButtonText("Advanced...");
    loadButton->setButtonText("Load vehicle");
    saveButton->setButtonText("Save vehicle");

    QSettings settings(":/files/Stabilis.ini", QSettings::IniFormat);
    settings.beginGroup("Vehicle");
    load(settings.value("load").toString());
    settings.endGroup();

    connect(saveButton,SIGNAL(pressed()),this,SLOT(buttonHandler()));
    connect(loadButton,SIGNAL(pressed()),this,SLOT(buttonHandler()));
    connect(advancedButton,SIGNAL(pressed()),this,SLOT(buttonHandler()));

}

void configvehiclesettings::load(QString file){
    QString s = "";
    if(file != ""){
        if(!file.contains(".stb")) file.append(".stb");

        qDebug() << file;
        conf->loadFile(file);
        s = conf->getValue("Vehicle ID");
        qDebug() << s;

        ui->loadedVehicle->setText(conf->getValue("Name"));
        ui->loadedVehicle->setAlignment(Qt::AlignRight);
    }

    //5 represents an airplane ID
    if(s == "5"){
        if(fileList != NULL) fileList->hide();

        //Instantiates the object if it has not been already
        if(airplaneSheet == NULL){
            airplaneSheet = new airplaneTemplate(ui->settingsArea, conf);
        }
        //CurrentTemplate is a global pointer that always points to the current active view
        currentTemplate = airplaneSheet;
        ui->overlay->setText("");
        ui->windowLabel->setText("Airplane");

        currentTemplate->show();
        setDefaultState();
    }else if(s == "" && state != loadState){
        currentTemplate = NULL;
        setLoadState();
    //Only fails if the VID is not present or the file is unreadable
    }else{
        QErrorMessage *msg = new QErrorMessage(this);
        ui->loadedVehicle->setText("");
        msg->showMessage("File not recognized. Check your vehicle ID and try again.");
        conf->revert();
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
        this->globalSave();
    }
}

//Changes the text of the buttons accordingly
void configvehiclesettings::buttonHandler(){
    QObject* obj = sender();
    if(obj == saveButton){
        if(state == defaultState){
            this->save();
            qDebug() << "Save";
        }else if(state == advancedState){
            qDebug() << "Load";
            setLoadState();
        }else if(state == loadState){
            qDebug() << "New";
            setAdvancedState();
        }
    }else if(obj == advancedButton){
        if(state == defaultState){
            qDebug() << "New Vehicle";
            setAdvancedState();
        }else if(state == advancedState){
            qDebug() << "Cancel";
            setDefaultState();
        }else if(state == loadState){
            qDebug() << "Back";
            setDefaultState();
        }
    }else if(obj == loadButton){
        if(state == defaultState){
            qDebug() << "Load";
            setLoadState();
        }else if(state == advancedState){
            qDebug() << "OK";
        }else if(state == loadState){
            qDebug() << "Browse...";
            QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"../Userdata",tr("Stb Files (*.stb)"));
            load(fileName);
        }
    }
}

void configvehiclesettings::setDefaultState(){
    advancedButton->setButtonText("New");
    loadButton->setButtonText("Load");
    saveButton->setButtonText("Save");
    if(state == loadState) fileList->hide();
    if(state == advancedState) newVehicle->hide();
    if(currentTemplate != NULL) currentTemplate->show();

    ui->loadedVehicle->setText(conf->getValue("Name"));
    ui->overlay->setText("");
    if(currentTemplate = airplaneSheet) ui->windowLabel->setText("Airplane");
    state = defaultState;
}

void configvehiclesettings::setAdvancedState(){
    advancedButton->setButtonText("Cancel");
    loadButton->setButtonText("OK");
    saveButton->setButtonText("Load");
    if(state == loadState) fileList->hide();
    ui->loadedVehicle->setText("");
    ui->windowLabel->setText("");
    ui->overlay->setText("Create a new vehicle");
    ui->overlay->setAlignment(Qt::AlignCenter);
    state = advancedState;

    if(newVehicle == NULL){
        newVehicle = new newVehicleDialog(ui->settingsArea);
        newVehicle->show();
    }else{
        newVehicle->show();
    }

    if(currentTemplate != NULL){
        currentTemplate->hide();
    }
}

void configvehiclesettings::setLoadState(){
    if(state == advancedState) newVehicle->hide();
    state = loadState;

    advancedButton->setButtonText("Back");
    loadButton->setButtonText("Browse...");
    saveButton->setButtonText("New");

    ui->overlay->setText("Load a vehicle");
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

#include "../Stabilis-GUI/Displays/config_materials/headers/loadvehicledialog.h"
#include "../headers/configcreator.h"
#include "ui_loadvehicledialog.h"
#include <QSettings>
#include <QDir>
#include <QDebug>
LoadVehicleDialog::LoadVehicleDialog(QWidget *parent, configcreator *config) :
    QWidget(parent),
    ui(new Ui::LoadVehicleDialog)
{
    ui->setupUi(this);
    conf = config;

    QSettings settings("../Stabilis-GUI/Stabilis.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");
    QString s = settings.value("secondary").toString();
    QString p = settings.value("primary").toString();
    QString f = settings.value("font").toString();
    ui->fileList->setStyleSheet("QListWidget{ border-width: 0px; background-color: white; } QListWidget::item:selected {background-color: " + p + "; color: " + f + "} QListWidget::item:hover{background-color: " + s + "}");
    settings.endGroup();

    QDir shortcutsFolder("../Userdata/");
    QFileInfoList shortcuts(shortcutsFolder.entryInfoList(QDir::Files, QDir::Name | QDir::IgnoreCase));

    foreach (QFileInfo fi, shortcuts){
        QListWidgetItem *item = new QListWidgetItem(fi.fileName());
        if(item->text().contains(".stb")){
            item->setText(item->text().replace(".stb",""));
            ui->fileList->addItem(item);
        }
    }
}

QString LoadVehicleDialog::getSelected(){
    QListWidgetItem *item = ui->fileList->currentItem();
    return item->text();
}

QListWidget* LoadVehicleDialog::getListWidget(){
    QListWidget *list(ui->fileList);
    return list;
}

LoadVehicleDialog::~LoadVehicleDialog()
{
    delete ui;
}

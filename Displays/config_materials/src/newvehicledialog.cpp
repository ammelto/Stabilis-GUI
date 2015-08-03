#include "../headers/newvehicledialog.h"
#include "../headers/configcreator.h"
#include "ui_newvehicledialog.h"
#include <QSettings>
#include <QFontDatabase>

newVehicleDialog::newVehicleDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newVehicleDialog)
{
    ui->setupUi(this);

    QSettings settings(":/files/Stabilis.ini", QSettings::IniFormat);
    settings.beginGroup("Settings");

    ui->VIDBox->setStyleSheet("QComboBox {border: 1px solid gray; border-radius: 1px;}"
                              "QComboBox:!editable:on, QComboBox::drop-down:editable:on {background: "+ settings.value("secondary").toString() +"; color: "+ settings.value("font").toString() +"; } "
                              "QComboBox:on { padding-top: 3px;padding-left: 4px;}"
                              "QComboBox::drop-down {width: 0px;}");

    settings.endGroup();

    QFontDatabase::addApplicationFont("qrc:/fonts/Resources/fonts/Roboto-Bold.ttf");
    ui->templateLabel->setFont(QFont("Roboto",11));
    //
    ui->templateDetail->setFont(QFont("Roboto",9));
    ui->nameDetail->setFont(QFont("Roboto",9));
    vName = new inputField(ui->nameValue,ui->nameValue->geometry(),"Name","");

}

QString newVehicleDialog::getName(){
    return vName->getValue();
}

QString newVehicleDialog::getType(){
    QString s;
    s = ui->VIDBox->currentText();
    return s;
}

newVehicleDialog::~newVehicleDialog()
{
    delete ui;
}

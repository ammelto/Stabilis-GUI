#include "../Stabilis-GUI/Displays/config_materials/headers/loadvehicledialog.h"
#include "ui_loadvehicledialog.h"

LoadVehicleDialog::LoadVehicleDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadVehicleDialog)
{
    ui->setupUi(this);
}

LoadVehicleDialog::~LoadVehicleDialog()
{
    delete ui;
}

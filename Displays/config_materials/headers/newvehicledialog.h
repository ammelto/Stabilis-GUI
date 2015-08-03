#ifndef NEWVEHICLEDIALOG_H
#define NEWVEHICLEDIALOG_H

#include <QWidget>
#include "../headers/configcreator.h"
#include "./inputfield.h"

namespace Ui {
class newVehicleDialog;
}

class newVehicleDialog : public QWidget
{
    Q_OBJECT

public:
    explicit newVehicleDialog(QWidget *parent = 0);
    QString getName();
    QString getType();
    ~newVehicleDialog();

private:
    Ui::newVehicleDialog *ui;
    inputField *vName;
};

#endif // NEWVEHICLEDIALOG_H

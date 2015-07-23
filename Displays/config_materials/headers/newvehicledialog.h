#ifndef NEWVEHICLEDIALOG_H
#define NEWVEHICLEDIALOG_H

#include <QWidget>
#include "../headers/configcreator.h"

namespace Ui {
class newVehicleDialog;
}

class newVehicleDialog : public QWidget
{
    Q_OBJECT

public:
    explicit newVehicleDialog(QWidget *parent = 0);
    ~newVehicleDialog();

private:
    Ui::newVehicleDialog *ui;
};

#endif // NEWVEHICLEDIALOG_H

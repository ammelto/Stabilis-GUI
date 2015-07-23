#ifndef LOADVEHICLEDIALOG_H
#define LOADVEHICLEDIALOG_H

#include "../headers/configcreator.h"
#include <QWidget>
#include <QListWidget>

namespace Ui {
class LoadVehicleDialog;
}

class LoadVehicleDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LoadVehicleDialog(QWidget *parent = 0, configcreator *config = 0);
    QString getSelected();
    QListWidget *getListWidget();
    ~LoadVehicleDialog();

private:
    configcreator *conf;
    Ui::LoadVehicleDialog *ui;
};


#endif // LOADVEHICLEDIALOG_H

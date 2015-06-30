#ifndef LOADVEHICLEDIALOG_H
#define LOADVEHICLEDIALOG_H

#include <QWidget>

namespace Ui {
class LoadVehicleDialog;
}

class LoadVehicleDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LoadVehicleDialog(QWidget *parent = 0);
    ~LoadVehicleDialog();

private:
    Ui::LoadVehicleDialog *ui;
};

#endif // LOADVEHICLEDIALOG_H

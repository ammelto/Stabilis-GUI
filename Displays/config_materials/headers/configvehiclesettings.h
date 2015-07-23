#ifndef CONFIGVEHICLESETTINGS_H
#define CONFIGVEHICLESETTINGS_H
#include "../headers/configvehiclesettings.h"
#include "../headers/airplanetemplate.h"
#include "../headers/loadvehicledialog.h"
#include "../headers/newvehicledialog.h"
#include "./configcreator.h"
#include "./genericbutton.h"
#include <QListWidget>
#include <QWidget>

namespace Ui {
class configvehiclesettings;
}

class configvehiclesettings : public QWidget
{
    Q_OBJECT

public:
    explicit configvehiclesettings(QWidget *parent = 0, configcreator *config = 0);
    void setTheme(QColor p, QColor s, QColor f);
    void save();
    ~configvehiclesettings();

private:
    int state = 0;
    enum{
        defaultState, advancedState, loadState, newState
    };
    configcreator *conf;
    QWidget *currentTemplate;
    newVehicleDialog *newVehicle;
    LoadVehicleDialog *fileList;
    airplaneTemplate *airplaneSheet;
    genericButton *advancedButton;
    genericButton *loadButton;
    genericButton *saveButton;

    void load(QString file);
    void setDefaultState();
    void setAdvancedState();
    void setLoadState();
    void setNewState();
    Ui::configvehiclesettings *ui;
public slots:
    void select(QListWidgetItem *item);
    void buttonHandler();
signals:
    void globalSave();
};

#endif // CONFIGVEHICLESETTINGS_H

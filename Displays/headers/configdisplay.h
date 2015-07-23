#ifndef CONFIGDISPLAY_H
#define CONFIGDISPLAY_H

#include "../config_materials/headers/configcontrollersettings.h"
#include "../config_materials/headers/configgeneralsettings.h"
#include "../config_materials/headers/confignetworksettings.h"
#include "../config_materials/headers/configvehiclesettings.h"
#include <QWidget>

namespace Ui {
class configdisplay;
}

class configdisplay : public QWidget
{
    Q_OBJECT

public:
    explicit configdisplay(QWidget *parent = 0);
    void setTheme(QColor p, QColor s, QColor f);
    void save();
    ~configdisplay();

public:
    configcontrollersettings *controllerSettings;
    configGeneralSettings *generalSettings;
    confignetworksettings *networkSettings;
    configvehiclesettings *vehicleSettings;
    Ui::configdisplay *ui;
public slots:
    void update();
};

#endif // CONFIGDISPLAY_H

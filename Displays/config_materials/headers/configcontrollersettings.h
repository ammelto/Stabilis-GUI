#ifndef CONFIGCONTROLLERSETTINGS_H
#define CONFIGCONTROLLERSETTINGS_H

#include <QWidget>
#include "./inputfield.h"
#include "./configcreator.h"

namespace Ui {
class configcontrollersettings;
}

class configcontrollersettings : public QWidget
{
    Q_OBJECT

public:
    explicit configcontrollersettings(QWidget *parent = 0, configcreator *config = 0);
    ~configcontrollersettings();

public slots:
    void update();
    void save();

private:
    Ui::configcontrollersettings *ui;
    configcreator *conf;

    inputField* sensors[6][5];
    inputField* controller[8][2];
    inputField* limits[3];
};

#endif // CONFIGCONTROLLERSETTINGS_H

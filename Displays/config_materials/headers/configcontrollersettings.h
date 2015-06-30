#ifndef CONFIGCONTROLLERSETTINGS_H
#define CONFIGCONTROLLERSETTINGS_H

#include <QWidget>
#include "./configcreator.h"

namespace Ui {
class configcontrollersettings;
}

class configcontrollersettings : public QWidget
{
    Q_OBJECT

public:
    explicit configcontrollersettings(QWidget *parent = 0, configcreator *config = 0);
    void save();
    ~configcontrollersettings();

private:
    Ui::configcontrollersettings *ui;
};

#endif // CONFIGCONTROLLERSETTINGS_H

#ifndef CONFIGNETWORKSETTINGS_H
#define CONFIGNETWORKSETTINGS_H

#include <QWidget>
#include "./configcreator.h"

namespace Ui {
class confignetworksettings;
}

class confignetworksettings : public QWidget
{
    Q_OBJECT

public:
    explicit confignetworksettings(QWidget *parent = 0, configcreator *config = 0);
    void save();
    ~confignetworksettings();

private:
    Ui::confignetworksettings *ui;
};

#endif // CONFIGNETWORKSETTINGS_H

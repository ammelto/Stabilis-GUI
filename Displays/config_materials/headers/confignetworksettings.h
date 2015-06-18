#ifndef CONFIGNETWORKSETTINGS_H
#define CONFIGNETWORKSETTINGS_H

#include <QWidget>

namespace Ui {
class confignetworksettings;
}

class confignetworksettings : public QWidget
{
    Q_OBJECT

public:
    explicit confignetworksettings(QWidget *parent = 0);
    ~confignetworksettings();

private:
    Ui::confignetworksettings *ui;
};

#endif // CONFIGNETWORKSETTINGS_H

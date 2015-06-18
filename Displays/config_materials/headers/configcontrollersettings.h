#ifndef CONFIGCONTROLLERSETTINGS_H
#define CONFIGCONTROLLERSETTINGS_H

#include <QWidget>

namespace Ui {
class configcontrollersettings;
}

class configcontrollersettings : public QWidget
{
    Q_OBJECT

public:
    explicit configcontrollersettings(QWidget *parent = 0);
    ~configcontrollersettings();

private:
    Ui::configcontrollersettings *ui;
};

#endif // CONFIGCONTROLLERSETTINGS_H

#ifndef CONFIGVEHICLESETTINGS_H
#define CONFIGVEHICLESETTINGS_H

#include <QWidget>

namespace Ui {
class configvehiclesettings;
}

class configvehiclesettings : public QWidget
{
    Q_OBJECT

public:
    explicit configvehiclesettings(QWidget *parent = 0);
    void setTheme(QColor p, QColor s, QColor f);
    ~configvehiclesettings();

private:
    Ui::configvehiclesettings *ui;
};

#endif // CONFIGVEHICLESETTINGS_H

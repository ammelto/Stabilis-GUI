#ifndef CONFIGGENERALSETTINGS_H
#define CONFIGGENERALSETTINGS_H

#include <QWidget>
#include "./configcreator.h"

namespace Ui {
class configGeneralSettings;
}

class configGeneralSettings : public QWidget
{
    Q_OBJECT

public:
    explicit configGeneralSettings(QWidget *parent = 0, configcreator *config = 0);
    void save();
    ~configGeneralSettings();


public slots:
    void toggleListener(int value);
    void update();

private:
    QColor primary;
    QColor secondary;
    QColor font;
    configcreator *conf;
    Ui::configGeneralSettings *ui;
};

#endif // CONFIGGENERALSETTINGS_H

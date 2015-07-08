#ifndef AIRPLANETEMPLATE_H
#define AIRPLANETEMPLATE_H
#include "./inputfield.h"
#include "./configcreator.h"
#include <QWidget>

namespace Ui {
class airplaneTemplate;
}

class airplaneTemplate : public QWidget
{
    Q_OBJECT

public:
    explicit airplaneTemplate(QWidget *parent = 0, configcreator *config = 0);
    void save();
    ~airplaneTemplate();

public slots:
    void update();

private:
    configcreator *conf;
    inputField *pathField, *infField, *orbitField, *throttleP, *throttleI, *throttleD,
    *lattitudeP, *lattitudeI, *lattitudeD, *longitudeP, *longitudeI, *longitudeD,
    *xP, *xI, *xD, *yP, *yI, *yD, *zP, *zI, *zD, *throttleValue, *phiValue, *thetaValue, *stallValue;
    Ui::airplaneTemplate *ui;
};

#endif // AIRPLANETEMPLATE_H

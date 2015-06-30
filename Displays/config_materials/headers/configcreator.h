#ifndef CONFIGCREATOR_H
#define CONFIGCREATOR_H
#include <QString>
#include <QFile>
#include <QMap>


class configcreator
{
public:
    void loadFile(QString s);
    void writeFile(QString s, QString v);
    QString readFile(QString s);
    QString getValue(QString key);

    //setters
    void setSimulationMode(QString v);
    void setHILMode(QString v);
    void setCommsMode(QString v);
    void setDataLogging(QString v);
    void setVehicleId(QString v);
    void setStall(QString v);
    void setPhi(QString v);
    void setTheta(QString v);
    void setThrottle(QString v);
    void setXP(QString v);
    void setXI(QString v);
    void setXD(QString v);
    void setYP(QString v);
    void setYI(QString v);
    void setYD(QString v);
    void setZP(QString v);
    void setZI(QString v);
    void setZD(QString v);
    void setLattitudeX(QString v);
    void setLattitudeY(QString v);
    void setLattitudeZ(QString v);
    void setLongitudeX(QString v);
    void setLongitudeY(QString v);
    void setLongitudeZ(QString v);
    void setThrottleX(QString v);
    void setThrottleY(QString v);
    void setThrottleZ(QString v);
    void setPath(QString v);
    void setInf(QString v);
    void setOrbit(QString v);
    void setName(QString v);
    //servos
    void setServoLimitAll(QString v);
    void setServoLimitElev(QString v);
    void setServoLimitRudder(QString v);
    void setSensorBus1(QString v);
    void setSensorBus2(QString v);
    void setSensorAddress1(QString v);
    void setSensorAddress2(QString v);
    void setBaroBus1(QString v);
    void setBaroBus2(QString v);
    void setBaroAddress1(QString v);
    void setBaroAddress2(QString v);
    void setVN(QString v);
    void setRadio(QString v);
    //controller settings
    void setAileronIn(QString v);
    void setElevatorIn(QString v);
    void setRudderIn(QString v);
    void setThrottleIn(QString v);
    void setFlapIn(QString v);
    void setAuxIn(QString v);
    void setModeIn(QString v);
    void setTriggerIn(QString v);
    void setAileronOut(QString v);
    void setElevatorOut(QString v);
    void setRudderOut(QString v);
    void setThrottleOut(QString v);
    void setFlapOut(QString v);
    void setAuxOut(QString v);
    void setModeOut(QString v);
    void setTriggerOut(QString v);
    configcreator();

protected:
    QFile *loadedFile;

private:
    QMap<QString, QString> map;
    void createMap();

    //setters
    QString getSimulationMode();
    QString getHILMode();
    QString getCommsMode();
    QString getDataLogging();
    QString getVehicleId();
    QString getStall();
    QString getPhi();
    QString getTheta();
    QString getThrottle();
    QString getXP();
    QString getXI();
    QString getXD();
    QString getYP();
    QString getYI();
    QString getYD();
    QString getZP();
    QString getZI();
    QString getZD();
    QString getLattitudeP();
    QString getLattitudeI();
    QString getLattitudeD();
    QString getLongitudeP();
    QString getLongitudeI();
    QString getLongitudeD();
    QString getThrottleP();
    QString getThrottleI();
    QString getThrottleD();
    QString getPath();
    QString getInf();
    QString getOrbit();
    QString getName();
    //servos
    QString getServoLimitAll();
    QString getServoLimitElev();
    QString getServoLimitRudder();
    QString getSensorBus1();
    QString getSensorBus2();
    QString getSensorAddress1();
    QString getSensorAddress2();
    QString getBaroBus1();
    QString getBaroBus2();
    QString getBaroAddress1();
    QString getBaroAddress2();
    QString getVN();
    QString getRadio();
    //controller settings
    QString getAileronIn();
    QString getElevatorIn();
    QString getRudderIn();
    QString getThrottleIn();
    QString getFlapIn();
    QString getAuxIn();
    QString getModeIn();
    QString getTriggerIn();
    QString getAileronOut();
    QString getElevatorOut();
    QString getRudderOut();
    QString getThrottleOut();
    QString getFlapOut();
    QString getAuxOut();
    QString getModeOut();
    QString getTriggerOut();

};

#endif // CONFIGCREATOR_H

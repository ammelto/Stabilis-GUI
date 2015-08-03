#include "../headers/configcreator.h"
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QMap>
#include <QApplication>

//Controller for the reading and writing of the config file
configcreator::configcreator()
{
    if(!QDir("../Userdata").exists()){
        QDir().mkdir("../Userdata");
        qDebug() << "Userdata directory created";
    }

}

void configcreator::loadFile(QString s){
    if(s == "") return;
    if(loadedFile != NULL) previousFile = loadedFile;
    loadedFile = new QFile(s);

    if(loadedFile->exists()){
;
        qDebug() << loadedFile;

        createMap();
        if(getValue("Vehicle ID") != ""){
            QSettings settings("../Stabilis-GUI/Stabilis.ini", QSettings::IniFormat);
            settings.beginGroup("Vehicle");
            settings.setValue("load",s);
            settings.endGroup();
        }
        update();
    }
}

QString configcreator::readFile(QString s){
    if(loadedFile->exists()){
        bool n = loadedFile->open(QIODevice::ReadOnly);
        if(n){
            QString file;
            while(!loadedFile->atEnd()){
                file = loadedFile->readLine();
                if(file.contains(s)){
                    file.replace(s,"");
                    file = file.simplified();
                    loadedFile->close();
                    loadedFile->flush();
                    return file;
                }
            }
            loadedFile->flush();
            loadedFile->close();
            //Did not find
        }else{
            qDebug() << " FAILED TO OPEN";
            //Failed to open
        }
    }else{
        qDebug() << "NO SUCH FILE";
        //Does not exist
    }
    return "";
}

void configcreator::newFile(QString name, QString type){
    qDebug() << name;
    qDebug() << type;

    if(!QFile("../Userdata/"+ name +".stb").exists()){
            QFile::copy(":/files/Userdata/config.stb","../Userdata/"+ name +".stb");
    }
    loadFile("../Userdata/"+ name + ".stb");
    loadedFile->setPermissions(QFile::WriteUser);

    setVehicleId("5");
}

void configcreator::revert(){
    if(previousFile != NULL){
        loadedFile = previousFile;
        createMap();
        update();
    }
}

void configcreator::createMap(){
    map["Name"] = getName();
    map["Simulation Mode"] = getSimulationMode();
    map["HIL Mode"] = getHILMode();
    map["Comms Mode"] = getCommsMode();
    map["Data Logging"] = getDataLogging();
    map["Vehicle ID"] = getVehicleId();
    map["Stall"] = getStall();
    map["Phi"] = getPhi();
    map["Theta"] = getTheta();
    map["Throttle"] = getThrottle();
    map["XP"] = getXP();
    map["XI"] = getXI();
    map["XD"] = getXD();
    map["YP"] = getYP();
    map["YI"] = getYI();
    map["YD"] = getYD();
    map["ZP"] = getZP();
    map["ZI"] = getZI();
    map["ZD"] = getZD();
    map["Lateral P"] = getLattitudeP();
    map["Lateral I"] = getLattitudeI();
    map["Lateral D"] = getLattitudeD();
    map["Longitude P"] = getLongitudeP();
    map["Longitude I"] = getLongitudeI();
    map["Longitude D"] = getLongitudeD();
    map["Throttle P"] = getThrottleP();
    map["Throttle I"] = getThrottleI();
    map["Throttle D"] = getThrottleD();
    map["Path"] = getPath();
    map["Inf"] = getInf();
    map["Orbit"] = getOrbit();
    map["Servo Limit ALL"] = getServoLimitAll();
    map["Servo Limit ELEV"] = getServoLimitElev();
    map["Servo Limit RUDDER"] = getServoLimitRudder();
    map["Sensor Bus 1"] = getSensorBus1();
    map["Sensor Bus 2"] = getSensorBus2();
    map["Sensor Bus Address 1"] = getSensorAddress1();
    map["Sensor Bus Address 2"] = getSensorAddress2();
    map["Baro Bus 1"] = getBaroBus1();
    map["Baro Bus 2"] = getBaroBus2();
    map["Baro Bus Address 1"] = getBaroAddress1();
    map["Baro Bus Address 2"] = getBaroAddress2();
    map["VN200"] = getVN();
    map["Radio"] = getRadio();
    map["Aileron in"] = getAileronIn();
    map["Elevator in"] = getElevatorIn();
    map["Rudder in"] = getRudderIn();
    map["Throttle in"] = getThrottleIn();
    map["Flap in"] = getFlapIn();
    map["Aux in"] = getAuxIn();
    map["Mode in"] = getModeIn();
    map["Trigger in"] = getTriggerIn();
    map["Aileron out"] = getAileronOut();
    map["Elevator out"] = getElevatorOut();
    map["Rudder out"] = getRudderOut();
    map["Throttle out"] = getThrottleOut();
    map["Flap out"] = getFlapOut();
    map["Aux out"] = getAuxOut();
    map["Mode out"] = getModeOut();
    map["Trigger out"] = getTriggerOut();
}

QString configcreator::getValue(QString key){
    return map.value(key);
}

void configcreator::writeFile(QString s, QString v){
    if(loadedFile->exists()){
        bool n = loadedFile->open(QIODevice::ReadWrite);
        qDebug() << "Writing to: " + loadedFile->fileName();
        if(n){
            QString file;
            QString fileCopy;
            QTextStream stream(loadedFile);
            while(!stream.atEnd()){
                file = stream.readLine();
                if(file.contains(s)){
                    file = "\t" + s + " " + v;
                }
                    fileCopy.append(file + "\n");
            }
            loadedFile->resize(0);
            stream << fileCopy;
            loadedFile->flush();
            loadedFile->close();

        }else{
            //Failed to open
        }
    }else{
        //Does not exist
    }
}

QString configcreator::getSimulationMode(){
    return readFile("~SIMULATION_MODE");
}

QString configcreator::getHILMode(){
    return readFile("~HIL_MODE");
}

QString configcreator::getCommsMode(){
    return readFile("~GCS_COMMS_MODE");
}

QString configcreator::getDataLogging(){
    return readFile("~DATA_LOGGING");
}

QString configcreator::getVehicleId(){
    return readFile("~Airplane_ID");
}

QString configcreator::getStall(){
    return readFile("~V_STALL");
}

QString configcreator::getPhi(){
    return readFile("~LIMIT_PHI");
}

QString configcreator::getTheta(){
    return readFile("~LIMIT_THETA");
}

QString configcreator::getThrottle(){
    return readFile("~LIMIT_THROTTLE");
}

QString configcreator::getXP(){
    return readFile("~K_X_IL_P");
}

QString configcreator::getXI(){
    return readFile("~K_X_IL_I");
}

QString configcreator::getXD(){
    return readFile("~K_X_IL_D");
}

QString configcreator::getYP(){
    return readFile("~K_Y_IL_P");
}

QString configcreator::getYI(){
    return readFile("~K_Y_IL_I");
}

QString configcreator::getYD(){
    return readFile("~K_Y_IL_D");
}

QString configcreator::getZP(){
    return readFile("~K_Z_IL_P");
}

QString configcreator::getZI(){
    return readFile("~K_Z_IL_I");
}

QString configcreator::getZD(){
    return readFile("~K_Z_IL_D");
}

QString configcreator::getLattitudeP(){
    return readFile("~K_XY_OL_P");
}

QString configcreator::getLattitudeI(){
    return readFile("~K_XY_OL_I");
}

QString configcreator::getLattitudeD(){
    return readFile("~K_XY_OL_D");
}

QString configcreator::getLongitudeP(){
    return readFile("~K_H_OL_P");
}

QString configcreator::getLongitudeI(){
    return readFile("~K_H_OL_I");
}

QString configcreator::getLongitudeD(){
    return readFile("~K_H_OL_D");
}

QString configcreator::getThrottleP(){
    return readFile("~K_THROTTLE_P");
}

QString configcreator::getThrottleI(){
    return readFile("~K_THROTTLE_P");
}

QString configcreator::getThrottleD(){
    return readFile("~K_THROTTLE_P");
}

QString configcreator::getPath(){
    return readFile("~K_PATH");
}

QString configcreator::getInf(){
    return readFile("~X_INF");
}

QString configcreator::getOrbit(){
    return readFile("~K_ORBIT");
}

QString configcreator::getName(){
    QString s = QFileInfo(*loadedFile).baseName();
    return s;
}

//servos
QString configcreator::getServoLimitAll(){
    return readFile("~LIMIT_AIL");
}

QString configcreator::getServoLimitElev(){
    return readFile("~LIMIT_ELEV");
}

QString configcreator::getServoLimitRudder(){
    return readFile("~LIMIT_RUDDER");
}

QString configcreator::getSensorBus1(){
    return readFile("~pSensorBus1");
}

QString configcreator::getSensorBus2(){
    return readFile("~pSensorBus2");
}

QString configcreator::getSensorAddress1(){
    return readFile("~pSensorAddress1");
}

QString configcreator::getSensorAddress2(){
    return readFile("~pSensorAddress2");
}

QString configcreator::getBaroBus1(){
    return readFile("~baroBus1");
}

QString configcreator::getBaroBus2(){
    return readFile("~baroBus2");
}

QString configcreator::getBaroAddress1(){
    return readFile("~baroAddress1");
}

QString configcreator::getBaroAddress2(){
    return readFile("~baroAddress2");
}

QString configcreator::getVN(){
    return readFile("~VN200");
}

QString configcreator::getRadio(){
    return readFile("~RADIO");
}

//controller settings
QString configcreator::getAileronIn(){
    return readFile("~aileron_in");
}

QString configcreator::getElevatorIn(){
    return readFile("~elevator_in");
}

QString configcreator::getRudderIn(){
    return readFile("~rudder_in");
}

QString configcreator::getThrottleIn(){
    return readFile("~throttle_in");
}

QString configcreator::getFlapIn(){
    return readFile("~flap_in");
}

QString configcreator::getAuxIn(){
    return readFile("~aux1_in");
}

QString configcreator::getModeIn(){
    return readFile("~mode_in");
}

QString configcreator::getTriggerIn(){
    return readFile("~trigger_in");
}

QString configcreator::getAileronOut(){
    return readFile("~aileron_out");
}

QString configcreator::getElevatorOut(){
    return readFile("~elevator_out");
}

QString configcreator::getRudderOut(){
    return readFile("~rudder_out");
}

QString configcreator::getThrottleOut(){
    return readFile("~throttle_out");
}

QString configcreator::getFlapOut(){
    return readFile("~flap_out");
}

QString configcreator::getAuxOut(){
    return readFile("~aux1_out");
}

QString configcreator::getModeOut(){
    return readFile("~mode_out");
}

QString configcreator::getTriggerOut(){
    return readFile("~trigger_out");
}


//setters
void configcreator::setSimulationMode(QString v){
    map.insert("Simulation Mode", v);
    writeFile("~SIMULATION_MODE", v);
}

void configcreator::setHILMode(QString v){
    map.insert("HIL Mode", v);
    writeFile("~HIL_MODE", v);
}

void configcreator::setCommsMode(QString v){
    map.insert("Comms Mode", v);
    writeFile("~GCS_COMMS_MODE", v);
}

void configcreator::setDataLogging(QString v){
    map.insert("Data Logging", v);
    writeFile("~DATA_LOGGING", v);
}

void configcreator::setVehicleId(QString v){
    map.insert("Vehicle ID", v);
    writeFile("~Airplane_ID", v);
}

void configcreator::setStall(QString v){
    map.insert("Stall", v);
    writeFile("~V_STALL", v);
}

void configcreator::setPhi(QString v){
    map.insert("Phi", v);
    writeFile("~LIMIT_PHI", v);
}

void configcreator::setTheta(QString v){
    map.insert("Theta", v);
    writeFile("~LIMIT_THETA", v);
}

void configcreator::setThrottle(QString v){
    map.insert("Throttle", v);
    writeFile("~LIMIT_THROTTLE", v);
}

void configcreator::setXP(QString v){
    map.insert("XP", v);
    writeFile("~K_X_IL_P", v);
}

void configcreator::setXI(QString v){
    map.insert("XI", v);
    writeFile("~K_X_IL_I", v);
}

void configcreator::setXD(QString v){
    map.insert("XD", v);
    writeFile("~K_X_IL_D", v);
}

void configcreator::setYP(QString v){
    map.insert("YP", v);
    writeFile("~K_Y_IL_P", v);
}

void configcreator::setYI(QString v){
    map.insert("YI", v);
    writeFile("~K_Y_IL_I", v);
}

void configcreator::setYD(QString v){
    map.insert("YD", v);
    writeFile("~K_Y_IL_D", v);
}

void configcreator::setZP(QString v){
    map.insert("ZP", v);
    writeFile("~K_Z_IL_P", v);
}

void configcreator::setZI(QString v){
    map.insert("ZI", v);
    writeFile("~K_Z_IL_I", v);
}

void configcreator::setZD(QString v){
    map.insert("ZD", v);
    writeFile("~K_Z_IL_D", v);
}

void configcreator::setLattitudeX(QString v){
    map.insert("Lateral P", v);
    writeFile("~K_XY_OL_P", v);
}

void configcreator::setLattitudeY(QString v){
    map.insert("Lateral I", v);
    writeFile("~K_XY_OL_I", v);
}

void configcreator::setLattitudeZ(QString v){
    map.insert("Lateral D", v);
    writeFile("~K_XY_OL_D", v);
}

void configcreator::setLongitudeX(QString v){
    map.insert("Longitude P", v);
    writeFile("~K_H_OL_P", v);
}

void configcreator::setLongitudeY(QString v){
    map.insert("Longitude I", v);
    writeFile("~K_H_OL_I", v);
}

void configcreator::setLongitudeZ(QString v){
    map.insert("Longitude D", v);
    writeFile("~K_H_OL_D", v);
}

void configcreator::setThrottleX(QString v){
    map.insert("Throttle P", v);
    writeFile("~K_THROTTLE_P", v);
}

void configcreator::setThrottleY(QString v){
    map.insert("Throttle I", v);
    writeFile("~K_THROTTLE_I", v);
}

void configcreator::setThrottleZ(QString v){
    map.insert("Throttle D", v);
    writeFile("~K_THROTTLE_D", v);
}

void configcreator::setPath(QString v){
    map.insert("Path", v);
    writeFile("~K_PATH", v);
}

void configcreator::setInf(QString v){
    map.insert("Inf", v);
    writeFile("~X_INF", v);
}

void configcreator::setOrbit(QString v){
    map.insert("Orbit", v);
    writeFile("~K_ORBIT", v);
}

void configcreator::setName(QString v){
    loadedFile->rename("../Userdata/" + v + ".stb");
    map.insert("Name",v);
    QSettings settings("../Stabilis-GUI/Stabilis.ini", QSettings::IniFormat);
    settings.beginGroup("Vehicle");
    settings.setValue("load","../Userdata/" + v + ".stb");
    settings.endGroup();
}

//servos
void configcreator::setServoLimitAll(QString v){
    map.insert("Servo Limit ALL", v);
    writeFile("~LIMIT_AIL", v);
}

void configcreator::setServoLimitElev(QString v){
    map.insert("Servo Limit ELEV", v);
    writeFile("~LIMIT_ELEV", v);
}

void configcreator::setServoLimitRudder(QString v){
    map.insert("Servo Limit Rudder", v);
    writeFile("~LIMIT_RUDDER", v);
}

void configcreator::setSensorBus1(QString v){
    map.insert("Sensor Bus 1", v);
    writeFile("~pSensorBus1", v);
}

void configcreator::setSensorBus2(QString v){
    map.insert("Sensor Bus 2", v);
    writeFile("~pSensorBus2", v);
}

void configcreator::setSensorAddress1(QString v){
    map.insert("Sensor Bus Address 1", v);
    writeFile("~pSensorAddress1", v);
}

void configcreator::setSensorAddress2(QString v){
    map.insert("Sensor Bus Address 2", v);
    writeFile("~pSensorAddress2", v);
}

void configcreator::setBaroBus1(QString v){
    map.insert("Baro Bus 1", v);
    writeFile("~baroBus1", v);
}

void configcreator::setBaroBus2(QString v){
    map.insert("Baro Bus 2", v);
    writeFile("~baroBus2", v);
}

void configcreator::setBaroAddress1(QString v){
    map.insert("Baro Bus Address 1", v);
    writeFile("~baroAddress1", v);
}

void configcreator::setBaroAddress2(QString v){
    map.insert("Baro Bus Address 2", v);
    writeFile("~baroAddress2", v);
}

void configcreator::setVN(QString v){
    map.insert("VN200", v);
    writeFile("~VN200", v);
}

void configcreator::setRadio(QString v){
    map.insert("Radio", v);
    writeFile("~RADIO", v);
}

//controller settings
void configcreator::setAileronIn(QString v){
    map.insert("Aileron in", v);
    writeFile("~aileron_in", v);
}

void configcreator::setElevatorIn(QString v){
    map.insert("Elevator in", v);
    writeFile("~elevator_in", v);
}

void configcreator::setRudderIn(QString v){
    map.insert("Rudder in", v);
    writeFile("~rudder_in", v);
}

void configcreator::setThrottleIn(QString v){
    map.insert("Throttle in", v);
    writeFile("~throttle_in", v);
}

void configcreator::setFlapIn(QString v){
    map.insert("Flap in", v);
    writeFile("~flap_in", v);
}

void configcreator::setAuxIn(QString v){
    map.insert("Aux in", v);
    writeFile("~aux1_in", v);
}

void configcreator::setModeIn(QString v){
    map.insert("Mode in", v);
    writeFile("~mode_in", v);
}

void configcreator::setTriggerIn(QString v){
    map.insert("Trigger in", v);
    writeFile("~trigger_in", v);
}

void configcreator::setAileronOut(QString v){
    map.insert("Aileron out", v);
    writeFile("~aileron_out", v);
}

void configcreator::setElevatorOut(QString v){
    map.insert("Elevator out", v);
    writeFile("~elevator_out", v);
}

void configcreator::setRudderOut(QString v){
    map.insert("Rudder out", v);
    writeFile("~rudder_out", v);
}

void configcreator::setThrottleOut(QString v){
    map.insert("Throttle out", v);
    writeFile("~throttle_out", v);
}

void configcreator::setFlapOut(QString v){
    map.insert("Flap out", v);
    writeFile("~flap_out", v);
}

void configcreator::setAuxOut(QString v){
    map.insert("Aux out", v);
    writeFile("~aux1_out", v);
}

void configcreator::setModeOut(QString v){
    map.insert("Mode out", v);
    writeFile("~mode_out", v);
}

void configcreator::setTriggerOut(QString v){
    map.insert("Trigger out", v);
    writeFile("~trigger_out", v);
}



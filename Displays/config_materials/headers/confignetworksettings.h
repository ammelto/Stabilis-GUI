#ifndef CONFIGNETWORKSETTINGS_H
#define CONFIGNETWORKSETTINGS_H

#include <QWidget>
#include "./genericbutton.h"
#include "./configcreator.h"
#include "./inputfield.h"

namespace Ui {
class confignetworksettings;
}

class confignetworksettings : public QWidget
{
    Q_OBJECT

public:
    explicit confignetworksettings(QWidget *parent = 0, configcreator *config = 0);
    ~confignetworksettings();
    void setTheme(QColor p, QColor s, QColor f);

public slots:
    void connectButtonHandler();
    void returnCode(int code);

private:
    Ui::confignetworksettings *ui;
    inputField *addressField, *portField, *nameField, *passField;
    genericButton *connectButton;

signals:
    void startConnection(QString host, QString port, QString username, QString password);
};

#endif // CONFIGNETWORKSETTINGS_H

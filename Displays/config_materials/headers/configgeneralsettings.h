#ifndef CONFIGGENERALSETTINGS_H
#define CONFIGGENERALSETTINGS_H

#include <QWidget>

namespace Ui {
class configGeneralSettings;
}

class configGeneralSettings : public QWidget
{
    Q_OBJECT

public:
    explicit configGeneralSettings(QWidget *parent = 0);
    ~configGeneralSettings();


public slots:
    void toggleListener(int value);

private:
    Ui::configGeneralSettings *ui;
};

#endif // CONFIGGENERALSETTINGS_H

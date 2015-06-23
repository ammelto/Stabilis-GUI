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
    void setTheme(QColor p, QColor s, QColor f);
    explicit configGeneralSettings(QWidget *parent = 0);
    ~configGeneralSettings();


public slots:
    void toggleListener(int value);

private:
    QColor primary;
    QColor secondary;
    QColor font;
    Ui::configGeneralSettings *ui;
};

#endif // CONFIGGENERALSETTINGS_H

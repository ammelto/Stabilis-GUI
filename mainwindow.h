#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <QColor>
#include "./Displays/headers/homedisplay.h"
#include "./Displays/headers/docsdisplay.h"
#include "./Displays/headers/configdisplay.h"
#include "./Displays/headers/infodisplay.h"
#include "./Displays/headers/windowdisplay.h"
#include "sidemenu.h"
#include "titlebar.h"
#include <QRect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QColor getPrimaryColor();
    QColor getSecondaryColor();
    QColor getFontColor();
    ~MainWindow();

public slots:
     void setState(int state);
     void setDisplay(int display);
     void setTheme(QColor p,QColor s,QColor f);

private:
    enum states{close, maximize, minimize, windowed};
    enum display{home, console, config, docs, window, info};
    bool isMax = false;
    QRect savedGeometry;
    QColor primaryColor;
    QColor secondaryColor;
    QColor fontColor;
    homedisplay *homeDisplay;
    docsdisplay *docsDisplay;
    infodisplay *infoDisplay;
    configdisplay *configDisplay;
    windowdisplay *windowDisplay;
    sidemenu *sideMenu;
    titlebar *titleBar;
    int currentDisplay = 0;

    bool eventFilter(QObject *obj, QEvent *event);
    void resetDisplay();
    Ui::MainWindow *ui;
    QPoint dragPosition;

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <QColor>
#include "./Displays/homedisplay.h"
#include "./Displays/docsdisplay.h"
#include "./Displays/configdisplay.h"
#include "./Displays/consoledisplay.h"
#include "./Displays/infodisplay.h"
#include "./Displays/windowdisplay.h"
#include "sidemenu.h"
#include "titlebar.h"

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
    enum states{close, maximize, minimize};
    enum display{home, console, config, docs, window, info};
    QColor primaryColor;
    QColor secondaryColor;
    QColor fontColor;
    homedisplay *homeDisplay;
    docsdisplay *docsDisplay;
    infodisplay *infoDisplay;
    configdisplay *configDisplay;
    windowdisplay *windowDisplay;
    consoledisplay *consoleDisplay;
    sidemenu *sideMenu;
    titlebar *titleBar;

    bool eventFilter(QObject *obj, QEvent *event);
    void resetDisplay();
    Ui::MainWindow *ui;
    QPoint dragPosition;

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H

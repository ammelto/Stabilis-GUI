#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include "./Displays/homedisplay.h"
#include "./Displays/docsdisplay.h"
#include "./Displays/configdisplay.h"
#include "./Displays/consoledisplay.h"
#include "./Displays/infodisplay.h"
#include "./Displays/windowdisplay.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
     void setState(int state);
     void setDisplay(int display);

private:
    enum states{close, maximize, minimize};
    enum display{home, console, config, docs, window, info};
    homedisplay *homeDisplay;
    docsdisplay *docsDisplay;
    infodisplay *infoDisplay;
    configdisplay *configDisplay;
    windowdisplay *windowDisplay;
    consoledisplay *consoleDisplay;

    bool eventFilter(QObject *obj, QEvent *event);
    void resetDisplay();
    Ui::MainWindow *ui;
    QPoint dragPosition;

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H

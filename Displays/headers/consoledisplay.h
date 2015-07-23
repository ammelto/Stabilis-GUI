#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H
#include "../console_materials/headers/terminalwindow.h"

#include <QWidget>

namespace Ui {
class consoledisplay;
}

class consoledisplay : public QWidget
{
    Q_OBJECT

public:
    explicit consoledisplay(QWidget *parent = 0);
    ~consoledisplay();
    int connectConsole();
    void connectCallback(int status);
    int writeCommand();
    void writeCallback(int status);
    void readMessage();

private:
    Ui::consoledisplay *ui;
    TerminalWindow *terminal;

public slots:
    int connectConsole(QString host, QString port, QString username, QString password);
};

#endif // CONSOLEDISPLAY_H

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
    void writeCommandCallback(int status);
    void readMessage();
    int sendFile(char* local_src, char* remote_dest);
    int receiveFile(char* local_dest, char* remote_src);
    void sendFileCallback(int status);
    void receiveFileCallback(int status);

private:
    Ui::consoledisplay *ui;
    TerminalWindow *terminal;

public slots:
    int connectConsole(QString host, QString port, QString username, QString password);
    int writeCommand(QString command);

signals:
    void connectionWorked();

};

#endif // CONSOLEDISPLAY_H

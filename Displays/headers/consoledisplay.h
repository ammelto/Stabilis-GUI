#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H
#include "../console_materials/headers/terminalwindow.h"

struct remote_connection_data;

#include <QWidget>

namespace Ui {
class consoledisplay;
}

class consoledisplay : QObject
{
    Q_OBJECT

public:
    explicit consoledisplay(QWidget *parent = 0);
    ~consoledisplay();
    int connectConsole();


private:
    Ui::consoledisplay *ui;
    TerminalWindow *terminal;

public slots:
    int connectConsole(QString host, QString port, QString username, QString password);
    int writeCommand(QString command);
    int readMessage();
    int sendFile(QString filepath);
    int receiveFile();
    void sendFileCallback(int status,remote_connection_data* data);
    void receiveFileCallback(int status,remote_connection_data* data);
    void connectCallback(int status,remote_connection_data* data);
    void writeCommandCallback(int status,remote_connection_data* data);
    void readMessageCallback(int status, remote_connection_data* data);

signals:
    void connectionWorked(int);

};

//static const char* new_line = "\n";
static const char NEW_LINE_CHAR = ((char *)("\r"))[0];


#endif // CONSOLEDISPLAY_H

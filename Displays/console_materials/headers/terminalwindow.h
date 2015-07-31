#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H

#include <QWidget>
#include <QPlainTextEdit>

#define MAX_INPUT 5000
typedef enum options{TRANSFER_FILE, RECEIVE_FILE, DISCONNECT, NONE} option;
namespace Ui {
class TerminalWindow;
}

class TerminalWindow : public QPlainTextEdit
{
    Q_OBJECT

public:
    explicit TerminalWindow(QWidget *parent = 0);
    ~TerminalWindow();

private:
    Ui::TerminalWindow *ui;
    void putData(const QByteArray &data);
    void setLocalEchoEnabled(bool set);
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void contextMenuEvent(QContextMenuEvent *e);
    void sendCommand();
    void showPrevCommand(int line);
    void cycleOptions();
    void doOption(option opt);
public:
    bool localEchoEnabled;
    void updateTerminal(char* text);

signals:
    int writeCommand(QString command);

public slots:
    void writeOut(QString text);

private:
    char* input_buffer[MAX_INPUT];
    int cursor_stop_position = 1;
    int prev_command_length;
    option opt = NONE;
    QString transfer_file = "TRANSFER FILE";
    QString receive_file = "RECEIVE FILE";
    QString disconnect = "DISCONNECT";
    QString none = " ";
};



#endif // TERMINALWINDOW_H

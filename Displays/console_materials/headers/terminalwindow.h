#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H

#include <QWidget>
#include <QPlainTextEdit>

#define MAX_INPUT 5000

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
public:
    bool localEchoEnabled;

signals:
    void writeCommand(QString command);

public slots:
    void writeOut(QString text);

private:
    char* input_buffer[MAX_INPUT];

};



#endif // TERMINALWINDOW_H

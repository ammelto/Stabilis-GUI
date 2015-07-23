#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H

#include <QWidget>

namespace Ui {
class TerminalWindow;
}

class TerminalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalWindow(QWidget *parent = 0);
    ~TerminalWindow();

private:
    Ui::TerminalWindow *ui;
};

#endif // TERMINALWINDOW_H

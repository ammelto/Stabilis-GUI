#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QMenuBar>

namespace Ui {
class titlebar;
}

class titlebar : public QWidget
{
    Q_OBJECT

public:
    explicit titlebar(QWidget *parent = 0);
    ~titlebar();

private:
    enum states{close, maximize, minimize};

    Ui::titlebar *ui;
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void stateChange(int);
};

#endif // TITLEBAR_H

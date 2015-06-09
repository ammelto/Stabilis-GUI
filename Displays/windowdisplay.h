#ifndef WINDOWDISPLAY_H
#define WINDOWDISPLAY_H

#include <QWidget>

namespace Ui {
class windowdisplay;
}

class windowdisplay : public QWidget
{
    Q_OBJECT

public:
    explicit windowdisplay(QWidget *parent = 0);
    ~windowdisplay();

private:
    Ui::windowdisplay *ui;
};

#endif // WINDOWDISPLAY_H

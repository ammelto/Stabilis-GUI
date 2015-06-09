#ifndef CONFIGDISPLAY_H
#define CONFIGDISPLAY_H

#include <QWidget>

namespace Ui {
class configdisplay;
}

class configdisplay : public QWidget
{
    Q_OBJECT

public:
    explicit configdisplay(QWidget *parent = 0);
    ~configdisplay();

private:
    Ui::configdisplay *ui;
};

#endif // CONFIGDISPLAY_H

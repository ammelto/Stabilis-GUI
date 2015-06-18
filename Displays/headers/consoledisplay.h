#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

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

private:
    Ui::consoledisplay *ui;
};

#endif // CONSOLEDISPLAY_H

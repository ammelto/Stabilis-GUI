#ifndef HOMEDISPLAY_H
#define HOMEDISPLAY_H

#include <QWidget>

namespace Ui {
class homedisplay;
}

class homedisplay : public QWidget
{
    Q_OBJECT

public:
    explicit homedisplay(QWidget *parent = 0);
    ~homedisplay();

private:
    Ui::homedisplay *ui;
};

#endif // HOMEDISPLAY_H

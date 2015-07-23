#ifndef INFODISPLAY_H
#define INFODISPLAY_H

#include <QWidget>

namespace Ui {
class infodisplay;
}

class infodisplay : public QWidget
{
    Q_OBJECT

public:
    explicit infodisplay(QWidget *parent = 0);
    ~infodisplay();

private:
    Ui::infodisplay *ui;
};

#endif // INFODISPLAY_H

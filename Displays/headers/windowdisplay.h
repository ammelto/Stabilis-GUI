#ifndef WINDOWDISPLAY_H
#define WINDOWDISPLAY_H

#include <QWidget>
#include <QColor>

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

signals:
    void setTheme(QColor, QColor, QColor);
};


#endif // WINDOWDISPLAY_H

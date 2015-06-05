#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QWidget>
#include <QFontDatabase>
#include <QGraphicsEffect>

namespace Ui {
class sidemenu;
}

class sidemenu : public QWidget
{
    Q_OBJECT

public:
    explicit sidemenu(QWidget *parent = 0);
    ~sidemenu();

private:
    enum display{home, console, config};
    int currentDisplay;
    QPalette pal;
    QGraphicsDropShadowEffect* enabledShadow;
    QGraphicsDropShadowEffect* homeShadow;
    QGraphicsDropShadowEffect* consoleShadow;
    QGraphicsDropShadowEffect* configShadow;

    Ui::sidemenu *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    void resetButtons();
};

#endif // SIDEMENU_H

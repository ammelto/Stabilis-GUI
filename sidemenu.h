#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QWidget>
#include <QFontDatabase>
#include <QGraphicsEffect>
#include <QPixmap>

namespace Ui {
class sidemenu;
}

class sidemenu : public QWidget
{
    Q_OBJECT

public:
    explicit sidemenu(QWidget *parent = 0);
    void setTheme(QColor p,QColor s,QColor f);
    ~sidemenu();

private:
    enum display{home, console, config, docs, window, info};
    int currentDisplay = 0;
    QPalette pal;
    QColor primaryColor;
    QColor secondaryColor;
    QColor fontColor;
    QPixmap homeIconSource;
    QPixmap consoleIconSource;
    QPixmap docsIconSource;
    QPixmap configIconSource;
    QPixmap windowIconSource;
    QPixmap infoIconSource;

    Ui::sidemenu *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    void repaint();
    void repaintIcons();

signals:
    void setDisplay(int);
};

#endif // SIDEMENU_H

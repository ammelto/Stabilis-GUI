#ifndef GENERICBUTTON_H
#define GENERICBUTTON_H

#include <QWidget>

namespace Ui {
class genericButton;
}

class genericButton : public QWidget
{
    Q_OBJECT

public:
    explicit genericButton(QWidget *parent = 0);
    void setButtonText(QString s);
    void setLocation(QRect r);
    void setTheme(QColor p, QColor s, QColor f);
    ~genericButton();

private:
    QColor primary;
    QColor secondary;
    QColor font;

    bool eventFilter(QObject *obj, QEvent *event);
    Ui::genericButton *ui;

signals:
    void pressed();
};

#endif // GENERICBUTTON_H

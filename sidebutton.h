#ifndef SIDEBUTTON_H
#define SIDEBUTTON_H

#include <QWidget>

namespace Ui {
class sidebutton;
}

class sidebutton : public QWidget
{
    Q_OBJECT

public:
    explicit sidebutton(QWidget *parent = 0);
    ~sidebutton();

private:
    Ui::sidebutton *ui;
};

#endif // SIDEBUTTON_H

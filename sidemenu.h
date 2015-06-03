#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QWidget>
#include <QFontDatabase>


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
    Ui::sidemenu *ui;
};

#endif // SIDEMENU_H

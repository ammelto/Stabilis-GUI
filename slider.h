#ifndef SLIDER_H
#define SLIDER_H

#include <QWidget>

namespace Ui {
class slider;
}

class slider : public QWidget
{
    Q_OBJECT

public:
    explicit slider(QWidget *parent = 0);
    ~slider();

private:
    Ui::slider *ui;
};

#endif // SLIDER_H

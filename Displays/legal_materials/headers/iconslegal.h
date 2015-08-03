#ifndef ICONSLEGAL_H
#define ICONSLEGAL_H

#include <QWidget>

namespace Ui {
class iconsLegal;
}

class iconsLegal : public QWidget
{
    Q_OBJECT

public:
    explicit iconsLegal(QWidget *parent = 0);
    ~iconsLegal();

private:
    Ui::iconsLegal *ui;
};

#endif // ICONSLEGAL_H

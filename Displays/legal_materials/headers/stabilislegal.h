#ifndef STABILISLEGAL_H
#define STABILISLEGAL_H

#include <QWidget>

namespace Ui {
class stabilisLegal;
}

class stabilisLegal : public QWidget
{
    Q_OBJECT

public:
    explicit stabilisLegal(QWidget *parent = 0);
    ~stabilisLegal();

private:
    Ui::stabilisLegal *ui;
};

#endif // STABILISLEGAL_H

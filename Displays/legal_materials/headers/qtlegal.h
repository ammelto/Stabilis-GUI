#ifndef QTLEGAL_H
#define QTLEGAL_H

#include <QWidget>

namespace Ui {
class qtLegal;
}

class qtLegal : public QWidget
{
    Q_OBJECT

public:
    explicit qtLegal(QWidget *parent = 0);
    ~qtLegal();

private:
    Ui::qtLegal *ui;
};

#endif // QTLEGAL_H

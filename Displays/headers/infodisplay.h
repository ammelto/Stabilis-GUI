#ifndef INFODISPLAY_H
#define INFODISPLAY_H

#include <QWidget>
#include "../legal_materials/headers/qtlegal.h"
#include "../legal_materials/headers/iconslegal.h"
#include "../legal_materials/headers/stabilislegal.h"

namespace Ui {
class infodisplay;
}

class infodisplay : public QWidget
{
    Q_OBJECT

public:
    explicit infodisplay(QWidget *parent = 0);
    ~infodisplay();

private:
    Ui::infodisplay *ui;
    iconsLegal *iLegal;
    stabilisLegal *sLegal;
    qtLegal *qLegal;
};

#endif // INFODISPLAY_H

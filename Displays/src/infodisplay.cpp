#include "../headers/infodisplay.h"
#include "ui_infodisplay.h"

infodisplay::infodisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infodisplay)
{
    ui->setupUi(this);

    iLegal = new iconsLegal(ui->iconsLegal);
    qLegal = new qtLegal(ui->qtLegal);
    sLegal = new stabilisLegal(ui->stabilisLegal);

}

infodisplay::~infodisplay()
{
    delete ui;
}

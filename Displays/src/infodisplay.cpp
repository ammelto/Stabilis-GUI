#include "../headers/infodisplay.h"
#include "ui_infodisplay.h"

infodisplay::infodisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infodisplay)
{
    ui->setupUi(this);
}

infodisplay::~infodisplay()
{
    delete ui;
}

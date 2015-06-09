#include "configdisplay.h"
#include "ui_configdisplay.h"

configdisplay::configdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configdisplay)
{
    ui->setupUi(this);
}

configdisplay::~configdisplay()
{
    delete ui;
}

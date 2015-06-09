#include "homedisplay.h"
#include "ui_homedisplay.h"

homedisplay::homedisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homedisplay)
{
    ui->setupUi(this);


}

homedisplay::~homedisplay()
{
    delete ui;
}

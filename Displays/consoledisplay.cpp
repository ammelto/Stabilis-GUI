#include "consoledisplay.h"
#include "ui_consoledisplay.h"

consoledisplay::consoledisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::consoledisplay)
{
    ui->setupUi(this);


}

consoledisplay::~consoledisplay()
{
    delete ui;
}

#include "sidebutton.h"
#include "ui_sidebutton.h"

sidebutton::sidebutton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sidebutton)
{
    ui->setupUi(this);


    QPalette pal = this->palette();
    pal.setColor(this->backgroundRole(), QColor(108,147,233));
    this->setPalette(pal);
    this->setAutoFillBackground(true);


}

sidebutton::~sidebutton()
{
    delete ui;
}

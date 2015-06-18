#include "../headers/windowdisplay.h"
#include "ui_windowdisplay.h"

windowdisplay::windowdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windowdisplay)
{
    ui->setupUi(this);
}

windowdisplay::~windowdisplay()
{
    delete ui;
}

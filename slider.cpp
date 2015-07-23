#include "slider.h"
#include "ui_slider.h"

slider::slider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::slider)
{
    ui->setupUi(this);
}

slider::~slider()
{
    delete ui;
}

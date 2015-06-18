#include "../headers/docsdisplay.h"
#include "ui_docsdisplay.h"

docsdisplay::docsdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::docsdisplay)
{
    ui->setupUi(this);
}

docsdisplay::~docsdisplay()
{
    delete ui;
}

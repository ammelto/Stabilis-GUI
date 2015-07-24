#include "../headers/docsdisplay.h"
#include "ui_docsdisplay.h"

docsdisplay::docsdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::docsdisplay)
{
    ui->setupUi(this);

    nav = new DocsNavMenu(ui->navWindow);
    content = new DocsContentWindow(ui->mainPage);
}

docsdisplay::~docsdisplay()
{
    delete ui;
}

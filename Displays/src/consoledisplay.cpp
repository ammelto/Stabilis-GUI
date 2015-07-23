#include "../headers/consoledisplay.h"
#include "ui_consoledisplay.h"

consoledisplay::consoledisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::consoledisplay)
{
    ui->setupUi(this);

    terminal = new TerminalWindow(ui->console);

}

consoledisplay::~consoledisplay()
{
    delete ui;
}

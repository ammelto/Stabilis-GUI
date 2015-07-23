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


/*
 *openConsole
 *
 *opens a new thread to run console interface
 * and attempts to connect to the given target
 *
 * */
void consoledisplay::connectConsole(){



}


/*
 *connectCallback
 *
 *callback after attempt to connect to target
 *
 * */
void consoledisplay::connectCallback(int status){




}

/*
 * writeCommand
 *
 * writes commands to the remote target
 *
 * OR
 *
 * writes commands to console, such as file transfer, close console, etc.
 *
 *
 * */
void consoledisplay::writeCommand(){


}


/*
 * writeCallback
 *
 *call back after an attempt to write a command to the target
 *
 * */
void consoledisplay::writeCallback(int status){


}


/*
 *readMessage
 *
 * ASYNC call back from console back end,
 *which waits until the target sends back a message
 *that we read in from this function
 *
 *
 * */
void consoledisplay::readMessage(){

}

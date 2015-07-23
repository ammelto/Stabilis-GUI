#include "../headers/consoledisplay.h"
#include "ui_consoledisplay.h"
#include "console.h"


console_thread* con_thread;

consoledisplay::consoledisplay(QWidget* parent) :
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
int consoledisplay::connectConsole(QString host, QString port, QString username, QString password){

    remote_connection_data* data;

    if(host == NULL || port == NULL || username == NULL || password == NULL){
        return -1;
    }

    data = new remote_connection_data();

    con_thread = new console_thread(this, data);
    con_thread->start();


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
int consoledisplay::writeCommand(){


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

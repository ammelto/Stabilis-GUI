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

    //connect(this, SIGNAL(writeOut(QString text)), terminal, SLOT(writeOut(QString text)));
    connect(terminal, SIGNAL(writeCommand(QString)), this, SLOT(writeCommand(QString)));
    //connect(terminal, SIGNAL(sendFi(QString command)), this, SLOT(writeCommand()));
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
        //return -1;
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
void consoledisplay::connectCallback(int status,remote_connection_data* data){

    if(status == -1){
        delete(con_thread);
        con_thread = NULL;
    }
    connectionWorked(status);

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
int consoledisplay::writeCommand(QString command){
    printf("entering write command\n");
    if(con_thread == NULL){
        printf("error: no connection\n");
        return -1;
    }

    if(con_thread->data->instruction_flags & WRITE_COMMAND){
        printf("error: console thread is busy\n");
        return -2;
    }

    QByteArray ba = command.toLatin1();
    char *res = ba.data();
    printf("string is %s\n", res);
    size_t len = strlen(res);
    printf("Command is %d characters long\n", len);
    if(len > BUFSIZ-10){
        printf("error: command is too long.\n");
        return -3;
    }

    //the order of setting flag and filling buffer matters for sync reasons.
    //if we set the flag first, the console thread might write whatever was previously in the buffer
    memcpy(con_thread->data->command,res, len);
    con_thread->data->command[len] = 0;

    con_thread->data->instruction_flags |= WRITE_COMMAND;
    printf("writing command\n");
    return 0;
}


/*
 * writeCallback
 *
 *call back after an attempt to write a command to the target
 *
 * */
void consoledisplay::writeCommandCallback(int status,remote_connection_data* data){
    //if(status == 0)
        data->instruction_flags &= ~WRITE_COMMAND;

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
void consoledisplay::readMessage(int status,remote_connection_data* data){
    //if(status == 0){
        terminal->updateTerminal(data->inputbuf);
   // }

}

int consoledisplay::sendFile(char* local_src, char* remote_dest){
    if(con_thread == NULL){
        return -1;
    }

    return 0;
}

void consoledisplay::sendFileCallback(int status,remote_connection_data* data){

}

int consoledisplay::receiveFile(char* local_dest, char* remote_src){
    if(con_thread == NULL){
        return -1;
    }

    return 0;
}

void consoledisplay::receiveFileCallback(int status,remote_connection_data* data){

}



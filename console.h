#include <qthread.h>
#include "Displays/headers/consoledisplay.h"
#include <libssh2_config.h>
#include <libssh2.h>
#include <libssh2_sftp.h>
#ifndef CONSOLE_H
#define CONSOLE_H

#endif // CONSOLE_H


#define BUFSIZ 10000
#define EXIT_COMMAND	"exit\n"
#define SEND_FILE (1<<0)
#define RECEIVE_FILE (1<<1)
#define WRITE_COMMAND (1<<2)
#define READ_COMMAND (1<<3)
#define TERMINATE (1<<4)



/*
 *This structure allows us to communicate with the
 *shell thread that continuously reads and writes.
 *We don't want to create a new thread for each ssh read/write.
 *
 * */
typedef struct remote_connection_data{
    const char *hostaddr = "192.168.7.2";
    const char *commandline = "uptime";
    const char *username    = "root";
    const char *password    = "root";
    LIBSSH2_SESSION *session;
    LIBSSH2_CHANNEL *channel;
    int sock;
    char command[BUFSIZ];
    char inputbuf[BUFSIZ];
    char* local_path;
    char* remote_path;
    char instruction_flags;

} remote_connection, p_remote_connection;

class console_thread : public QThread{
    Q_OBJECT
public:
    console_thread(consoledisplay* console_control, remote_connection_data* data);
    remote_connection_data* data;
protected:
    void run();

private:
    consoledisplay* console_control;
    int begin_console_thread(remote_connection_data* data);
    int run_shell(remote_connection_data* data);

signals:
    void sendFileCallback(int ,remote_connection_data* );
    void receiveFileCallback(int ,remote_connection_data* );
    void connectCallback(int ,remote_connection_data* );
    void writeCommandCallback(int ,remote_connection_data* );
    void readMessage(int , remote_connection_data* );
};

static int clean_up(remote_connection_data* data);
static int write_command(remote_connection_data* data);
static int read_remote(remote_connection_data* data);
static int receive_file(remote_connection_data* data);
static int send_file(remote_connection_data* data);
static int open_console(remote_connection_data* data);

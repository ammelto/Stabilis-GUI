#include <qthread.h>
#include "Displays/headers/consoledisplay.h"
#include <libssh2_config.h>
#include <libssh2.h>
#include <libssh2_sftp.h>
#ifndef CONSOLE_H
#define CONSOLE_H

#endif // CONSOLE_H

int open_console(void);
#define BUFSIZ 10000
#define EXIT_COMMAND	"exit\n"
#define WRITE_FILE (1<<0)
#define READ_FILE (1<<1)
#define WRITE_COMMAND (1<<2)
#define READ_COMMAND (1<<3)
#define TERMINATE (1<<4)


int receive_file(char* remote_src, char* dest);
int send_file(char* src, char* remote_dest);
int run_shell();


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
    char command[BUFSIZ];
    char inputbuf[BUFSIZ];
    char* local_path;
    char* remote_path;
    char instruction_flags;

} remote_connection, p_remote_connection;

class console_thread : public QThread{
public:
    console_thread(consoledisplay* console_control, remote_connection_data* data);
protected:
    void run();

private:
    remote_connection_data* data;
    consoledisplay* console_control;
};
static void begin_console_thread();
static void run_loop();
static void clean_up();

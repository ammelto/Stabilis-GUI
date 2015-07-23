/*
 * TODO:abstract these ssh functions into platform independent calls.
 *include platform specific headers which link to platform specific definitions *
 *
 * */

#include "console.h"

#ifdef HAVE_WINSOCK2_H
#include <windows.h>
# include <winsock2.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#ifdef HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif
#ifdef HAVE_SYS_SELECT_H
# include <sys/select.h>
#endif
# ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_ARPA_INET_H
# include <arpa/inet.h>
#endif
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#include <sys/types.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>


/*
 * One thread should be designed to handle multiple connections?
 * For now it can only handle one.
 *
 * */
console_thread::console_thread(consoledisplay* console_control, remote_connection_data* data){
    this->data = data;
    this->console_control = console_control;
}


/*
 *The console thread will be created on connection and will run
 *until connection fails or the user elects to terminate the connection
 *
 *
 * */
void console_thread::run(){
    begin_console_thread(this->data);
    clean_up(this->data);
    return;
}

static void begin_console_thread(remote_connection_data* data){
    err = open_console(data);
    console_control->connectCallback(err);
    if(err){
        return;
    }
    run_loop(data);
}

/*
 *This function runs continuously as a reader/writer
 *and receives commands from a global struct.
 *
 *The global struct can also signal this function to return / clean up
 *
 * */
static void run_shell(remote_connection_data* data){
    int err = 0;

    while(1){
        // procedure is check termination flag, write command-wait-read remote, write file, read file
        if(data->instruction_flags & TERMINATE){
            break;
        }
        if(data->instruction_flags & WRITE_COMMAND){

        }
        if(data->instruction_flags & READ_COMMAND){

        }
        if(data->instruction_flags & WRITE_FILE){

        }
        if(data->instruction_flags & READ_FILE){

        }

    }

}

static void clean_up(remote_connection_data* data){


}


int open_console(remote_connection_data* data) {

    const char *hostaddr = "192.168.7.2";
    const char *commandline = "uptime";
    const char *username    = "root";
    const char *password    = "root";
    /* Variables to don't touch */
    int rc;
    int sock;
    int err;
    struct sockaddr_in sin;
    LIBSSH2_SESSION *session;
    LIBSSH2_CHANNEL *channel;
    char command[BUFSIZ];
    char inputbuf[BUFSIZ];
    WSADATA wsaData;
    WORD wVersionRequested;

    wVersionRequested = MAKEWORD(2,2);

    /* Libss2 init block */
    rc = libssh2_init(0);
    if (rc) {
        fprintf(stderr, "Error: libssh_init()\n");
        return (EXIT_FAILURE);
    }
    err = WSAStartup(wVersionRequested, &wsaData);
        if (err != 0) {
            /* Tell the user that we could not find a usable */
            /* Winsock DLL.                                  */
            printf("WSAStartup failed with error: %d\n", err);
            return 1;
        }
    /* Creating socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        sock = WSAGetLastError();
        perror("socket");
        return (EXIT_FAILURE);
    }
    /* Connect this socket to remote side */
    sin.sin_family = AF_INET;
    sin.sin_port = htons(22);
    sin.sin_addr.s_addr = inet_addr(hostaddr);
    if (connect(sock, (struct sockaddr*)(&sin),
                sizeof(struct sockaddr_in)) != 0) {
        fprintf(stderr, "Failed to connect\n");
        return (EXIT_FAILURE);
    }

    /* Create a session instance and start it up. This will trade welcome
     * banners, exchange keys, and setup crypto, compression, and MAC layers */
    session = libssh2_session_init();
    if (!session) {
        fprintf(stderr, "SSH init failed\n");
        return (EXIT_FAILURE);
    }

    /* Handshake for session */
    rc = libssh2_session_handshake(session, sock);
    if (rc) {
        fprintf(stderr, "SSH handshake failed\n");
        return (EXIT_FAILURE);
    }

    /* Lets authenticate */
    rc = libssh2_userauth_password(session, username, password);
    if (rc) {
        printf("Authentication by password failed\n");
        return (EXIT_FAILURE);
    } else {
        printf("Authentication by password succeeded\n");
    }

    /* Request a shell */
    channel = libssh2_channel_open_session(session);
    if (!channel) {
        fprintf(stderr, "Unable to open a session\n");
        return (EXIT_FAILURE);
    }

    /* Request a terminal with 'vanilla' terminal emulation */
    rc = libssh2_channel_request_pty(channel, "vanilla");
    if (rc) {
        fprintf(stderr, "Failed requesting pty\n");
        return (EXIT_FAILURE);
    }

    /* Open a SHELL on that pty */
    rc = libssh2_channel_shell(channel);
    if (rc) {
        fprintf(stderr, "Unable to request shell on allocated pty\n");
        return (EXIT_FAILURE);
    }

    /* Main loop starts here.
     * In it you will be requested to input a command
     * command will be executed at remote side
     * an you will get output from it */
    /*
     rc = libssh2_channel_write(channel, "\n", strlen("\n"));
    do{

    rc = libssh2_channel_read(channel, inputbuf, BUFSIZ);
    libssh2_channel_flush_ex(channel, LIBSSH2_CHANNEL_FLUSH_ALL);
    printf("Remote side output:\n %s\n", inputbuf);
    }
    while(strstr(inputbuf, "root@") == NULL);
    printf("Remote side output:\n %s\n", inputbuf);*/
libssh2_channel_set_blocking(channel, 0);
    do {
        /* Request for command input */
        printf("$ ");
        fgets(command, BUFSIZ, stdin);
        printf("Command is %s", command);
        if (strcmp(command, "\n") == 0) {
            printf("Empty command\n");
            continue;
        }
        //libssh2_channel_flush_ex(channel, LIBSSH2_CHANNEL_FLUSH_ALL);
        /* Write command to stdin of remote shell */
        rc = libssh2_channel_write(channel, command, strlen(command));
        //printf("Channel write return value is %d\n", rc);

        /* Read output from remote side */
usleep(200000);
       libssh2_channel_read(channel, inputbuf, BUFSIZ);
            printf("Remote side output:\n %s\n", inputbuf);
    } while (strcmp(command, EXIT_COMMAND) != 0);
    /* Main loop ends here */

    /* De-init and pre-exit actions */
    if (channel) {
        libssh2_channel_free(channel);
        channel = NULL;
    }

    rc = libssh2_session_disconnect(session, "Normal Shutdown");
    if (rc) {
        fprintf(stderr, "Session disconnect error\n");
        return (EXIT_FAILURE);
    } else
        printf("Session finished successful\n");

    libssh2_session_free(session);

    close(sock);

    libssh2_exit();

    return (EXIT_SUCCESS);
}


int run_shell(){

    do {
        /* Request for command input */
        printf("$ ");
        fgets(command, BUFSIZ, stdin);
        printf("Command is %s", command);
        if (strcmp(command, "\n") == 0) {
            printf("Empty command\n");
            continue;
        }
        //libssh2_channel_flush_ex(channel, LIBSSH2_CHANNEL_FLUSH_ALL);
        /* Write command to stdin of remote shell */
        rc = libssh2_channel_write(channel, command, strlen(command));
        //printf("Channel write return value is %d\n", rc);

        /* Read output from remote side */
usleep(200000);
       libssh2_channel_read(channel, inputbuf, BUFSIZ);
            printf("Remote side output:\n %s\n", inputbuf);
    } while (strcmp(command, EXIT_COMMAND) != 0);
    /* Main loop ends here */



return 0;

}


/*
 *This function attempts to write a file to a remote file
 *
 *
 * */
int send_file(char* src, char* remote_dest){


return 0;
}

int receive_file(char* remote_src, char* dest){

}


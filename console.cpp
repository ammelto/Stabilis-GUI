/*
 * TODO:abstract these ssh functions into platform independent calls.
 *include platform specific headers which link to platform specific definitions *
 *
 * */

#include "console.h"

#include <libssh2_config.h>
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
    //this constructor runs from the GUI thread

    this->console_control = console_control;

    /*
     *SIGNAL/SLOT cross thread magic allows us to get to GUI safe code *from* this thread.
     *Basically, the SLOT functions get put in a queue when SIGNALed, and they get run when the GUI thread does its refresh loop.
     *
     * */
    connect(this, SIGNAL(readMessageCallback(int,remote_connection_data*)), console_control, SLOT(readMessageCallback(int,remote_connection_data*)));
    connect(this, SIGNAL(writeCommandCallback(int,remote_connection_data*)), console_control, SLOT(writeCommandCallback(int,remote_connection_data*)));
    connect(this, SIGNAL(sendFileCallback(int,remote_connection_data*)), console_control, SLOT(sendFileCallback(int,remote_connection_data*)));
    connect(this, SIGNAL(receiveFileCallback(int,remote_connection_data*)), console_control, SLOT(receiveFileCallback(int,remote_connection_data*)));
    connect(this, SIGNAL(connectCallback(int,remote_connection_data*)), console_control, SLOT(connectCallback(int,remote_connection_data*)));

    this->data = data;
}


/*
 *The console thread will be created on connection and will run
 *until connection fails or the user elects to terminate the connection *
 *
 * */
void console_thread::run(){
    //thread begin
    while(data == NULL);//waiting for constructor to finish
    int err;
    err = begin_console_thread(this->data);
    err = clean_up(this->data);
    return;
}

int console_thread::begin_console_thread(remote_connection_data* data){
    int err;

    err = open_console(data);
    connectCallback(err, data);
    if(err){
        //return err;
    }
    //this one loops
    err = run_shell(data);

    return err;
}

/*
 *This function runs continuously as a reader/writer
 *and receives commands from a global struct.
 *
 *The global struct can also signal this function to return / clean up
 *
 *This loop never clears flags. Flags should be cleared in the call back handlers
 *
 * */
int console_thread::run_shell(remote_connection_data* data){
    int err = 0;

    while(1){
        // procedure is check termination flag, write command-wait-read remote, write file, read file
        if(data->instruction_flags & TERMINATE){
            break;
        }
        if(data->instruction_flags & WRITE_COMMAND){
            err = write_command(data);
            writeCommandCallback(err, data);
            //if(!err){
                /* Read output from remote side */
                usleep(200000);
                err = read_remote(data);
                readMessageCallback(err, data);
           // }
        }
        if(data->instruction_flags & READ_COMMAND){
            err = read_remote(data);
            readMessageCallback(err, data);
        }
        if(data->instruction_flags & SEND_FILE){
            err = send_file(data);
            sendFileCallback(err, data);
        }
        if(data->instruction_flags & RECEIVE_FILE){
            receiveFileCallback(err, data);
        }

    }

}

static int clean_up(remote_connection_data* data){
    int rc;

    /* De-init and pre-exit actions */
    if (data->channel) {
        libssh2_channel_free(data->channel);
        data->channel = NULL;
    }

    rc = libssh2_session_disconnect(data->session, "Normal Shutdown");
    if (rc) {
        fprintf(stderr, "Session disconnect error\n");
        return (EXIT_FAILURE);
    } else
        printf("Session finished successful\n");

    libssh2_session_free(data->session);

    close(data->sock);

    libssh2_exit();

}


static int open_console(remote_connection_data* data) {

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
#ifdef WIN32
    WSADATA wsadata;
    int err;

    err = WSAStartup(MAKEWORD(2,0), &wsadata);
    if (err != 0) {
        fprintf(stderr, "WSAStartup failed with error: %d\n", err);
        return 1;
    }
#endif
    /* Libss2 init block */
    rc = libssh2_init(0);
    if (rc) {
        fprintf(stderr, "Error: libssh_init()\n");
        return (EXIT_FAILURE);
    }

    /* Creating socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){//INVALID_SOCKET) {
        //sock = WSAGetLastError();
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
    data->sock = sock;
    data->channel = channel;
    data->session = session;

    return (EXIT_SUCCESS);
}


static int write_command(remote_connection_data* data){
    int rc;

    printf("Command is %s\n", data->command);
    if (strcmp(data->command, "\n") == 0) {
        printf("Empty command\n");
        return -1;
    }
    /* Write command to stdin of remote shell */
    rc = libssh2_channel_write(data->channel, data->command, strlen(data->command));
    printf("Channel write return value is %d\n", rc);

    return rc;

}

static int read_remote(remote_connection_data* data){

    int rc;
    //libssh2 strangely returns the number of bytes read OR an error (negative value)
    rc = libssh2_channel_read(data->channel, data->inputbuf, BUFSIZ);

    if(rc > 0){
        data->inputbuf[rc] = 0;//string termination
        printf("Remote side output:\n %s\n", data->inputbuf);
        return 0;
    }
    else
        return rc;
}

/*
 *This function attempts to write a file to a remote file
 *
 *
 * */
static int send_file(remote_connection_data* data){

    int sock, i, auth_pw = 1;
            struct sockaddr_in sin;
            const char *fingerprint;
            LIBSSH2_SESSION *session;
            const char *hostaddr = "192.168.7.2";
            const char *username="root";
            const char *password="root";
            const char *loclfile=data->local_path;//"/home/nolander/Desktop/UC_UAS_STUDIO.setup.sh";
            const char *sftppath=data->remote_path;//"/tmp/adfsdf";
            int rc;
            FILE *local;
            LIBSSH2_SFTP *sftp_session;
            LIBSSH2_SFTP_HANDLE *sftp_handle;
            char mem[1024*100];
            size_t nread;
            char *ptr;

        #ifdef WIN32
            WSADATA wsadata;
            int err;

            err = WSAStartup(MAKEWORD(2,0), &wsadata);
            if (err != 0) {
                fprintf(stderr, "WSAStartup failed with error: %d\n", err);
                return 1;
            }
        #endif


            rc = libssh2_init (0);
            if (rc != 0) {
                fprintf (stderr, "libssh2 initialization failed (%d)\n", rc);
                return 1;
            }

            local = fopen(loclfile, "rb");
            if (!local) {
                fprintf(stderr, "Can't open local file %s\n", loclfile);
                return -1;
            }

            /*
             * The application code is responsible for creating the socket
             * and establishing the connection
             */
            sock = socket(AF_INET, SOCK_STREAM, 0);

            sin.sin_family = AF_INET;
            sin.sin_port = htons(22);
            sin.sin_addr.s_addr = inet_addr(hostaddr);
            if (connect(sock, (struct sockaddr*)(&sin),
                    sizeof(struct sockaddr_in)) != 0) {
                fprintf(stderr, "failed to connect!\n");
                return -1;
            }

            /* Create a session instance
             */
            session = libssh2_session_init();
            if(!session)
                return -1;

            /* Since we have set non-blocking, tell libssh2 we are blocking */
            libssh2_session_set_blocking(session, 1);

            /* ... start it up. This will trade welcome banners, exchange keys,
             * and setup crypto, compression, and MAC layers
             */
            rc = libssh2_session_handshake(session, sock);
            if(rc) {
                fprintf(stderr, "Failure establishing SSH session: %d\n", rc);
                return -1;
            }

            /* At this point we havn't yet authenticated.  The first thing to do
             * is check the hostkey's fingerprint against our known hosts Your app
             * may have it hard coded, may go to a file, may present it to the
             * user, that's your call
             */
            fingerprint = libssh2_hostkey_hash(session, LIBSSH2_HOSTKEY_HASH_SHA1);
            fprintf(stderr, "Fingerprint: ");
            for(i = 0; i < 20; i++) {
                fprintf(stderr, "%02X ", (unsigned char)fingerprint[i]);
            }
            fprintf(stderr, "\n");

            if (auth_pw) {
                /* We could authenticate via password */
                if (libssh2_userauth_password(session, username, password)) {
                    fprintf(stderr, "Authentication by password failed.\n");
                    goto shutdown;
                }
            } else {
                /* Or by public key */
                if (libssh2_userauth_publickey_fromfile(session, username,
                                    "/home/username/.ssh/id_rsa.pub",
                                    "/home/username/.ssh/id_rsa",
                                    password)) {
                    fprintf(stderr, "\tAuthentication by public key failed\n");
                    goto shutdown;
                }
            }

            fprintf(stderr, "libssh2_sftp_init()!\n");
            sftp_session = libssh2_sftp_init(session);

            if (!sftp_session) {
                fprintf(stderr, "Unable to init SFTP session\n");
                goto shutdown;
            }

            fprintf(stderr, "libssh2_sftp_open()!\n");
            /* Request a file via SFTP */
            sftp_handle =
                libssh2_sftp_open(sftp_session, sftppath,
                              LIBSSH2_FXF_WRITE|LIBSSH2_FXF_CREAT|LIBSSH2_FXF_TRUNC,
                              LIBSSH2_SFTP_S_IRUSR|LIBSSH2_SFTP_S_IWUSR|
                              LIBSSH2_SFTP_S_IRGRP|LIBSSH2_SFTP_S_IROTH);

            if (!sftp_handle) {
                fprintf(stderr, "Unable to open file with SFTP\n");
                goto shutdown;
            }
            fprintf(stderr, "libssh2_sftp_open() is done, now send data!\n");
            do {
                nread = fread(mem, 1, sizeof(mem), local);
                if (nread <= 0) {
                    /* end of file */
                    break;
                }
                ptr = mem;

                do {
                    /* write data in a loop until we block */
                    rc = libssh2_sftp_write(sftp_handle, ptr, nread);
                    if(rc < 0)
                        break;
                    ptr += rc;
                    nread -= rc;
                } while (nread);

            } while (rc > 0);

            libssh2_sftp_close(sftp_handle);
            libssh2_sftp_shutdown(sftp_session);

        shutdown:
            libssh2_session_disconnect(session,
                                       "Normal Shutdown, Thank you for playing");
            libssh2_session_free(session);

        #ifdef WIN32
            closesocket(sock);
        #else
            close(sock);
        #endif
            if (local)
                fclose(local);
            fprintf(stderr, "all done\n");

            libssh2_exit();

            return 0;
}

static int receive_file(remote_connection_data* data){

    return 0;

}




#include "console.h"
#include <libssh2_config.h>
#include <libssh2.h>
#include <libssh2_sftp.h>

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


int open_console() {

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

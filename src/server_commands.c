#define _BSD_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "server_commands.h"

/*
 * Display chat log
 */
int command_history(int socket) {
    FILE *fp;
    char str[80];

    fp = fopen("chat.txt", "r");

    while (fgets(str, 80, fp) != NULL) {
        send(socket, str, strlen(str), 0);
        /* Add delay because without delay the client would receive only the
           first message */
        usleep(20000);
    }

    fclose(fp);
    return 0;
}

/*
 * Write message into chat log file
 */
int command_write(char *message) {
    FILE *fp;
    fp = fopen("chat.txt", "a+");
    fputs(message, fp);
    fclose(fp);

    return 0;
}

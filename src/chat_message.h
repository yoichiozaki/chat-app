#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

typedef enum {
    msg_type_normal = 0,
    msg_type_status = 1,
    msg_type_ping = 2,
    msg_type_unknown = 3
} msg_type;

/* Chat message */
typedef struct _chatMessage {
    char *token;
    char *nickname;        /* Sender's nickname */
    msg_type message_type; /* Message type enum */
    char *message;         /* Chat message contents */
} chatMessage;

char *format_message(chatMessage *message);
chatMessage *parse_message(char *message);

#endif

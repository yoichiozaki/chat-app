#ifndef SESSION_H
#define SESSION_H

/* Chat session structure */
typedef struct _chatSession {
    char *nickname; /* User's nickname */
    char *token;    /* Session token used for simple authentication */
} chatSession;

char *create_token(char *token, size_t size);
chatSession *create_session(void);
void session_replace_nick(chatSession *session, char *newnick);
#endif

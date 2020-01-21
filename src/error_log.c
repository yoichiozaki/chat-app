#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "error_log.h"

/*
 * Log error without formatting to error.log
 * log_error("error occurred");
 */
void log_error(const char *msg) {
    FILE *fp;
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    fp = fopen("error.log", "a+");
    if (fp == NULL) {
        return;
    }
    fprintf(fp, "[%02d:%02d:%02d] %s\n", timeinfo->tm_hour, timeinfo->tm_min,
            timeinfo->tm_sec, msg);
    fclose(fp);
}

/*
 * Log error with printf formatting to error.log
 * log_errorf("number %d", 12);
 */
void log_errorf(const char *msg, ...) {
    FILE *fp;
    va_list args;
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    fp = fopen("error.log", "a+");
    if (fp == NULL) {
        return;
    }

    va_start(args, msg);
    fprintf(fp, "[%02d:%02d:%02d] ", timeinfo->tm_hour, timeinfo->tm_min,
            timeinfo->tm_sec);
    vfprintf(fp, msg, args);
    fprintf(fp, "\n");
    va_end(args);
    fclose(fp);
}

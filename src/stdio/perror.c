#include <string.h>
#include <errno.h>
#include <stdio.h>

void perror(const char *text) {
    int e = errno;
    if (text && *text) {
        fputs(text, stderr);
        fputc(' ', stderr);
    }
    fputs(strerror(e), stderr);
    fputc('\n', stderr);
}

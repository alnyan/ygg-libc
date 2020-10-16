#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <err.h>

void vwarn(const char *fmt, va_list args) {
    vfprintf(stderr, fmt, args);

    if (fmt && *fmt) {
        fputs(": ", stderr);
    }
    fputs(strerror(errno), stderr);
    fputc('\n', stderr);
}

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <err.h>

void errx(int eval, const char *fmt, ...) {
    va_list args;

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    exit(eval);
}

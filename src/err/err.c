#include <stdlib.h>
#include <err.h>

void err(int eval, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vwarn(fmt, args);
    va_end(args);
    exit(eval);
}

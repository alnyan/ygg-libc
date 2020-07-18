#include <stdio.h>

int snprintf(char *dst, size_t lim, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int r = vsnprintf(dst, lim, fmt, args);
    va_end(args);
    return r;
}

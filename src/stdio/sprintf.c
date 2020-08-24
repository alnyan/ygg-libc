#include <stdio.h>

int sprintf(char *dst, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int res = vsnprintf(dst, (size_t) -1, fmt, args);
    va_end(args);
    return res;
}

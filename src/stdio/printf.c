#include <stdio.h>

int printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int r = vfprintf(stdout, format, args);
    va_end(args);
    return r;
}

#include <stdio.h>

int scanf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int r = vfscanf(stdin, format, args);
    va_end(args);
    return r;
}

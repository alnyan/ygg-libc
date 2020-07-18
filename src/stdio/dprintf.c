#include <_libc/stdio.h>
#include <stdio.h>

int dprintf(int fd, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int r = vdprintf(fd, format, args);
    va_end(args);
    return r;
}

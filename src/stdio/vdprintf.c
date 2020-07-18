#include <_libc/stdio.h>
#include <unistd.h>
#include <stdio.h>

static int dprintf_out(void *ctx, const char *text, size_t len) {
    ssize_t r = write(*(int *) ctx, text, len);
    if (r < 0 || (size_t) r != len) {
        return -1;
    }
    return 0;
}

int vdprintf(int fd, const char *format, va_list args) {
    return __libc_vprintf(format, &fd, dprintf_out, args);
}

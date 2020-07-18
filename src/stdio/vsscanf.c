#include <_libc/stdio.h>
#include <stdio.h>

static int vsscanf_in(void *ctx) {
    const char **p = ctx;

    if (!*p || !**p) {
        return EOF;
    } else {
        int ch = **p;
        ++(*p);
        return ch;
    }
}

int vsscanf(const char *str, const char *format, va_list args) {
    return __libc_vscanf(format, &str, vsscanf_in, args);
}

#include <_libc/stdio.h>
#include <stdio.h>

static int vfprintf_out(void *ctx, const char *text, size_t count) {
    if (fwrite(text, 1, count, ctx) != count) {
        return -1;
    }
    return 0;
}

int vfprintf(FILE *fp, const char *format, va_list ap) {
    return __libc_vprintf(format, fp, vfprintf_out, ap);
}

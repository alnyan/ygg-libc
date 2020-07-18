#include <_libc/stdio.h>
#include <stdio.h>

int vfscanf(FILE *fp, const char *format, va_list ap) {
    return __libc_vscanf(format, fp, (int(*)(void *)) fgetc, ap);
}

#include <stdio.h>

int fscanf(FILE *fp, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int r = vfscanf(fp, format, ap);
    va_end(ap);
    return r;
}

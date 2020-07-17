#include <stdio.h>

int fprintf(FILE *fp, const char *format, ...) {
    va_list ap;
    int r;
    va_start(ap, format);
    r = vfprintf(fp, format, ap);
    va_end(ap);
    return r;
}

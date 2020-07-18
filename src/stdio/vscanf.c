#include <stdio.h>

int vscanf(const char *format, va_list args) {
    return vfscanf(stdin, format, args);
}

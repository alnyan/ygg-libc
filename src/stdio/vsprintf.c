#include <stdio.h>

int vsprintf(char *dst, const char *fmt, va_list args) {
    return vsnprintf(dst, (size_t) -1, fmt, args);
}

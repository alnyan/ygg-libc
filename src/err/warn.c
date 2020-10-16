#include <err.h>

void warn(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vwarn(fmt, args);
    va_end(args);
}

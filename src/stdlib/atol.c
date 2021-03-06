#include <stdlib.h>
#include <ctype.h>

long atol(const char *str) {
    long r = 0;
    while (*str && isdigit(*str)) {
        r *= 10;
        r += *str++ - '0';
    }
    return r;
}

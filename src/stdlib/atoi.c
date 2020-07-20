#include <stdlib.h>
#include <ctype.h>

int atoi(const char *str) {
    int r = 0;
    while (*str && isdigit(*str)) {
        r *= 10;
        r += *str++ - '0';
    }
    return r;
}

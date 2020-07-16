#include <string.h>

char *stpcpy(char *dest, const char *src) {
    do {
        *dest = *src;
        if (!*src++) {
            return dest;
        }
        ++dest;
    } while (1);
}

char *stpncpy(char *dest, const char *src, size_t n) {
    if (!n) {
        return dest;
    }
    do {
        *dest = *src;
        if (!*src++) {
            return dest;
        }
        ++dest;
        if (!--n) {
            return dest;
        }
    } while (1);
}

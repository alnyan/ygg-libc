#include <string.h>

int strcmp(const char *a, const char *b) {
    for (;; ++a, ++b) {
        int delta = *a - *b;
        if (delta) {
            return delta;
        }
        if (!*a) {       // Implies !*b
            break;
        }
    }
    return 0;
}

int strncmp(const char *a, const char *b, size_t lim) {
    for (; lim; ++a, ++b, --lim) {
        int delta = *a - *b;
        if (delta) {
            return delta;
        }
        if (!*a) {       // Implies !*b
            break;
        }
    }
    return 0;
}

#include <string.h>

char *strcpy(char *dst, const char *src) {
    size_t i;
    for (i = 0;; ++i) {
        dst[i] = src[i];
        if (!src[i]) {
            break;
        }
    }
    return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n; ++i) {
        dst[i] = src[i];
        if (!src[i]) {
            break;
        }
    }
    return dst;
}

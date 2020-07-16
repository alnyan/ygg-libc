#include <string.h>

char *strcat(char *dst, const char *src) {
    size_t len = strlen(dst);
    for (size_t i = 0;; ++i) {
        dst[len + i] = src[i];
        if (!src[i]) {
            break;
        }
    }
    return dst;
}

char *strncat(char *dst, const char *src, size_t n) {
    size_t d = strlen(dst);
    size_t i;

    for (i = 0; i < n && src[i]; ++i) {
        dst[d + i] = src[i];
    }
    dst[d + i] = 0;

    return dst;
}


#include <string.h>

void *memccpy(void *dst, const void *src, int c, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        ((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
        if (((unsigned char *) dst)[i] == c) {
            return dst + i;
        }
    }
    return NULL;
}

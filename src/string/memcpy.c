#include <string.h>

void *memcpy(void *dst, const void *src, size_t sz) {
    for (size_t i = 0; i < sz; ++i) {
        ((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
    }
    return dst;
}

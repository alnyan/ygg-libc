#include <string.h>

void *memmove(void *dest, const void *src, size_t n) {
    if (dest == src) {
        return dest;
    }

    if ((src + n) <= dest || (dest + n) <= src) {
        return memcpy(dest, src, n);
    }

    if (dest < src) {
        ptrdiff_t a = src - dest;
        memcpy(        dest,  src,      a);
        memcpy((void *) src,  src + a,  n - a);
    } else {
        ptrdiff_t a = dest - src;
        memcpy(    dest + a,  dest,     n - a);
        memcpy(        dest,  src,      a);
    }

    return dest;
}


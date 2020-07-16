#include <string.h>

void *memchr(const void *ptr, int v, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        if (((unsigned char *) ptr)[i] == v) {
            return (void *) ptr + i;
        }
    }
    return NULL;
}

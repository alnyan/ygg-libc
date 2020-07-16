#include <string.h>

void *memset(void *ptr, int v, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        ((unsigned char *) ptr)[i] = v;
    }
    return ptr;
}

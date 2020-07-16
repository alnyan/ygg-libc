#include <string.h>

int memcmp(const void *p0, const void *p1, size_t n) {
    int diff;
    for (size_t i = 0; i < n; ++i) {
        diff = ((unsigned char *) p0)[i] - ((unsigned char *) p1)[i];
        if (diff) {
            return diff;
        }
    }
    return 0;
}

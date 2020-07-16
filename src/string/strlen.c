#include <string.h>

size_t strlen(const char *s) {
    size_t r;
    for (r = 0; s[r]; ++r);
    return r;
}

size_t strnlen(const char *s, size_t len) {
    size_t r;
    for (r = 0; r < len && s[r]; ++r);
    return r;
}

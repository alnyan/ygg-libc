#include <string.h>

size_t strspn(const char *s, const char *accept) {
    size_t l = 0;

    while (*s) {
        if (!strchr(accept, *s)) {
            return l;
        }
        ++l;
        ++s;
    }
    return l;
}

size_t strcspn(const char *s, const char *reject) {
    size_t l = 0;

    while (*s) {
        if (strchr(reject, *s)) {
            return l;
        }
        ++l;
        ++s;
    }
    return l;
}

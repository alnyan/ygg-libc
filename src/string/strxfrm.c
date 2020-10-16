#include <string.h>

// Locales are ignored, so just act like strncpy()
size_t strxfrm(char *__Restrict dest, const char *__Restrict src, size_t n) {
    size_t i = 0;
    while (*src && i < n) {
        *dest = *src;
        dest++;
        src++;
        i++;
    }
    if (i < n) {
        *dest = 0;
    }
    return i;
}

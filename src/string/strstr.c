#include <string.h>

char *_strstr(const char *haystack, const char *needle) {
    // TODO: maybe use KMP algorithm for small needle sizes
    size_t n = strlen(needle);
    if (!*needle && !*haystack) {
        return (char *) haystack;
    }

    for (size_t i = 0; haystack[i]; ++i) {
        if (!strncmp(haystack + i, needle, n)) {
            return (char *) haystack + i;
        }
    }
    return NULL;
}


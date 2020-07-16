#include <string.h>

char *strchr(const char *str, int chr) {
    for (; *str; ++str) {
        if (*str == chr) {
            return (char *) str;
        }
    }
    return NULL;
}

char *strrchr(const char *str, int chr) {
    size_t len = strlen(str);
    if (!len) {
        return NULL;
    }
    while (--len) {
        if (str[len] == chr) {
            return (char *) &str[len];
        }
    }
    return NULL;
}

#include <stdlib.h>
#include <string.h>

char *strdup(const char *str) {
    char *ptr = malloc(strlen(str) + 1);
    if (ptr) {
        strcpy(ptr, str);
    }
    return ptr;
}

char *strndup(const char *str, size_t len) {
    char *ptr;
    size_t l = strnlen(str, len);
    ptr = malloc(l + 1);
    if (ptr) {
        strncpy(ptr, str, l);
        ptr[l] = 0;
    }
    return ptr;
}

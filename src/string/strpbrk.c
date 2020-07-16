#include <string.h>

char *strpbrk(const char *str, const char *accept) {
    for (; *str; ++str) {
        if (strchr(accept, *str)) {
            return (char *) str;
        }
    }
    return NULL;
}

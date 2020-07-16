#include <string.h>

// XXX: Not actually implemented - current locale is C
int strcoll(const char *a, const char *b) {
    return strcmp(a, b);
}

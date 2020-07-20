#include <_libc/environ.h>
#include <string.h>
#include <stdlib.h>

char *getenv(const char *key) {
    char **p = __libc_env_find(environ, key);
    if (!p) {
        return NULL;
    }
    return *p + strlen(key) + 1;
}

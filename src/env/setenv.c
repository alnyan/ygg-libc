#include <_libc/environ.h>
#include <string.h>
#include <stdlib.h>

static int environ_pristine = 1;

// Returns 1 if env variable string was malloc()d
static int env_is_alloc(const char *ptr) {
    return (((uintptr_t) ptr) < __libc_orig_argp_base) ||
            ((uintptr_t) ptr) >= (__libc_orig_argp_base + (__libc_orig_argp_count << 12));
}

int setenv(const char *key, const char *value, int overwrite) {
    // Try to find the key first
    char **p = __libc_env_find(environ, key);

    if (!p) {
        // Reallocate the environment pointer list
        size_t envpl;
        for (envpl = 0; environ[envpl]; ++envpl);

        char **environ_new;
        if (environ_pristine) {
            environ_new = malloc(sizeof(char *) * (envpl + 2));
            if (!environ_new) {
                return -1;
            }

            memcpy(environ_new, environ, sizeof(char *) * (envpl + 1));
            environ_pristine = 0;
        } else {
            environ_new = realloc(environ, sizeof(char *) * (envpl + 2));
        }

        environ_new[envpl + 1] = NULL;
        environ = environ_new;
        p = &environ[envpl];
    } else {
        if (!overwrite) {
            return -1;
        }
    }

    // Free the previous value first
    char *oldp = *p;
    *p = NULL;
    if (oldp && env_is_alloc(oldp)) {
        free(oldp);
    }

    size_t sk = strlen(key);
    oldp = malloc(sk);
    strcpy(oldp, key);
    oldp[sk] = '=';
    strcpy(oldp + sk + 1, value);

    *p = oldp;

    return 0;
}

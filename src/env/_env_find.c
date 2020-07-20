#include <_libc/environ.h>
#include <string.h>

char **__libc_env_find(char **env, const char *key) {
    size_t i;
    for (i = 0; env[i]; ++i) {
        const char *e = strchr(env[i], '=');
        if (!e) {
            // ???
            continue;
        }

        // My length != their length
        if ((size_t) (e - env[i]) != strlen(key)) {
            continue;
        }

        if (!strncmp(key, env[i], e - env[i])) {
            return &env[i];
        }
    }

    return NULL;
}

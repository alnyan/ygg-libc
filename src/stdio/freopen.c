#include <errno.h>
#include <stdio.h>

FILE *freopen(const char *pathname, const char *mode, FILE *fp) {
    if (!pathname) {
        // ... it's implementation-defined which changes
        //     of mode are permitted (if any)
        errno = EINVAL;
        return NULL;
    }

    // TODO: reuse the same FILE
    fclose(fp);
    fp = fopen(pathname, mode);
    return fp;
}

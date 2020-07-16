#include <_libc/stdio.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

FILE *fopen(const char *pathname, const char *mode) {
    FILE *fp = __libc_file_create();
    if (!fp) {
        return NULL;
    }

    if (__libc_file_open_path(fp, pathname, mode) != 0) {
        int e = errno;
        fclose(fp);
        errno = e;
        return NULL;
    }

    return fp;
}

#include <_libc/stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

FILE *fdopen(int fd, const char *mode) {
    FILE *fp = __libc_file_create();
    int e;
    if (!fp) {
        return NULL;
    }

    int flags;
    if ((flags = __libc_file_mode(mode)) < 0) {
        errno = EINVAL;
        goto err;
    }

    if (!(flags & (FILE_MODE_WRITE | FILE_MODE_READ))) {
        errno = EINVAL;
        goto err;
    }

    if (__libc_file_open_fd(fp, fd, flags) != 0) {
        goto err;
    }

    return fp;
err:
    e = errno;
    fclose(fp);
    errno = e;
    return NULL;
}

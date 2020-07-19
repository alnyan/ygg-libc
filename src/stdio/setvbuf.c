#include <_libc/stdio.h>
#include <errno.h>
#include <stdio.h>

int setvbuf(FILE *fp, char *buf, int mode, size_t size) {
    if (mode != _IONBF && mode != _IOLBF && mode != _IOFBF) {
        errno = EINVAL;
        return -1;
    }

    if (fflush(fp) != 0) {
        return -1;
    }

    flockfile(fp);

    if (mode == _IONBF) {
        fp->buf_mode = mode;
        funlockfile(fp);
        return 0;
    }

    if (!size) {
        size = BUFSIZ;
    }
    if (size > BUFSIZ) {
        // This is not supported
        errno = EINVAL;
        funlockfile(fp);
        return -1;
    }

    fp->buf_mode = mode;
    if (buf) {
        fp->buf = buf;
    } else {
        // Just use the original buffer
        fp->buf = &fp[1];
    }

    funlockfile(fp);
    return 0;
}

#include <_libc/stdio.h>
#include <stdio.h>
#include <errno.h>

size_t fread_unlocked(void *buf, size_t size, size_t nmemb, FILE *fp) {
    // TODO: buffering
    if (!(fp->flags & FILE_MODE_READ)) {
        errno = EBADF;
        fp->flags |= FILE_FLAG_ERROR;
        return 0;
    }

    size_t rem = size * nmemb;
    size_t off = 0;
    fp->flags &= ~FILE_FLAG_EOF;
    while (rem) {
        ssize_t bread = fp->read(fp->ctx, buf + off, rem);
        if (bread < 0) {
            fp->flags |= FILE_FLAG_ERROR;
            return off / size;
        }
        if (bread == 0) {
            fp->flags |= FILE_FLAG_EOF;
            return off / size;
        }
        off += bread;
        rem -= bread;
    }

    return off / size;
}

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

    if (fp->buf_mode == _IONBF) {
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

    for (size_t i = 0; i < size * nmemb; i += size) {
        for (size_t b = 0; b < size; ++b) {
            int r = fgetc_unlocked(fp);

            if (r == EOF) {
                return i / size;
            }

            ((char *) buf)[i + b] = r;
        }
    }

    return nmemb;
}

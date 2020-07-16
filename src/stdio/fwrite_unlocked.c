#include <_libc/stdio.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>

size_t fwrite_unlocked(const void *ptr, size_t size, size_t nmemb, FILE *fp) {
    assert(fp);
    if (fp->flags & FILE_FLAG_EOF) {
        return 0;
    }

    if (!(fp->flags & FILE_MODE_WRITE)) {
        errno = EBADF;
        fp->flags |= FILE_FLAG_ERROR;
        return 0;
    }

    if (fp->buf_mode == _IONBF) {
        size_t rem = size * nmemb;
        size_t off = 0;

        fp->flags &= ~FILE_FLAG_EOF;
        while (rem) {
            ssize_t res = fp->write(fp->ctx, ptr + off, rem);
            if (res < 0) {
                // Signalled error
                fp->flags |= FILE_FLAG_ERROR;
                return off / size;
            }
            if (res == 0) {
                // Signalled EOF
                fp->flags |= FILE_FLAG_EOF;
                return off /size;
            }
            off += res;
            rem -= res;
        }

        return off / size;
    }

    for (size_t i = 0; i < size * nmemb; i += size) {
        for (size_t b = 0; b < size; ++b) {
            int r = fputc_unlocked(((char *) ptr)[i + b], fp);

            if (r < 0) {
                return i / size;
            }
        }
    }

    return nmemb;
}

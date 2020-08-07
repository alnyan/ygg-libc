#include <_libc/stdio.h>
#include <errno.h>
#include <stdio.h>

int fgetc_unlocked(FILE *fp) {
    if (fp->buf_mode == _IONBF) {
        unsigned char c;
        if (fread_unlocked(&c, sizeof(c), 1, fp) == 1) {
            return ((int) c) & 0xFF;
        }
        return EOF;
    }

    if (fp->flags & FILE_FLAG_EOF) {
        return EOF;
    }
    if (!(fp->flags & FILE_MODE_READ)) {
        errno = EBADF;
        fp->flags |= FILE_FLAG_ERROR;
        return EOF;
    }

    __libc_file_flush_write(fp);

    if (fp->ungetc != -1) {
        int r = fp->ungetc;
        fp->ungetc = -1;
        return r;
    }

    if (fp->rdbufpos >= fp->rdbuf) {
        // Reached end of readbuf
        // TODO: arbitrary buffer size setting?
        ssize_t bread = fp->read(fp->ctx, fp->buf, BUFSIZ);

        if (bread < 0) {
            fp->flags |= FILE_FLAG_ERROR;
            return EOF;
        }
        if (bread == 0) {
            fp->flags |= FILE_FLAG_EOF;
            return EOF;
        }

        fp->rdbufpos = 0;
        fp->rdbuf = bread;
    }

    char ch = ((char *) fp->buf)[fp->rdbufpos++];
    return ((int) ch) & 0xFF;
}

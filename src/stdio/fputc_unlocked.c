#include <_libc/stdio.h>
#include <errno.h>
#include <stdio.h>

int fputc_unlocked(int ch, FILE *fp) {
    if (fp->buf_mode == _IONBF) {
        unsigned char c = ch;
        if (fwrite_unlocked(&c, sizeof(c), 1, fp) == 1) {
            return c;
        }
        return EOF;
    }
    if (!(fp->flags & FILE_MODE_WRITE)) {
        errno = EBADF;
        fp->flags |= FILE_FLAG_ERROR;
        return 0;
    }

    __libc_file_flush_read(fp);

    ((char *) fp->buf)[fp->wrbuf++] = ch;

    if ((fp->buf_mode == _IOLBF && ch == '\n') || fp->wrbuf >= BUFSIZ) {
        if (__libc_file_flush_write(fp) != 0) {
            return EOF;
        }
    }

    return ch;
}

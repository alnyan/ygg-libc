#include <_libc/stdio.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static void file_default_free(void *ctx, FILE *fp) {
    (void) ctx;
    free(fp);
}

FILE *__libc_file_create(void) {
    FILE *res = malloc(sizeof(FILE) + BUFSIZ);
    if (!res) {
        errno = ENOMEM;
        return NULL;
    }
    memset(res, 0, sizeof(FILE));

    res->free = file_default_free;
    res->buf = ((void *) res) + sizeof(FILE);

    return res;
}

int __libc_file_mode(const char *mode) {
    int flags = 0;
    switch (*mode++) {
    case 'r':
        flags |= FILE_MODE_READ;
        break;
    case 'w':
        flags |= FILE_MODE_WRITE | FILE_MODE_CREAT | FILE_MODE_TRUNC;
        break;
    case 'a':
        flags |= FILE_MODE_WRITE | FILE_MODE_CREAT | FILE_MODE_APPEND;
        break;
    default:
        return -1;
    }
    return flags;
}

int __libc_file_flush_read(FILE *fp) {
    if ((fp->flags & FILE_MODE_READ) && fp->seek) {
        // TODO: off_t
        long count = fp->rdbuf - fp->rdbufpos;
        if (count < 0) {
            count = fp->seek(fp->ctx, count, SEEK_CUR);
            // Reset file read buffer
            fp->rdbuf = 0;
            fp->rdbufpos = 0;
            if (count < 0) {
                fp->flags |= FILE_FLAG_ERROR;
                return -1;
            }
        }
    }

    return 0;
}

int __libc_file_flush_write(FILE *fp) {
    if (fp->flags & FILE_MODE_WRITE) {
        size_t rem = fp->wrbuf;
        size_t off = 0;

        fp->wrbuf = 0;

        while (rem) {
            ssize_t bwrite = fp->write(fp->ctx, fp->buf + off, rem);

            if (bwrite < 0) {
                fp->flags |= FILE_FLAG_ERROR;
                return -1;
            }
            if (bwrite == 0) {
                fp->flags |= FILE_FLAG_EOF;
                return -1;
            }

            rem -= bwrite;
            off += bwrite;
        }
    }

    return 0;
}

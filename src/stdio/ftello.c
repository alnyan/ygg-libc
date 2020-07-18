#include <_libc/stdio.h>
#include <unistd.h>
#include <stdio.h>

off_t ftello(FILE *fp) {
    off_t res;
    flockfile(fp);
    off_t off = fp->seek(fp->ctx, 0, SEEK_CUR);
    if (off == (off_t) -1) {
        res = (off_t) -1;
        goto err;
    }

    off_t count_read = fp->rdbuf - fp->rdbufpos;
    off_t count_write = fp->wrbuf;

    if (off < count_read + count_write) {
        res = 0;
    } else {
        res = off - count_read + count_write;
    }
err:
    funlockfile(fp);
    return res;
}

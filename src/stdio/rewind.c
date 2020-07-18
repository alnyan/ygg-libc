#include <_libc/stdio.h>
#include <unistd.h>
#include <stdio.h>

void rewind(FILE *fp) {
    flockfile(fp);
    if (__libc_file_flush_read(fp) != 0 ||
        __libc_file_flush_write(fp) != 0) {
        goto err;
    }
    fp->seek(fp->ctx, 0, SEEK_SET);
err:
    funlockfile(fp);
}

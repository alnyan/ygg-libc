#include <_libc/stdio.h>
#include <unistd.h>
#include <stdio.h>

int fseeko(FILE *fp, off_t offset, int whence) {
    int res = 0;
    flockfile(fp);
    if (__libc_file_flush_read(fp) != 0) {
        res = -1;
        goto ret;
    }
    if (__libc_file_flush_write(fp) != 0) {
        res = -1;
        goto ret;
    }
    if (fp->seek(fp, offset, whence) == (off_t) -1) {
        res = -1;
    }
ret:
    funlockfile(fp);
    return res;
}

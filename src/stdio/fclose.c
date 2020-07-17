#include <_libc/stdio.h>
#include <stdio.h>

int fclose(FILE *fp) {
    __libc_file_flush_write(fp);
    __libc_file_flush_read(fp);

    int r = fp->close(fp->ctx);

    fp->free(fp->ctx, fp);

    return r;
}

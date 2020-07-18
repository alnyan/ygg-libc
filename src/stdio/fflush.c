#include <_libc/stdio.h>
#include <stdio.h>

int fflush(FILE *fp) {
    if (fp->buf_mode != _IONBF) {
        if (__libc_file_flush_read(fp) != 0) {
            return -1;
        }
        if (__libc_file_flush_write(fp) != 0) {
            return -1;
        }
    }
    return 0;
}

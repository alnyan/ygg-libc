#include <_libc/stdio.h>
#include <errno.h>
#include <stdio.h>

int fileno(FILE *fp) {
    // TODO: non-file FILEs
    return fp->fd;
}

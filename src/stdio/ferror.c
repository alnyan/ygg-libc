#include <_libc/stdio.h>
#include <stdio.h>

int ferror(FILE *fp) {
    return fp->flags & FILE_FLAG_ERROR;
}

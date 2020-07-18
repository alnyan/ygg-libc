#include <_libc/stdio.h>
#include <stdio.h>

int feof(FILE *fp) {
    return fp->flags & FILE_FLAG_EOF;
}

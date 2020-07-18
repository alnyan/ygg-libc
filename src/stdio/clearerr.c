#include <_libc/stdio.h>
#include <stdio.h>

void clearerr(FILE *fp) {
    flockfile(fp);
    fp->flags &= ~(FILE_FLAG_EOF | FILE_FLAG_ERROR);
    funlockfile(fp);
}

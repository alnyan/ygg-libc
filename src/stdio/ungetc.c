#include <_libc/stdio.h>
#include <errno.h>
#include <stdio.h>

static int ungetc_unlocked(int ch, FILE *fp) {
    if (fp->ungetc != -1 || ch == EOF) {
        fp->flags |= FILE_FLAG_ERROR;
        errno = ENOMEM;
        return EOF;
    }

    fp->ungetc = ch;
    return ch;
}

int ungetc(int ch, FILE *fp) {
    flockfile(fp);
    int r = ungetc_unlocked(ch, fp);
    funlockfile(fp);
    return r;
}

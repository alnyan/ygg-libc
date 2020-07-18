#include <stdio.h>

int fseek(FILE *fp, long offset, int whence) {
    return fseeko(fp, (off_t) offset, whence);
}

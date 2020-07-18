#include <stdio.h>

int fgetc(FILE *fp) {
    flockfile(fp);
    int r = fgetc_unlocked(fp);
    funlockfile(fp);
    return r;
}

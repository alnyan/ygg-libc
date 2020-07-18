#include <stdio.h>

int fputc(int ch, FILE *fp) {
    flockfile(fp);
    int c = fputc_unlocked(ch, fp);
    funlockfile(fp);
    return c;
}

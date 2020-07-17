#include <stdio.h>

char *fgets(char *buf, int len, FILE *fp) {
    flockfile(fp);
    char *r = fgets_unlocked(buf, len, fp);
    funlockfile(fp);
    return r;
}

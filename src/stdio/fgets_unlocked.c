#include <stdio.h>

char *fgets_unlocked(char *buf, int len, FILE *fp) {
    if (!len) {
        return NULL;
    }

    int rem = len;
    size_t off = 0;

    while (rem) {
        int ch = fgetc_unlocked(fp);

        if (ch == EOF) {
            break;
        }

        buf[off++] = ch;
        --rem;
        if (ch == '\n') {
            break;
        }
    }

    if (off) {
        return buf;
    } else {
        return NULL;
    }
}

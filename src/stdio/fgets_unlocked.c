#include <sys/debug.h>
#include <stdio.h>

char *fgets_unlocked(char *buf, int len, FILE *fp) {
    if (!len) {
        return NULL;
    }

    int rem = len - 1;
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
        ygg_debug_trace("fgets -> %d\n", off);
        buf[off] = 0;
        for (size_t i = 0; i < off; ++i) {
            ygg_debug_trace("buf[%d] = 0x%x\n", i, buf[i]);
        }
        return buf;
    } else {
        return NULL;
    }
}

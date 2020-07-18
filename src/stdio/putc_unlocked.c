#include <stdio.h>

int putc_unlocked(int ch, FILE *fp) {
    return fputc_unlocked(ch, fp);
}

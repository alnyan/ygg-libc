#include <stdio.h>

int putchar_unlocked(int ch) {
    return fputc_unlocked(ch, stdout);
}

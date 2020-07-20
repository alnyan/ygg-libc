#include <stdio.h>

int puts(const char *s) {
    flockfile(stdout);
    if (fputs(s, stdout) != 0) {
        funlockfile(stdout);
        return EOF;
    }
    if (fputc('\n', stdout) == EOF) {
        funlockfile(stdout);
        return EOF;
    }
    funlockfile(stdout);
    return 0;
}

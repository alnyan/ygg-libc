#include <string.h>
#include <stdio.h>

int fputs(const char *str, FILE *fp) {
    size_t len = strlen(str);
    if (fwrite(str, 1, len, fp) != len) {
        return EOF;
    }
    return 0;
}

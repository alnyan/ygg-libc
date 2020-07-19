#include <stdio.h>

void setbuf(FILE *fp, char *buf) {
    (void) setvbuf(fp, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
}

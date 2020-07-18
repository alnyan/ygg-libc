#include <stdio.h>

int fgetpos(FILE *fp, fpos_t *pos) {
    if ((*pos = ftello(fp)) < 0) {
        return -1;
    }
    return 0;
}

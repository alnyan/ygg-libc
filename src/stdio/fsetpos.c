#include <stdio.h>

int fsetpos(FILE *fp, const fpos_t *pos) {
    return fseeko(fp, *pos, SEEK_SET);
}

#include <stdio.h>

long ftell(FILE *fp) {
    return (long) ftello(fp);
}

#include <stdlib.h>
#include <string.h>

void *calloc(size_t size, size_t nmemb) {
    void *blk = malloc(size * nmemb);
    if (blk) {
        memset(blk, 0, size * nmemb);
    }
    return blk;
}

#include <stdio.h>

size_t fwrite(const void *data, size_t size, size_t nmemb, FILE *fp) {
    flockfile(fp);
    size_t r = fwrite_unlocked(data, size, nmemb, fp);
    funlockfile(fp);
    return r;
}

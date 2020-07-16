#include <stdio.h>

size_t fread(void *buf, size_t size, size_t nmemb, FILE *fp) {
    flockfile(fp);
    size_t r = fread_unlocked(buf, size, nmemb, fp);
    funlockfile(fp);
    return r;
}

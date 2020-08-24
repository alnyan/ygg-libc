#include <stdlib.h>

void *bsearch(const void *key,
              const void *base,
              size_t nmemb, size_t size,
              int (*compar) (const void *, const void *)) {
    size_t start = 0;
    size_t end = nmemb;

    while (start <= end) {
        size_t pivot = (start + end) / 2;
        int cmp = compar(base + size * pivot, key);

        if (cmp > 0) {
            end = pivot;
        } else if (cmp < 0) {
            start = pivot;
        } else {
            return (void *) base + size * pivot;
        }
    }
    return NULL;
}

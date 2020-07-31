#include <stdlib.h>

static int qsort_not_r(const void *a, const void *b, void *ctx) {
    return ((int (*) (const void *, const void *)) ctx)(a, b);
}

void qsort(void *base, size_t nmemb, size_t size, int (*cmp) (const void *, const void *)) {
    return qsort_r(base, nmemb, size, qsort_not_r, cmp);
}

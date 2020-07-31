#include <stdlib.h>

static inline void qsort_swap(void *base, size_t i0, size_t i1, size_t size) {
    unsigned char *p0 = base + i0 * size;
    unsigned char *p1 = base + i1 * size;
    char tmp;
    for (size_t i = 0; i < size; ++i) {
        tmp = p0[i];
        p0[i] = p1[i];
        p1[i] = tmp;
    }
}

// TODO: better pivot selection/partitioning
static size_t qsort_partition(void *base,
                              size_t nmemb,
                              size_t size,
                              int (*cmp) (const void *, const void *, void *),
                              void *ctx) {
    size_t pivot = nmemb - 1;
    size_t i = 0;

    for (size_t j = 0; j < nmemb; ++j) {
        if (cmp(base + j * size, base + pivot * size, ctx) < 0) {
            qsort_swap(base, j, i, size);
            ++i;
        }
    }
    qsort_swap(base, i, pivot, size);
    return i;
}

void qsort_r(void *base,
             size_t nmemb,
             size_t size,
             int (*cmp) (const void *, const void *, void *),
             void *ctx) {
    if (!size || nmemb < 2) {
        return;
    }

    size_t p = qsort_partition(base, nmemb, size, cmp, ctx);

    if (p > 1) {
        qsort_r(base, p, size, cmp, ctx);
    }
    if (p < nmemb - 2) {
        qsort_r(base + (p + 1) * size, nmemb - (p + 1), size, cmp, ctx);
    }
}


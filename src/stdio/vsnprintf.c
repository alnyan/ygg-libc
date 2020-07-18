#include <_libc/stdio.h>
#include <string.h>
#include <stdio.h>

struct vsnprintf_track {
    char *dst;
    size_t rem;
};

static int vsnprintf_out(void *ctx, const char *text, size_t len) {
    struct vsnprintf_track *t = ctx;
    if (!t->rem) {
        // Space only left for 0
        return -1;
    }
    if (len >= t->rem) {
        len = t->rem;
    }
    strncpy(t->dst, text, len);
    t->dst += len;
    t->rem -= len;
    return 0;
}

int vsnprintf(char *dst, size_t lim, const char *format, va_list args) {
    if (!lim) {
        return -1;
    }
    struct vsnprintf_track t = {
        .dst = dst,
        .rem = lim - 1
    };
    int r = __libc_vprintf(format, &t, vsnprintf_out, args);
    if (r < 0) {
        return r;
    }
    if ((size_t) r <= lim - 1) {
        dst[r] = 0;
    } else {
        dst[lim - 1] = 0;
    }
    return r;
}

#include <string.h>

// "Lower" group of errors
static const char *error0[64] = {};

char *strerror(int errnum) {
    if (!errnum) {
        return "success";
    }
    if (errnum < 0 || errnum >= 64 || !error0[errnum]) {
        return "unknown error";
    }
    return (char *) error0[errnum];
}

int strerror_r(int errnum, char *buf, size_t len) {
    const char *err = strerror(errnum);
    if (!len) {
        return -1;
    }
    strncpy(buf, err, len - 1);
    buf[len - 1] = 0;
    return 0;
}

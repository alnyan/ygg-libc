#include <unistd.h>
#include <string.h>
#include <errno.h>

static const char *_ttyname = "-tty-";

int ttyname_r(int fd, char *buf, size_t lim) {
    (void) fd;
    if (lim < sizeof(_ttyname)) {
        errno = ERANGE;
        return -1;
    }
    strncpy(buf, _ttyname, lim);
    return 0;
}

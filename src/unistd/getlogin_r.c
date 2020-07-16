#include <unistd.h>
#include <errno.h>

int getlogin_r(char *buf, size_t bufsize) {
    (void) buf;
    (void) bufsize;
    // TODO: read pwd for username
    errno = ENOENT;
    return -1;
}

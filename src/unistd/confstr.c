#include <unistd.h>
#include <errno.h>

size_t confstr(int name, char *buf, size_t len) {
    (void) name;
    (void) buf;
    (void) len;
    // TODO: _CS_PATH
    errno = EINVAL;
    return 0;
}

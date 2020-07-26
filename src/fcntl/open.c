#include <fcntl.h>

int open(const char *pathname, int flags, mode_t mode) {
    return openat(AT_FDCWD, pathname, flags, mode);
}

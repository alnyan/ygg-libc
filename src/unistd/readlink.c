#include <unistd.h>
#include <fcntl.h>

ssize_t readlink(const char *restrict pathname, char *restrict buf, size_t count) {
    return readlinkat(AT_FDCWD, pathname, buf, count);
}

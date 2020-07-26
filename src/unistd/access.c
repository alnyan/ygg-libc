#include <unistd.h>
#include <fcntl.h>

int access(const char *pathname, int mode) {
    return faccessat(AT_FDCWD, pathname, mode, 0);
}

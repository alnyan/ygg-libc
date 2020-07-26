#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <ygg/fcntl.h>
#include <unistd.h>
#include <errno.h>

int unlink(const char *pathname) {
    return unlinkat(AT_FDCWD, pathname, 0);
}

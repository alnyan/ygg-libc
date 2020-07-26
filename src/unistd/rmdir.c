#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <ygg/fcntl.h>
#include <unistd.h>
#include <errno.h>

int rmdir(const char *dirname) {
    return unlinkat(AT_FDCWD, dirname, AT_REMOVEDIR);
}


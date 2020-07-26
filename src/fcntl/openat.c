#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <fcntl.h>
#include <errno.h>

int openat(int dfd, const char *pathname, int flags, mode_t mode) {
    return SET_ERRNO(int, __syscall4(SYSCALL_NR_OPENAT, dfd, (long) pathname, flags, mode));
}

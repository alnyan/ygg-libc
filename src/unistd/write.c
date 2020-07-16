#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

ssize_t write(int fd, const void *data, size_t lim) {
    return SET_ERRNO(ssize_t, __syscall3(SYSCALL_NR_WRITE, fd, (long) data, lim));
}


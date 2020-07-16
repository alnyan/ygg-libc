#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

ssize_t read(int fd, void *data, size_t lim) {
    return SET_ERRNO(ssize_t, __syscall3(SYSCALL_NR_READ, fd, (long) data, lim));
}

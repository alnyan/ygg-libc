#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/ioctl.h>
#include <errno.h>

int ioctl(int fd, unsigned int fn, void *arg) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_IOCTL, fd, fn, (long) arg));
}

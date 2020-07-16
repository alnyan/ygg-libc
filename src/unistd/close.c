#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int close(int fd) {
    __syscall1(SYSCALL_NR_CLOSE, fd);
    errno = 0;
    return 0;
}

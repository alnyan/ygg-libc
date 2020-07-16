#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int pipe(int fds[2]) {
    return SET_ERRNO(int, __syscall1(SYSCALL_NR_PIPE, (long) fds));
}

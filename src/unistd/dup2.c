#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int dup2(int oldfd, int newfd) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_DUP2, oldfd, newfd));
}


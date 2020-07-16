#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int dup(int oldfd) {
    return SET_ERRNO(int, __syscall1(SYSCALL_NR_DUP, oldfd));
}

#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int setuid(uid_t uid) {
    return SET_ERRNO(int, __syscall1(SYSCALL_NR_SETUID, uid));
}

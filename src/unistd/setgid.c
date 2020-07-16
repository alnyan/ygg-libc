#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int setgid(gid_t gid) {
    return SET_ERRNO(int, __syscall1(SYSCALL_NR_SETGID, gid));
}

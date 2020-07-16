#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int chown(const char *pathname, uid_t uid, gid_t gid) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_CHOWN, (long) pathname, uid, gid));
}

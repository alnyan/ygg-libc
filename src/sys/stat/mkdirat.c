#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int mkdirat(int dfd, const char *pathname, mode_t mode) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_MKDIRAT, dfd, (long) pathname, mode));
}

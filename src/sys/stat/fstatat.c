#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int fstatat(int dfd, const char *restrict pathname, struct stat *restrict st, int flags) {
    return SET_ERRNO(int, __syscall4(SYSCALL_NR_FSTATAT, dfd, (long) pathname, (long) st, flags));
}

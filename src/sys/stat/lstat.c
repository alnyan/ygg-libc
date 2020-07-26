//#include <_libc/syscalls.h>
//#include <ygg/syscall.h>
#include <sys/stat.h>
//#include <errno.h>

int lstat(const char *restrict pathname, struct stat *restrict st) {
    return fstatat(AT_FDCWD, pathname, st, AT_SYMLINK_NOFOLLOW);
    //return SET_ERRNO(int, __syscall2(SYSCALL_NR_LSTAT, (long) pathname, (long) st));
}

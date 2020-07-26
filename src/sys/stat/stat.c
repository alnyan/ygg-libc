//#include <_libc/syscalls.h>
//#include <ygg/syscall.h>
#include <sys/stat.h>
//#include <errno.h>

int stat(const char *restrict pathname, struct stat *restrict st) {
    return fstatat(AT_FDCWD, pathname, st, 0);
    //return SET_ERRNO(int, __syscall2(SYSCALL_NR_STAT, (long) pathname, (long) st));
}

#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int chmod(const char *pathname, mode_t mode) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_CHMOD, (long) pathname, mode));
}

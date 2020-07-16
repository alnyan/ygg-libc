#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int chdir(const char *pathname) {
    return SET_ERRNO(int, __syscall1(SYSCALL_NR_CHDIR, (long) pathname));
}

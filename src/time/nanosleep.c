#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *restrict ts, struct timespec *restrict rem) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_NANOSLEEP, (long) ts, (long) rem));
}

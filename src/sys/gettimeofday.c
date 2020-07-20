#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/time.h>
#include <errno.h>

int gettimeofday(struct timeval *tv, struct timezone *tz) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_GETTIMEOFDAY, (long) tv, (long) tz));
}

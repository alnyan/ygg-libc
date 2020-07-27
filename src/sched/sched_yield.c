#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sched.h>

int sched_yield(void) {
    __syscall0(SYSCALL_NR_YIELD);
    return 0;
}

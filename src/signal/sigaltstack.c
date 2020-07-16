#include <errno.h>
#include <signal.h>
#include <ygg/syscall.h>
#include <_libc/syscalls.h>

int sigaltstack(const stack_t *ss, stack_t *old_ss) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_SIGALTSTACK, (long) ss, (long) old_ss));
}

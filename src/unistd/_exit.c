#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

_Noreturn void _exit(int status) {
    __syscall1(SYSCALL_NR_EXIT, status);
    while (1);
}

_Noreturn void _Exit(int status) __attribute__((alias("_exit")));

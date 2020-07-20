#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/utsname.h>
#include <errno.h>

int uname(struct utsname *u) {
    return SET_ERRNO(int, __syscall1(SYSCALL_NR_UNAME, (long) u));
}

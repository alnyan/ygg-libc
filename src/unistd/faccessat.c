#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int faccessat(int dfd, const char *pathname, int mode, int flags) {
    (void) dfd;
    (void) pathname;
    (void) mode;
    (void) flags;
    assert(0 && "system call not yet implemented");
}


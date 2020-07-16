#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int fchdir(int dfd) {
    (void) dfd;
    assert(0 && "system call not yet implemented");
}


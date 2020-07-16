#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

long fpathconf(int fd, int name) {
    (void) fd;
    (void) name;
    assert(0 && "system call not yet implemented");
}


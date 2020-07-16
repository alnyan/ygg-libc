#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int fchown(int fd, uid_t uid, gid_t gid) {
    (void) fd;
    (void) uid;
    (void) gid;
    assert(0 && "system call not yet implemented");
}

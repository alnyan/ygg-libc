#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int fchownat(int dfd, const char *pathname, uid_t uid, gid_t gid, int flags) {
    (void) dfd;
    (void) pathname;
    (void) uid;
    (void) gid;
    (void) flags;
    assert(0 && "system call not yet implemented");
}

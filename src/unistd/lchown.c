#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int lchown(const char *pathname, uid_t uid, gid_t gid) {
    (void) pathname;
    (void) uid;
    (void) gid;
    assert(0 && "system call not yet implemented");
}

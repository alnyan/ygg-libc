#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int setegid(gid_t gid) {
    (void) gid;
    assert(0 && "system call not yet implemented");
}

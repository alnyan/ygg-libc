#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int setregid(gid_t rgid, gid_t egid) {
    (void) rgid;
    (void) egid;
    assert(0 && "system call not yet implemented");
}

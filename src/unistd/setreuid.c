#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int setreuid(uid_t ruid, uid_t euid) {
    (void) ruid;
    (void) euid;
    assert(0 && "system call not yet implemented");
}

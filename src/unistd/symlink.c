#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int symlink(const char *target, const char *pathname) {
    (void) target;
    (void) pathname;
    assert(0 && "system call not yet implemented");
}

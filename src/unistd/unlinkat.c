#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int unlinkat(int dfd, const char *pathname, int flags) {
    (void) dfd;
    (void) pathname;
    (void) flags;
    assert(0 && "system call not yet implemented");
}

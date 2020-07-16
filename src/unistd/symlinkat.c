#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int symlinkat(const char *target, int linkdfd, const char *pathname) {
    (void) target;
    (void) linkdfd;
    (void) pathname;
    assert(0 && "system call not yet implemented");
}

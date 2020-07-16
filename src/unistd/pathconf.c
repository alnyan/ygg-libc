#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

long pathconf(const char *pathname, int name) {
    (void) pathname;
    (void) name;
    assert(0 && "system call not yet implemented");
}

#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int seteuid(uid_t uid) {
    (void) uid;
    assert(0 && "system call not yet implemented");
}

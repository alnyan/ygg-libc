#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int fexecve(int fd, char *const argv[], char *const envp[]) {
    (void) fd;
    (void) argv;
    (void) envp;
    assert(0 && "system call not yet implemented");
}


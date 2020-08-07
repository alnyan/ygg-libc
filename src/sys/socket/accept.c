#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/socket.h>
#include <errno.h>

int accept(int fd, struct sockaddr *sa, socklen_t *salen) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_ACCEPT, fd, (long) sa, (long) salen));
}

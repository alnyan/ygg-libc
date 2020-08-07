#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/socket.h>
#include <errno.h>

ssize_t recvfrom(int fd, void *buf, size_t lim, int flags, struct sockaddr *sa, socklen_t *salen) {
    (void) flags;
    return SET_ERRNO(ssize_t, __syscall5(SYSCALL_NR_RECVFROM, fd, (long) buf, lim, (long) sa, (long) salen));
}

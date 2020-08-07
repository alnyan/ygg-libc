#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/socket.h>
#include <errno.h>

int connect(int fd, const struct sockaddr *sa, socklen_t salen) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_CONNECT, fd, (long) sa, salen));
}

#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/socket.h>
#include <errno.h>

int socket(int dom, int type, int proto) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_SOCKET, dom, type, proto));
}

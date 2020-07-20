#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/select.h>
#include <errno.h>

int select(int nfds, fd_set *rfds, fd_set *wfds, fd_set *xfds, struct timeval *tv) {
    return SET_ERRNO(int, __syscall5(SYSCALL_NR_SELECT,
                                     nfds,
                                     (long) rfds,
                                     (long) wfds,
                                     (long) xfds,
                                     (long) tv));
}

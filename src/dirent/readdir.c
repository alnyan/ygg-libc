#include <_libc/syscalls.h>
#include <_libc/dirent.h>
#include <ygg/syscall.h>
#include <dirent.h>
#include <errno.h>

static ssize_t _readdir(int fd, struct dirent *entp) {
    return SET_ERRNO(ssize_t, __syscall2(SYSCALL_NR_READDIR, fd, (long) entp));
}

struct dirent *readdir(DIR *dirp) {
    ssize_t res;
    if (!dirp) {
        errno = EBADF;
        return NULL;
    }
    if ((res = _readdir(dirp->fd, &dirp->buf)) <= 0) {
        return NULL;
    }
    return &dirp->buf;
}

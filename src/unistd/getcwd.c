#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

char *getcwd(char *buf, size_t size) {
    if (SET_ERRNO(int, __syscall2(SYSCALL_NR_GETCWD, (long) buf, size)) == 0) {
        return buf;
    } else {
        return NULL;
    }
}

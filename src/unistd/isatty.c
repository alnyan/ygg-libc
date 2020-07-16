#include <_libc/syscalls.h>
#include <ygg/termios.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

// TODO: termios.h
extern int tcgetattr(int fd, struct termios *t);

int isatty(int fd) {
    struct termios dummy;
    if (tcgetattr(fd, &dummy) == 0) {
        return 1;
    } else {
        return 0;
    }
}

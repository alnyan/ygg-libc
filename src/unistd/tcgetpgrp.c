#include <unistd.h>
#include <ygg/termios.h>

// TODO: sys/ioctl.h
int ioctl(int fd, unsigned int cmd, void *arg);

pid_t tcgetprgp(int fd) {
    pid_t res;
    if (ioctl(fd, TIOCGPGRP, &res) != 0) {
        return -1;
    }
    return res;
}

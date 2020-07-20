#include <unistd.h>
#include <sys/ioctl.h>
#include <ygg/termios.h>

pid_t tcgetprgp(int fd) {
    pid_t res;
    if (ioctl(fd, TIOCGPGRP, &res) != 0) {
        return -1;
    }
    return res;
}

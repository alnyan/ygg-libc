#include <ygg/termios.h>
#include <unistd.h>

// TODO: sys/ioctl.h
int ioctl(int fd, unsigned int cmd, void *arg);

int tcsetpgrp(int fd, pid_t pgrp) {
    return ioctl(fd, TIOCSPGRP, &pgrp);
}

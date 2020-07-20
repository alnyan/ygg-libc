#include <sys/ioctl.h>
#include <termios.h>

int tcsetattr(int fd, int opt, const struct termios *tc) {
    switch (opt) {
    case TCSANOW:
    // No other variants now
    default:
        return ioctl(fd, TCSETS, (void *) tc);
    }
}

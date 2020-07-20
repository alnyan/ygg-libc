#include <sys/ioctl.h>
#include <termios.h>

int tcgetattr(int fd, struct termios *tc) {
    return ioctl(fd, TCGETS, tc);
}

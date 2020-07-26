#include <sys/stat.h>

int fstat(int fd, struct stat *st) {
    return fstatat(fd, NULL, st, AT_EMPTY_PATH);
}

#include <_libc/dirent.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>

DIR *opendir(const char *path) {
    int fd;
    DIR *res;

    if (!(res = malloc(sizeof(struct __DIR)))) {
        return NULL;
    }


    if ((fd = open(path, O_DIRECTORY | O_RDONLY, 0)) < 0) {
        fd = errno;
        free(res);
        errno = fd;
        // errno is set
        return NULL;
    }

    res->fd = fd;
    memset(&res->buf, 0, sizeof(res->buf));

    return res;
}

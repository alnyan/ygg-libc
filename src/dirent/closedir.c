#include <_libc/dirent.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int closedir(DIR *dirp) {
    if (!dirp) {
        return -1;
    }
    close(dirp->fd);
    free(dirp);
    return 0;
}

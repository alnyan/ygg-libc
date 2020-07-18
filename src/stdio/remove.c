#include <unistd.h>
#include <stdio.h>

// TODO: sys/stat.h
#include <ygg/stat.h>
extern int stat(const char *pathname, struct stat *st);

int remove(const char *pathname) {
    struct stat st;
    if (stat(pathname, &st) != 0) {
        return -1;
    }
    if ((st.st_mode & S_IFMT) == S_IFDIR) {
        return rmdir(pathname);
    } else {
        return unlink(pathname);
    }
}

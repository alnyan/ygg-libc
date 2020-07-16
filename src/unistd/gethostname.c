#include <unistd.h>
#include <string.h>
#include <errno.h>

// TODO: sys/utsname.h
#include <ygg/utsname.h>
extern int uname(struct utsname *buf);

int gethostname(char *name, size_t len) {
    // Use uname to retrieve hostname
    struct utsname v;
    if (!len || uname(&v) != 0) {
        return -1;
    }

    strncpy(name, v.nodename, len - 1);
    name[len] = 0;

    return 0;
}

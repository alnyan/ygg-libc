#include <_libc/pwfile.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <pwd.h>

int getpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result) {
    FILE *fp = fopen(PWD_FILE, "r");
    if (!fp) {
        return -1;
    }
    while (_getpwent(fp, pwd, buf, buflen) > 0) {
        if (!strcmp(pwd->pw_name, name)) {
            fclose(fp);
            *result = pwd;
            return 0;
        }
    }

    fclose(fp);
    errno = ENOENT;
    return -1;
}

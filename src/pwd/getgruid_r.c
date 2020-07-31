#include <_libc/pwfile.h>
#include <stdio.h>
#include <errno.h>
#include <grp.h>

int getgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen, struct group **result) {
    FILE *fp = fopen(GRP_FILE, "r");
    if (!fp) {
        return -1;
    }
    while (_getgrent(fp, grp, buf, buflen) > 0) {
        if (gid == grp->gr_gid) {
            fclose(fp);
            *result = grp;
            return 0;
        }
    }

    fclose(fp);
    errno = ENOENT;
    return -1;
}


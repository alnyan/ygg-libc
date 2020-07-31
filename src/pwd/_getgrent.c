#include <_libc/pwfile.h>
#include <string.h>
#include <ctype.h>
#include <grp.h>

// TODO: rewrite this
int _getgrent(FILE *fp, struct group *grp, char *buf, size_t buflen) {
    (void) buflen;
    char linebuf[512];
    char *e;
    char *ptr;
    int res;

    if (!fgets(linebuf, sizeof(linebuf), fp)) {
        return 0;
    }

    ptr = linebuf;
    size_t line_len = strlen(linebuf);
    if (!line_len) {
        return -1;
    }
    --line_len;

    // Trim whitespace
    while (line_len && isspace(linebuf[line_len])) {
        linebuf[line_len] = 0;
        --line_len;
    }

    // name:
    grp->gr_name = buf;
    if (!(e = strchr(ptr, ':'))) {
        return -1;
    }
    *e = 0;
    strcpy(grp->gr_name, ptr);
    buf += e - ptr + 1;
    ptr = e + 1;

    // gid:
    if (!(e = strchr(ptr, ':'))) {
        return -1;
    }
    *e = 0;
    res = sscanf(ptr, "%u", &grp->gr_gid);
    if (res != 1) {
        return -1;
    }
    ptr = e + 1;

    return 1;
}

#include <_libc/pwfile.h>
#include <string.h>
#include <ctype.h>
#include <pwd.h>

// TODO: rewrite this
int _getpwent(FILE *fp, struct passwd *pwd, char *buf, size_t buflen) {
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
    pwd->pw_name = buf;
    if (!(e = strchr(ptr, ':'))) {
        printf("no pwname\n");
        return -1;
    }
    *e = 0;
    strcpy(pwd->pw_name, ptr);
    buf += e - ptr + 1;
    ptr = e + 1;

    // passwd:
    pwd->pw_passwd = buf;
    if (!(e = strchr(ptr, ':'))) {
        printf("no pwpasswd\n");
        return -1;
    }
    *e = 0;
    strcpy(pwd->pw_passwd, ptr);
    buf += e - ptr + 1;
    ptr = e + 1;

    // uid:
    if (!(e = strchr(ptr, ':'))) {
        printf("no pwuid\n");
        return -1;
    }
    *e = 0;
    res = sscanf(ptr, "%u", &pwd->pw_uid);
    if (res != 1) {
        printf("no pwuid2\n");
        return -1;
    }
    ptr = e + 1;

    // gid:
    if (!(e = strchr(ptr, ':'))) {
        printf("no pwgid\n");
        return -1;
    }
    *e = 0;
    res = sscanf(ptr, "%u", &pwd->pw_gid);
    if (res != 1) {
        printf("no pwgid2\n");
        return -1;
    }
    ptr = e + 1;

    // comment:
    pwd->pw_gecos = buf;
    if (!(e = strchr(ptr, ':'))) {
        return -1;
    }
    *e = 0;
    strcpy(pwd->pw_gecos, ptr);
    buf += e - ptr + 1;
    ptr = e + 1;

    // dir:
    pwd->pw_dir = buf;
    if (!(e = strchr(ptr, ':'))) {
        return -1;
    }
    *e = 0;
    strcpy(pwd->pw_dir, ptr);
    buf += e - ptr + 1;
    ptr = e + 1;

    // shell
    pwd->pw_shell = buf;
    strcpy(pwd->pw_shell, ptr);

    return 1;
}

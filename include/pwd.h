#pragma once
#include <ygg/types.h>

struct passwd {
    char *pw_name;
    char *pw_passwd;            // Non-standard
    uid_t pw_uid;
    gid_t pw_gid;
    char *pw_comment;           // Non-standard
    char *pw_gecos;             // Non-standard
    char *pw_dir;
    char *pw_shell;
};

int getpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen, struct passwd **res);
int getpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen, struct passwd **res);

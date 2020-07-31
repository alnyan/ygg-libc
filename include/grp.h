#pragma once
#include <ygg/types.h>

struct group {
    char *gr_name;
    gid_t gr_gid;
    char **gr_mem;
};

int getgrnam_r(const char *name, struct group *grp, char *buf, size_t buflen, struct group **res);
int getgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen, struct group **res);

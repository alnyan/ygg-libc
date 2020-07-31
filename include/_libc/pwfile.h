#pragma once
#include <stdio.h>

#define PWD_FILE    "/etc/passwd"
#define GRP_FILE    "/etc/group"

struct passwd;
struct group;

int _getpwent(FILE *fp, struct passwd *pwd, char *buf, size_t buflen);
int _getgrent(FILE *fp, struct group *grp, char *buf, size_t buflen);

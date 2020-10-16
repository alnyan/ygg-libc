#pragma once
#include <ygg/fcntl.h>
#include <sys/types.h>
#include <bits/attr.h>
#include <ygg/stat.h>

#if defined(__cplusplus)
extern "C" {
#endif

int stat(const char *__Restrict path, struct stat *__Restrict buf);
int lstat(const char *__Restrict path, struct stat *__Restrict buf);
int fstat(int fd, struct stat *st);
int fstatat(int dfd, const char *__Restrict path, struct stat *__Restrict buf, int flags);

mode_t umask(mode_t cmask);

int mkdir(const char *path, mode_t mode);
int mkdirat(int fd, const char *path, mode_t mode);
int chmod(const char *pathname, mode_t mode);

#if defined(__cplusplus)
}
#endif

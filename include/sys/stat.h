#pragma once
#include <ygg/fcntl.h>
#include <sys/types.h>
#include <ygg/stat.h>

int stat(const char *restrict path, struct stat *restrict buf);
int lstat(const char *restrict path, struct stat *restrict buf);
int fstat(int fd, struct stat *st);
int fstatat(int dfd, const char *restrict path, struct stat *restrict buf, int flags);

mode_t umask(mode_t cmask);

int mkdir(const char *path, mode_t mode);
int mkdirat(int fd, const char *path, mode_t mode);
int chmod(const char *pathname, mode_t mode);

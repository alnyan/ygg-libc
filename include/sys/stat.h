#pragma once
#include <ygg/stat.h>

int stat(const char *restrict path, struct stat *restrict buf);
int lstat(const char *restrict path, struct stat *restrict buf);
int chmod(const char *pathname, mode_t mode);

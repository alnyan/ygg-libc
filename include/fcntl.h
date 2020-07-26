#pragma once
#include <ygg/fcntl.h>
#include <ygg/types.h>

int open(const char *pathname, int flags, mode_t mode);
int openat(int dfd, const char *pathname, int flags, mode_t mode);

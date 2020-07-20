#pragma once
#include <ygg/mount.h>

int mount(const char *src, const char *dst, const char *fs, unsigned long flags, void *data);

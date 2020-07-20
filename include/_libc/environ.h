#pragma once
#include <stdint.h>
#include <stddef.h>

extern char **environ;
extern size_t __libc_orig_argp_count;
extern uintptr_t __libc_orig_argp_base;

char **__libc_env_find(char **env, const char *key);

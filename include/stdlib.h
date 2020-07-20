#pragma once
#include <bits/attr.h>
#include <stddef.h>

__Malloc void *malloc(size_t size);
void *realloc(void *p, size_t newsz);
void free(void *ptr);

int atoi(const char *str);

char *getenv(const char *name);
int setenv(const char *name, const char *value, int overwrite);

// XXX: POSIX doesn't define _Noreturn attribute on those?
void _Exit(int status);
void exit(int status);

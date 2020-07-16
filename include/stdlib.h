#pragma once
#include <bits/attr.h>
#include <stddef.h>

__Malloc void *malloc(size_t size);
void free(void *ptr);

// XXX: POSIX doesn't define _Noreturn attribute on those?
void _Exit(int status);
void exit(int status);

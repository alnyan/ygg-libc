#pragma once
#include <bits/attr.h>
#include <stddef.h>

#define EXIT_SUCCESS        0
#define EXIT_FAILURE        1

double strtod(const char *nptr, char **endptr);

__Malloc void *calloc(size_t size, size_t nmemb);
__Malloc void *malloc(size_t size);
void *realloc(void *p, size_t newsz);
void free(void *ptr);
_Noreturn void abort(void);
int abs(int d);

int system(const char *command);

int atoi(const char *str);

char *getenv(const char *name);
int setenv(const char *name, const char *value, int overwrite);

_Noreturn void _Exit(int status);
_Noreturn void exit(int status);

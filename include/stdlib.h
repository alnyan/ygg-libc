#pragma once
#include <bits/attr.h>
#include <stddef.h>

#define EXIT_SUCCESS        0
#define EXIT_FAILURE        1

void qsort(void *base, size_t nmemb, size_t size, int (*cmp) (const void *, const void *));
void qsort_r(void *base,
             size_t nmemb,
             size_t size,
             int (*cmp) (const void *, const void *, void *),
             void *ctx);
void *bsearch(const void *key,
              const void *base,
              size_t nmemb,
              size_t size,
              int (*compar)(const void *, const void *));

long strtol(const char *nptr, char **endptr, int base);
unsigned long strtoul(const char *nptr, char **endptr, int base);

double strtod(const char *nptr, char **endptr);

int atoi(const char *str);
long atol(const char *str);
double atof(const char *str);

__Malloc void *calloc(size_t size, size_t nmemb);
__Malloc void *malloc(size_t size);
void *realloc(void *p, size_t newsz);
void free(void *ptr);
_Noreturn void abort(void);
int abs(int d);

int system(const char *command);

char *getenv(const char *name);
int setenv(const char *name, const char *value, int overwrite);

_Noreturn void _Exit(int status);
_Noreturn void exit(int status);

char *mktemp(char *temp);
size_t mbstowcs(wchar_t *dest, const char *src, size_t n);

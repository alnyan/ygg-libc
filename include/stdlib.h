#pragma once
#include <bits/attr.h>
#include <stddef.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct __div {
    int quot, rem;
} div_t;
typedef struct __ldiv {
    long quot, rem;
} ldiv_t;

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
__Noreturn void abort(void);

int abs(int d);
long labs(long d);

div_t div(int numer, int denom);
ldiv_t ldiv(long numer, long denom);

int rand(void);
void srand(unsigned int seed);

int system(const char *command);

char *getenv(const char *name);
int setenv(const char *name, const char *value, int overwrite);

__Noreturn void _Exit(int status);
__Noreturn void exit(int status);
int atexit(void (*function)(void));

char *mktemp(char *temp);
size_t mbstowcs(wchar_t *dest, const char *src, size_t n);

#if defined(__cplusplus)
}
#endif

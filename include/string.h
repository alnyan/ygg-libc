#pragma once
#include <bits/attr.h>
#include <stddef.h>

#if defined(__cplusplus)
extern "C" {
#endif

void    *memccpy(void *__Restrict dst, const void *__Restrict src, int c, size_t len);
void    *memchr(const void *ptr, int v, size_t len);
int      memcmp(const void *p0, const void *p1, size_t len);
void    *memcpy(void *dest, const void *src, size_t n);
void    *memmove(void *dst, const void *src, size_t len);
void    *memset(void *dest, int c, size_t n);

char    *stpcpy(char *__Restrict dst, const char *__Restrict src);
char    *stpncpy(char *__Restrict dst, const char *__Restrict src, size_t len);
char    *strcat(char *dst, const char *src);
char    *strchr(const char *str, int chr);
int      strcmp(const char *a, const char *b);
int      strcoll(const char *a, const char *b);
// TODO: strcoll_l
char    *strcpy(char *__Restrict dst, const char *__Restrict src);
size_t   strcspn(const char *a, const char *b);
char    *strdup(const char *str);
char    *strerror(int errnum);
// TODO: strerror_l
int      strerror_r(int errnum, char *dst, size_t lim);
size_t   strlen(const char *str);
char    *strncat(char *__Restrict dst, const char *__Restrict src, size_t len);
int      strncmp(const char *a, const char *b, size_t len);
char    *strncpy(char *__Restrict dst, const char *__Restrict src, size_t len);
char    *strndup(const char *str, size_t len);
size_t   strnlen(const char *str, size_t len);
char    *strpbrk(const char *str, const char *set);
char    *strrchr(const char *str, int chr);
char    *strsignal(int signum);
size_t   strspn(const char *a, const char *b);
char    *strstr(const char *a, const char *b);
char    *strtok(char *__Restrict str, const char *__Restrict delim);
char    *strtok_r(char *__Restrict str, const char *__Restrict delim, char **__Restrict saveptr);
size_t   strxfrm(char *__Restrict dest, const char *__Restrict src, size_t n);

int      strcasecmp(const char *a, const char *b);
int      strncasecmp(const char *a, const char *b, size_t n);

#if defined(__cplusplus)
}
#endif

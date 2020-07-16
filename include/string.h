#pragma once
#include <stddef.h>

void    *memccpy(void *restrict dst, const void *restrict src, int c, size_t len);
void    *memchr(const void *ptr, int v, size_t len);
int      memcmp(const void *p0, const void *p1, size_t len);
void    *memcpy(void *dest, const void *src, size_t n);
void    *memmove(void *dst, const void *src, size_t len);
void    *memset(void *dest, int c, size_t n);

char    *stpcpy(char *restrict dst, const char *restrict src);
char    *stpncpy(char *restrict dst, const char *restrict src, size_t len);
char    *strcat(char *dst, const char *src);
char    *strchr(const char *str, int chr);
int      strcmp(const char *a, const char *b);
int      strcoll(const char *a, const char *b);
// TODO: strcoll_l
char    *strcpy(char *restrict dst, const char *restrict src);
size_t   strcspn(const char *a, const char *b);
char    *strdup(const char *str);
char    *strerror(int errnum);
// TODO: strerror_l
int      strerror_r(int errnum, char *dst, size_t lim);
size_t   strlen(const char *str);
char    *strncat(char *restrict dst, const char *restrict src, size_t len);
int      strncmp(const char *a, const char *b, size_t len);
char    *strncpy(char *restrict dst, const char *restrict src, size_t len);
char    *strndup(const char *str, size_t len);
size_t   strnlen(const char *str, size_t len);
char    *strpbrk(const char *str, const char *set);
char    *strrchr(const char *str, int chr);
char    *strsignal(int signum);
size_t   strspn(const char *a, const char *b);
char    *strstr(const char *a, const char *b);
char    *strtok(char *restrict str, const char *restrict delim);
char    *strtok_r(char *restrict str, const char *restrict delim, char **restrict saveptr);

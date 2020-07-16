#pragma once
#include <stddef.h>

#define EOF             -1
#define BUFSIZ          8192
#define _IOLBF          1
#define _IONBF          2
#define TMP_MAX         10000
#define FOPEN_MAX       8               // TODO
#define FILENAME_MAX    1024

typedef struct __FILE FILE;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;

FILE  *fopen(const char *pathname, const char *mode);
int    fclose(FILE *fp);

void   flockfile(FILE *fp);
void   funlockfile(FILE *fp);

//// _unlocked functions
size_t fwrite_unlocked(const void *data, size_t size, size_t nmemb, FILE *fp);
size_t fread_unlocked(void *data, size_t size, size_t nmemb, FILE *fp);
int    fgetc_unlocked(FILE *fp);
int    fputc_unlocked(int ch, FILE *fp);

//// Regular functions
size_t fwrite(const void *data, size_t size, size_t nmemb, FILE *fp);
size_t fread(void *data, size_t size, size_t nmemb, FILE *fp);

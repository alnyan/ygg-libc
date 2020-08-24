#pragma once
#include <sys/types.h>
#include <stddef.h>
#include <stdarg.h>

#define EOF             -1
#define BUFSIZ          8192
#define _IOLBF          1
#define _IONBF          2
#define _IOFBF          3
#define TMP_MAX         10000
#define FOPEN_MAX       8               // TODO
#define FILENAME_MAX    1024

// TODO: merge these with kernel's fcntl.h
#define SEEK_SET    0
#define SEEK_CUR    1
#define SEEK_END    2

typedef struct __FILE FILE;
typedef off_t fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;

FILE  *fopen(const char *pathname, const char *mode);
FILE  *fdopen(int fd, const char *mode);
FILE  *freopen(const char *pathname, const char *mode, FILE *fp);
int    fclose(FILE *fp);
int    remove(const char *pathname);
int    rename(const char *oldpath, const char *newpath);                            // TODO
int    renameat(int olddfd, const char *oldpath, int newdfd, const char *newpath);  // TODO
char  *ctermid(char *s);
int    setvbuf(FILE *fp, char *buf, int mode, size_t size);
void   setbuf(FILE *fp, char *buf);
int    ungetc(int ch, FILE *fp);

FILE  *tmpfile(void);

FILE  *popen(const char *command, const char *type);
int    pclose(FILE *fp);

void   flockfile(FILE *fp);
void   funlockfile(FILE *fp);

//// _unlocked functions
size_t fwrite_unlocked(const void *data, size_t size, size_t nmemb, FILE *fp);
size_t fread_unlocked(void *data, size_t size, size_t nmemb, FILE *fp);
int    fgetc_unlocked(FILE *fp);
int    fputc_unlocked(int ch, FILE *fp);
char  *fgets_unlocked(char *buf, int size, FILE *fp);
int    getc_unlocked(FILE *fp);
int    getchar_unlocked(void);
int    putc_unlocked(int ch, FILE *fp);
int    putchar_unlocked(int ch);

//// Regular functions
size_t      fwrite(const void *data, size_t size, size_t nmemb, FILE *fp);
size_t      fread(void *data, size_t size, size_t nmemb, FILE *fp);
char       *fgets(char *buf, int size, FILE *fp);
int         fputs(const char *s, FILE *fp);
int         puts(const char *s);
int         fputc(int ch, FILE *fp);
void        perror(const char *msg);
void        rewind(FILE *fp);
int         fflush(FILE *fp);
int         feof(FILE *fp);
int         ferror(FILE *fp);
void        clearerr(FILE *fp);
int         fileno(FILE *fp);
int         fseek(FILE *fp, long offset, int whence);
int         fseeko(FILE *fp, off_t offset, int whence);
int         fsetpos(FILE *fp, const fpos_t *pos);
long        ftell(FILE *fp);
off_t       ftello(FILE *fp);
int         fgetpos(FILE *fp, fpos_t *pos);
int         fgetc(FILE *fp);
int         getc(FILE *fp);
int         getchar(void);
int         putc(int ch, FILE *fp);
int         putchar(int ch);
ssize_t     getdelim(char **lineptr, size_t *n, int delim, FILE *fp);
ssize_t     getline(char **lineptr, size_t *n, FILE *fp);

//// *printf() family
int    printf(const char *format, ...);
int    fprintf(FILE *fp, const char *format, ...);
int    dprintf(int fd, const char *format, ...);
int    sprintf(char *str, const char *format, ...);
int    snprintf(char *str, size_t size, const char *format, ...);
int    vprintf(const char *format, va_list ap);
int    vfprintf(FILE *fp, const char *format, va_list ap);
int    vdprintf(int fd, const char *format, va_list ap);
int    vsprintf(char *str, const char *format, va_list ap);
int    vsnprintf(char *str, size_t lim, const char *format, va_list ap);

//// *scanf() family
int    scanf(const char *format, ...);
int    fscanf(FILE *fp, const char *format, ...);
int    sscanf(const char *str, const char *format, ...);
int    vscanf(const char *format, va_list ap);
int    vfscanf(FILE *fp, const char *format, va_list ap);
int    vsscanf(const char *str, const char *format, va_list ap);

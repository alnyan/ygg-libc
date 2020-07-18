#pragma once
#include <sys/types.h>
#include <stdarg.h>

#define FILE_MODE_READ          (1 << 0)
#define FILE_MODE_WRITE         (1 << 1)
#define FILE_MODE_APPEND        (1 << 2)
#define FILE_MODE_TRUNC         (1 << 3)
#define FILE_MODE_CREAT         (1 << 4)

#define FILE_FLAG_ERROR         (1 << 16)
#define FILE_FLAG_EOF           (1 << 17)

struct __FILE {
    void *ctx;
    void *buf;

    ssize_t (*write)(void *ctx, const void *data, size_t len);
    ssize_t (*read) (void *ctx, void *data, size_t len);
    off_t   (*seek) (void *ctx, off_t offset, int whence);
    int     (*close)(void *ctx);

    void    (*free) (void *ctx, struct __FILE *fp);

    int fd, flags, buf_mode;
    size_t wrbuf, rdbuf, rdbufpos;
};

struct __FILE *__libc_file_create(void);
int __libc_file_open_path(struct __FILE *fp, const char *pathname, const char *mode);
int __libc_file_open_fd(struct __FILE *fp, int fd, int flags);
int __libc_file_mode(const char *mode);
int __libc_file_flush_read(struct __FILE *fp);
int __libc_file_flush_write(struct __FILE *fp);

int __libc_vprintf(const char *format,
                   void *ctx,
                   int (*out)(void *ctx, const char *text, size_t len),
                   va_list ap);
int __libc_vscanf(const char *format,
                  void *ctx,
                  int (*in)(void *ctx),
                  va_list ap);

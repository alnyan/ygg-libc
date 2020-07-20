#include <_libc/stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

static ssize_t file_read(void *ctx, void *buf, size_t lim);
static ssize_t file_write(void *ctx, const void *buf, size_t lim);
static int file_close(void *ctx);

char _stdin_buf[BUFSIZ];
char _stdout_buf[BUFSIZ];
char _stderr_buf[BUFSIZ];

FILE _stdin = {
    .buf = _stdin_buf,
    .buf_mode = _IOLBF,
    .ctx = &_stdin,
    .fd = STDIN_FILENO,
    .ungetc = -1,
    .free = NULL,
    .read = file_read,
    .write = file_write,
    .close = file_close,
    .flags = FILE_MODE_READ
};
FILE _stdout = {
    .buf = _stdout_buf,
    .buf_mode = _IOLBF,
    .ctx = &_stdout,
    .fd = STDOUT_FILENO,
    .free = NULL,
    .read = file_read,
    .write = file_write,
    .close = file_close,
    .flags = FILE_MODE_WRITE
};
FILE _stderr = {
    .buf = _stderr_buf,
    .buf_mode = _IONBF,
    .ctx = &_stdout,
    .fd = STDERR_FILENO,
    .free = NULL,
    .read = file_read,
    .write = file_write,
    .close = file_close,
    .flags = FILE_MODE_WRITE
};

FILE *const stdin = &_stdin;
FILE *const stdout = &_stdout;
FILE *const stderr = &_stderr;

static ssize_t file_read(void *ctx, void *buf, size_t lim) {
    return read(((FILE *) ctx)->fd, buf, lim);
}

static ssize_t file_write(void *ctx, const void *buf, size_t lim) {
    return write(((FILE *) ctx)->fd, buf, lim);
}

static int file_close(void *ctx) {
    return close(((FILE *) ctx)->fd);
}

static long file_seek(void *ctx, long off, int whence) {
    return lseek(((FILE *) ctx)->fd, off, whence);
}

int __libc_file_open_fd(FILE *fp, int fd, int flags) {
    // TODO: disallow certain combinations of params
    if (flags & FILE_MODE_READ) {
        fp->flags |= FILE_MODE_READ;
    }
    if (flags & FILE_MODE_WRITE) {
        fp->flags |= FILE_MODE_WRITE;
    }

    fp->fd = fd;
    fp->ctx = fp;

    fp->read = file_read;
    fp->write = file_write;
    fp->close = file_close;
    fp->seek = file_seek;

    return 0;
}

int __libc_file_open_path(FILE *fp, const char *pathname, const char *mode) {
    int flags, c_flags = 0;
    if ((flags = __libc_file_mode(mode)) == -1) {
        errno = EINVAL;
        return -1;
    }

    if (!(flags & (FILE_MODE_WRITE | FILE_MODE_READ))) {
        errno = EINVAL;
        return -1;
    }

    if (flags & FILE_MODE_WRITE) {
        if (flags & FILE_MODE_READ) {
            c_flags |= O_RDWR;
        } else {
            c_flags |= O_WRONLY;
        }
    } else {
        c_flags |= O_RDONLY;
    }
    if (flags & FILE_MODE_CREAT) {
        c_flags |= O_CREAT;
    }
    if (flags & FILE_MODE_TRUNC) {
        c_flags |= O_TRUNC;
    }

    int fd = open(pathname, c_flags, 0666);
    if (fd < 0) {
        return -1;
    }

    if (__libc_file_open_fd(fp, fd, flags) != 0) {
        int e = errno;
        close(fd);
        errno = e;
        return -1;
    }

    return 0;
}

#include <_libc/stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

// Internal pipe state
struct pipe {
    int fd;
    pid_t pid;
};

static ssize_t pipe_read(void *ctx, void *buf, size_t lim) {
    return read(((struct pipe *) ctx)->fd, buf, lim);
}

static ssize_t pipe_write(void *ctx, const void *buf, size_t lim) {
    return write(((struct pipe *) ctx)->fd, buf, lim);
}

static off_t pipe_seek(void *ctx, off_t offset, int whence) {
    (void) ctx;
    (void) offset;
    (void) whence;
    errno = ESPIPE;
    return -1;
}

static int pipe_close(void *_ctx) {
    struct pipe *ctx = _ctx;
    close(ctx->fd);
    int r;
    if (waitpid(ctx->pid, &r, 0) < 0) {
        return -1;
    }
    free(ctx);
    return r;
}

FILE *popen(const char *command, const char *mode) {
    int fds[2];
    struct pipe *ctx;
    FILE *fp = NULL;
    int flags = __libc_file_mode(mode);
    if (flags < 0) {
        errno = EINVAL;
        return NULL;
    }
    if ((flags & (FILE_MODE_WRITE | FILE_MODE_READ)) == (FILE_MODE_READ | FILE_MODE_WRITE)) {
        errno = EINVAL;
        return NULL;
    }

    if (!(ctx = calloc(1, sizeof(struct pipe)))) {
        goto err;
    }
    if (!(fp = __libc_file_create())) {
        goto err_ctx;
    }
    if (pipe(fds) != 0) {
        goto err_file;
    }
    if ((ctx->pid = fork()) == -1) {
        goto err_pipe;
    }

    if (ctx->pid == 0) {
        // In child
        if (flags & FILE_MODE_WRITE) {
            if (dup2(fds[0], STDIN_FILENO) < 0) {
                _exit(-1);
            }
        } else {
            if (dup2(fds[1], STDOUT_FILENO) < 0) {
                _exit(-1);
            }
        }
        close(fds[0]);
        close(fds[1]);

        _exit(execl("/bin/sh", "sh", "-c", command, NULL));
    }

    if (flags & FILE_MODE_WRITE) {
        close(fds[0]);
        ctx->fd = fds[1];
        fp->flags = FILE_MODE_WRITE;
    } else {
        close(fds[1]);
        ctx->fd = fds[0];
        fp->flags = FILE_MODE_READ;
    }

    fp->ctx = ctx;
    fp->read = pipe_read;
    fp->write = pipe_write;
    fp->seek = pipe_seek;
    fp->close = pipe_close;

    return fp;

    // TODO: preserve errno here
err_pipe:
    close(fds[0]);
    close(fds[1]);
err_file:
    fclose(fp);
err_ctx:
    free(ctx);
err:
    return NULL;
}

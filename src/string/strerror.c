#include <string.h>
#include <errno.h>

// "Lower" group of errors
static const char *error0[64] = {
    [EPERM] =       "Operation not permitted",
    [ENOENT] =      "No such file or directory",
    [ESRCH] =       "No such process",
    [EINTR] =       "Interrupted system call",
    [EIO] =         "I/O error",
    [ENXIO] =       "No such device or address",
    [E2BIG] =       "Argument list too long",
    [ENOEXEC] =     "Exec format error",
    [EBADF] =       "Bad file number",
    [ECHILD] =      "No child processes",
    [EAGAIN] =      "Try again",
    [ENOMEM] =      "Out of memory",
    [EACCES] =      "Permission denied",
    [EFAULT] =      "Bad address",
    [ENOTBLK] =     "Block device required",
    [EBUSY] =       "Device or resource busy",
    [EEXIST] =      "File exists",
    [EXDEV] =       "Cross-device link",
    [ENODEV] =      "No such device",
    [ENOTDIR] =     "Not a directory",
    [EISDIR] =      "Is a directory",
    [EINVAL] =      "Invalid argument",
    [ENFILE] =      "File table overflow",
    [EMFILE] =      "Too many open files",
    [ENOTTY] =      "Not a typewriter",
    [ETXTBSY] =     "Text file busy",
    [EFBIG] =       "File too large",
    [ENOSPC] =      "No space left on device",
    [ESPIPE] =      "Illegal seek",
    [EROFS] =       "Read-only file system",
    [EMLINK] =      "Too many links",
    [EPIPE] =       "Broken pipe",
    [EDOM] =        "Math argument out of domain of func",
    [ERANGE] =      "Math result not representable"
};

char *strerror(int errnum) {
    if (!errnum) {
        return "success";
    }
    if (errnum < 0 || errnum >= 64 || !error0[errnum]) {
        return "unknown error";
    }
    return (char *) error0[errnum];
}

int strerror_r(int errnum, char *buf, size_t len) {
    const char *err = strerror(errnum);
    if (!len) {
        return -1;
    }
    strncpy(buf, err, len - 1);
    buf[len - 1] = 0;
    return 0;
}

#pragma once
#include <sys/types.h>     // size_t, ssize_t

extern char **environ;


//// Defines
// POSIX conformance
#undef _POSIX_ADVISORY_INFO
#undef _POSIX_ASYNCHRONOUS_IO
#undef _POSIX_BARRIERS
#define _POSIX_CHOWN_RESTRICTED             200809L
#undef _POSIX_CLOCK_SELECTION
#undef _POSIX_CPU_TIME
#undef _POSIX_FSYNC                         // TODO: maybe I'll add this on a per-file basis
#undef _POSIX_IPV6                          // I don't even support IPv4 yet lol
#define _POSIX_JOB_CONTROL                  200809L
#undef _POSIX_MAPPED_FILES                  // TODO: I'll implement this eventually
#undef _POSIX_MEMLOCK
#undef _POSIX_MEMLOCK_RANGE
#undef _POSIX_MEMORY_PROTECTION
#undef _POSIX_MESSAGE_PASSING
#undef _POSIX_MONOTONIC_CLOCK               // TODO
#define _POSIX_NO_TRUNC                     200809L
#undef _POSIX_PRIORITIZED_IO
#undef _POSIX_PRIORITY_SCHEDULING           // TODO: maybe just define that and ignore the priorities
#undef _POSIX_RAW_SOCKETS                   // TODO: the kernel kinda supports them, but pending rewrite
#undef _POSIX_READER_WRITER_LOCKS
#undef _POSIX_REALTIME_SIGNALS
#undef _POSIX_REGEXP                        // TODO
#undef _POSIX_SAVED_IDS                     // TODO?
#undef _POSIX_SEMAPHORES
#undef _POSIX_SHARED_MEMORY_OBJECTS         // TODO
#define _POSIX_SHELL                        200809L
#undef _POSIX_SPAWN                         // TODO?
#undef _POSIX_SPIN_LOCKS                    // TODO?
#undef _POSIX_SPORADIC_SERVER
#undef _POSIX_SYNCHRONIZED_IO
#undef _POSIX_THREAD_ATTR_STACKADDR
#undef _POSIX_THREAD_ATTR_STACKSIZE
#undef _POSIX_THREAD_CPUTIME
#undef _POSIX_THREAD_PRIO_INHERIT
#undef _POSIX_THREAD_PRIO_PROTECT
#undef _POSIX_THREAD_PRIORITY_SCHEDULING
#undef _POSIX_THREAD_PROCESS_SHARED
#undef _POSIX_THREAD_ROBUST_PRIO_INHERIT
#undef _POSIX_THREAD_ROBUST_PRIO_PROTECT
#define _POSIX_THREAD_SAFE_FUNCTIONS        200809L
#undef _POSIX_THREAD_SPORADIC_SERVER
#undef _POSIX_THREADS                       // TODO
#undef _POSIX_TIMEOUTS                      // TODO?
#undef _POSIX_TIMERS                        // TODO
#undef _POSIX_TRACE                         // TODO?
#undef _POSIX_TRACE_EVENT_FILTER
#undef _POSIX_TRACE_INHERIT
#undef _POSIX_TRACE_LOG
#undef _POSIX_TYPED_MEMORY_OBJECTS
#define _POSIX_V6_LP64_OFF64                200809L
#define _POSIX_V7_LP64_OFF64                200809L
#undef _POSIX2_C_BIND                       // Dunno what that is
#undef _POSIX2_C_DEV                        // Ditto
#undef _POSIX2_CHAR_TERM
#undef _POSIX2_FORT_DEV                     // Lel
#undef _POSIX2_FORT_RUN                     // Lmao
#undef _POSIX2_LOCALEDEV
#undef _POSIX2_PBS
#undef _POSIX2_PBS_ACCOUNTING
#undef _POSIX2_PBS_CHECKPOINT
#undef _POSIX2_PBS_LOCATE
#undef _POSIX2_PBS_MESSAGE
#undef _POSIX2_PBS_TRACK
#undef _POSIX2_SW_DEV
#undef _POSIX2_UPE
#undef _XOPEN_CRYPT
#undef _XOPEN_ENH_I18N
#undef _XOPEN_REALTIME
#undef _XOPEN_SHM
#undef _XOPEN_STREAMS
#undef _XOPEN_UUCP

// TODO: merge these with kernel's fcntl.h
#define SEEK_SET    0
#define SEEK_CUR    1
#define SEEK_END    2

#define R_OK        4
#define W_OK        2
#define X_OK        1
#define F_OK        0

// No POSIX advisory locks

#define _PC_2_SYMLINKS              1
#define _PC_ALLOC_SIZE_MIN          2
#define _PC_ASYNC_IO                3
#define _PC_CHOWN_RESTRICTED        4
#define _PC_FILESIZEBITS            5
#define _PC_LINK_MAX                6
#define _PC_MAX_CANON               7
#define _PC_MAX_INPUT               8
#define _PC_NAME_MAX                9
#define _PC_NO_TRUNC                10
#define _PC_PATH_MAX                11
#define _PC_PIPE_BUF                12
#define _PC_PRIO_IO                 13
#define _PC_REC_INCR_XFER_SIZE      14
#define _PC_REC_MAX_XFER_SIZE       15
#define _PC_REC_MIN_XFER_SIZE       16
#define _PC_REC_XFER_ALIGN          17
#define _PC_SYMLINK_MAX             18
#define _PC_SYNC_IO                 19
#define _PC_TIMESTAMP_RESOLUTION    20
#define _PC_VDISABLE                21

#define _SC_2_C_BIND                        1
#define _SC_2_C_DEV                         2
#define _SC_2_CHAR_TERM                     3
#define _SC_2_FORT_DEV                      4
#define _SC_2_FORT_RUN                      5
#define _SC_2_LOCALEDEF                     6
#define _SC_2_PBS                           7
#define _SC_2_PBS_ACCOUNTING                8
#define _SC_2_PBS_CHECKPOINT                9
#define _SC_2_PBS_LOCATE                    10
#define _SC_2_PBS_MESSAGE                   11
#define _SC_2_PBS_TRACK                     12
#define _SC_2_SW_DEV                        13
#define _SC_2_UPE                           14
#define _SC_2_VERSION                       15
#define _SC_ADVISORY_INFO                   16
#define _SC_AIO_LISTIO_MAX                  17
#define _SC_AIO_MAX                         18
#define _SC_AIO_PRIO_DELTA_MAX              19
#define _SC_ARG_MAX                         20
#define _SC_ASYNCHRONOUS_IO                 21
#define _SC_ATEXIT_MAX                      22
#define _SC_BARRIERS                        23
#define _SC_BC_BASE_MAX                     24
#define _SC_BC_DIM_MAX                      25
#define _SC_BC_SCALE_MAX                    26
#define _SC_BC_STRING_MAX                   27
#define _SC_CHILD_MAX                       28
#define _SC_CLK_TCK                         29
#define _SC_CLOCK_SELECTION                 30
#define _SC_COLL_WEIGHTS_MAX                31
#define _SC_CPUTIME                         32
#define _SC_DELAYTIMER_MAX                  33
#define _SC_EXPR_NEST_MAX                   34
#define _SC_FSYNC                           35
#define _SC_GETGR_R_SIZE_MAX                36
#define _SC_GETPW_R_SIZE_MAX                37
#define _SC_HOST_NAME_MAX                   38
#define _SC_IOV_MAX                         39
#define _SC_IPV6                            40
#define _SC_JOB_CONTROL                     41
#define _SC_LINE_MAX                        42
#define _SC_LOGIN_NAME_MAX                  43
#define _SC_MAPPED_FILES                    44
#define _SC_MEMLOCK                         45
#define _SC_MEMLOCK_RANGE                   46
#define _SC_MEMORY_PROTECTION               47
#define _SC_MESSAGE_PASSING                 48
#define _SC_MONOTONIC_CLOCK                 49
#define _SC_MQ_OPEN_MAX                     50
#define _SC_MQ_PRIO_MAX                     51
#define _SC_NGROUPS_MAX                     52
#define _SC_OPEN_MAX                        53
#define _SC_PAGE_SIZE                       54
#define _SC_PAGESIZE                        55
#define _SC_PRIORITIZED_IO                  56
#define _SC_PRIORITY_SCHEDULING             57
#define _SC_RAW_SOCKETS                     58
#define _SC_RE_DUP_MAX                      59
#define _SC_READER_WRITER_LOCKS             60
#define _SC_REALTIME_SIGNALS                61
#define _SC_REGEXP                          62
#define _SC_RTSIG_MAX                       63
#define _SC_SAVED_IDS                       64
#define _SC_SEM_NSEMS_MAX                   65
#define _SC_SEM_VALUE_MAX                   66
#define _SC_SEMAPHORES                      67
#define _SC_SHARED_MEMORY_OBJECTS           68
#define _SC_SHELL                           69
#define _SC_SIGQUEUE_MAX                    70
#define _SC_SPAWN                           71
#define _SC_SPIN_LOCKS                      72
#define _SC_SPORADIC_SERVER                 73
#define _SC_SS_REPL_MAX                     74
#define _SC_STREAM_MAX                      75
#define _SC_SYMLOOP_MAX                     76
#define _SC_SYNCHRONIZED_IO                 77
#define _SC_THREAD_ATTR_STACKADDR           78
#define _SC_THREAD_ATTR_STACKSIZE           79
#define _SC_THREAD_CPUTIME                  80
#define _SC_THREAD_DESTRUCTOR_ITERATIONS    81
#define _SC_THREAD_KEYS_MAX                 82
#define _SC_THREAD_PRIO_INHERIT             83
#define _SC_THREAD_PRIO_PROTECT             84
#define _SC_THREAD_PRIORITY_SCHEDULING      85
#define _SC_THREAD_PROCESS_SHARED           86
#define _SC_THREAD_ROBUST_PRIO_INHERIT      87
#define _SC_THREAD_ROBUST_PRIO_PROTECT      88
#define _SC_THREAD_SAFE_FUNCTIONS           89
#define _SC_THREAD_SPORADIC_SERVER          90
#define _SC_THREAD_STACK_MIN                91
#define _SC_THREAD_THREADS_MAX              92
#define _SC_THREADS                         93
#define _SC_TIMEOUTS                        94
#define _SC_TIMER_MAX                       95
#define _SC_TIMERS                          96
#define _SC_TRACE                           97
#define _SC_TRACE_EVENT_FILTER              98
#define _SC_TRACE_EVENT_NAME_MAX            99
#define _SC_TRACE_INHERIT                   100
#define _SC_TRACE_LOG                       101
#define _SC_TRACE_NAME_MAX                  102
#define _SC_TRACE_SYS_MAX                   103
#define _SC_TRACE_USER_EVENT_MAX            104
#define _SC_TTY_NAME_MAX                    105
#define _SC_TYPED_MEMORY_OBJECTS            106
#define _SC_TZNAME_MAX                      107
#define _SC_V7_ILP32_OFF32                  108
#define _SC_V7_ILP32_OFFBIG                 109
#define _SC_V7_LP64_OFF64                   110
#define _SC_V7_LPBIG_OFFBIG                 111
#define _SC_V6_ILP32_OFF32                  112
#define _SC_V6_ILP32_OFFBIG                 113
#define _SC_V6_LP64_OFF64                   114
#define _SC_V6_LPBIG_OFFBIG                 115
#define _SC_VERSION                         116
#define _SC_XOPEN_CRYPT                     117
#define _SC_XOPEN_ENH_I18N                  118
#define _SC_XOPEN_REALTIME                  119
#define _SC_XOPEN_REALTIME_THREADS          120
#define _SC_XOPEN_SHM                       121
#define _SC_XOPEN_STREAMS                   122
#define _SC_XOPEN_UNIX                      123
#define _SC_XOPEN_UUCP                      124
#define _SC_XOPEN_VERSION                   125

#define _POSIX_VDISABLE                     0

#define STDERR_FILENO       2
#define STDOUT_FILENO       1
#define STDIN_FILENO        0

// File control
int access(const char *pathname, int acc);                                                      //+
int chdir(const char *pathname);                                                                //+
int chown(const char *pathname, uid_t uid, gid_t gid);                                          //+
int close(int fd);                                                                              //+
int dup(int fd);                                                                                //+
int dup2(int oldfd, int newfd);                                                                 //+
int execl(const char *pathname, const char *arg, ...);                                          //+
int execle(const char *pathname, const char *arg, ...);                                         //+
int execlp(const char *file, const char *arg, ...);                                             //-
int execv(const char *pathname, char *const argv[]);                                            //+
int execve(const char *pathname, char *const argv[], char *const envp[]);                       //+
int execvp(const char *file, char *const argv[]);                                               //-
int faccessat(int dfd, const char *pathname, int mode, int flags);                              //-
int fchdir(int dfd);                                                                            //-
int fchown(int dfd, uid_t uid, gid_t gid);                                                      //-
int fchownat(int dfd, const char *pathname, uid_t uid, gid_t gid, int flags);                   //-
int fdatasync(int fd);                                                                          //?
int fexecve(int fd, char *const argv[], char *const argp[]);                                    //-
long fpathconf(int fd, int name);                                                               //-
int fsync(int fd);                                                                              //?
int ftruncate(int fd, off_t size);                                                              //-
char *getcwd(char *buf, size_t lim);                                                            //+
int isatty(int fd);                                                                             //+
int lchown(const char *pathname, uid_t uid, gid_t gid);                                         //-
int link(const char *oldpath, const char *newpath);                                             //-
int linkat(int old_dfd, const char *oldpath, int new_dfd, const char *newpath, int flags);      //-
int lockf(int fd, int cmd, off_t len);                                                          //-
off_t lseek(int fd, off_t off, int whence);                                                     //+
long pathconf(const char *pathname, int name);                                                  //+
int pipe(int fds[2]);                                                                           //+
ssize_t pread(int fd, void *buf, size_t count, off_t offset);                                   //-
ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);                            //-
ssize_t read(int fd, void *buf, size_t count);                                                  //+
ssize_t readlink(const char *restrict pathname, char *restrict buf, size_t lim);                //-
ssize_t readlinkat(int dfd, const char *restrict pathname, char *restrict buf, size_t lim);     //-
int rmdir(const char *dirname);                                                                 //+
int symlink(const char *target, const char *linkpath);                                          //-
int symlinkat(const char *target, int linkdfd, const char *linkpath);                           //-
void sync(void);                                                                                //+
int truncate(const char *pathname, off_t size);                                                 //-
int unlink(const char *pathname);                                                               //+
int unlinkat(int dfd, const char *pathname, int flags);                                         //-
ssize_t write(int fd, const void *buf, size_t count);                                           //+

// Access control
gid_t getegid(void);                                                                            //+
uid_t geteuid(void);                                                                            //+
gid_t getgid(void);                                                                             //+
int getgroups(int size, gid_t list[]);                                                          //?
uid_t getuid(void);                                                                             //+
int setegid(gid_t egid);                                                                        //-
int seteuid(uid_t euid);                                                                        //-
int setgid(gid_t gid);                                                                          //+
int setregid(gid_t rgid, gid_t egid);                                                           //-
int setreuid(uid_t ruid, uid_t euid);                                                           //-
int setuid(uid_t uid);                                                                          //+

// System control
size_t confstr(int name, char *buf, size_t lim);                                                //+
long gethostid(void);                                                                           //+
int gethostname(char *buf, size_t lim);                                                         //+
char *getlogin(void);                                                                           //W
int getlogin_r(char *buf, size_t lim);                                                          //-
long sysconf(int name);                                                                         //-

// getopt
int getopt(int argc, char *const argv[], const char *optstr);                                   //

// Process control
_Noreturn void _exit(int status);                                                               //+
pid_t fork(void);                                                                               //+
pid_t getpgid(pid_t pid);                                                                       //+
pid_t getpgrp(void);                                                                            //+
pid_t getpid(void);                                                                             //+
pid_t getppid(void);                                                                            //-
pid_t getsid(void);                                                                             //-
int nice(int inc);                                                                              //+
int pause(void);                                                                                //+
int setpgid(pid_t pid, pid_t pgid);                                                             //+
pid_t setpgrp(void);                                                                            //+
pid_t setsid(void);                                                                             //-
unsigned int sleep(unsigned int sec);                                                           //+
pid_t tcgetprgp(int fd);                                                                        //+
int tcsetpgrp(int fd, pid_t pgrp);                                                              //+
char *ttyname(int fd);                                                                          //W
int ttyname_r(int fd, char *buf, size_t size);                                                  //?

// Helpers and crypt
char *crypt(const char *key, const char *salt);                                                 //
void encrypt(char block[64], int edflag);                                                       //
void swab(const void *from, void *to, ssize_t n);                                               //

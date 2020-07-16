#pragma once

static inline long __syscall0(long n) {
    unsigned long ret;
    asm volatile ("syscall"
                 :"=a"(ret)
                 :"a"(n)
                 :"rcx","r11","memory");
    return ret;
}

static inline long __syscall1(long n, long a1) {
    unsigned long ret;
    asm volatile ("syscall"
                 :"=a"(ret)
                 :"a"(n),"D"(a1)
                 :"rcx","r11","memory");
    return ret;
}

static inline long __syscall2(long n, long a1, long a2) {
    unsigned long ret;
    asm volatile ("syscall"
                 :"=a"(ret)
                 :"a"(n),"D"(a1),"S"(a2)
                 :"rcx","r11","memory");
    return ret;
}

static inline long __syscall3(long n, long a1, long a2, long a3) {
    unsigned long ret;
    asm volatile ("syscall"
                 :"=a"(ret)
                 :"a"(n),"D"(a1),"S"(a2),"d"(a3)
                 :"rcx","r11","memory");
    return ret;
}

static inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6) {
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	register long r9 __asm__("r9") = a6;
	asm volatile ("syscall"
                 :"=a"(ret)
                 :"a"(n),"D"(a1),"S"(a2),"d"(a3),"r"(r10),"r"(r8),"r"(r9)
                 :"rcx","r11","memory");
	return ret;
}

#define SET_ERRNO(t, r)                     ({ \
        t res = (t) r; \
        if (res < 0) { \
            errno = -res; \
        } \
        ((int) res) < 0 ? (t) -1 : res; \
    })

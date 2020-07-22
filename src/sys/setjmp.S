.section .text
.global setjmp
.global longjmp
.global _setjmp
.global _longjmp

// Context:
// rbx rbp r12 r13 r14 r15 rsp rip
//  0   8   16  24  32  40  48  56

setjmp:
_setjmp:
    // rdi - jmpbuf
    movq %rbx,  0(%rdi)
    movq %rbp,  8(%rdi)
    movq %r12, 16(%rdi)
    movq %r13, 24(%rdi)
    movq %r14, 32(%rdi)
    movq %r15, 40(%rdi)
    // rsp is pointing to return address now, so offset by 8
    leaq 8(%rsp), %rax
    movq %rax, 48(%rdi)
    // Store return address
    movq (%rsp), %rax
    movq %rax, 56(%rdi)
    movq $0, %rax
    ret

longjmp:
_longjmp:
    // rdi - jmpbuf, rsi - return
    mov %rsi, %rax

    movq  8(%rdi), %rbp

    // Setup new stack and return address
    movq 48(%rdi), %rsp
    pushq 56(%rdi)

    movq  0(%rdi), %rbx
    movq 16(%rdi), %r12
    movq 24(%rdi), %r13
    movq 32(%rdi), %r14
    movq 40(%rdi), %r15

    ret

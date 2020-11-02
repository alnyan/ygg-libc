.section .text
.global tan
.type tan, %function
tan:
    movsd %xmm0, -8(%rsp)
    fldl -8(%rsp)
    fptan
    fnstsw %ax
    andw $0x400, %ax
    jnz 1f
    fstp %st(0)
    fstpl -8(%rsp)
    movsd -8(%rsp), %xmm0
    ret
1:
    // TODO: handle out-of-range cases
    jmp .
.size tan, . - tan

.section .text
.global cos
.type cos, %function
cos:
    movsd %xmm0, -8(%rsp)
    fldl -8(%rsp)
    fcos
    fnstsw %ax
    andw $0x400, %ax
    jnz 1f
    fstpl -8(%rsp)
    movsd -8(%rsp), %xmm0
    ret
1:
    // TODO: handle out-of-range cases
    jmp .
.size cos, . - cos

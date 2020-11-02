.section .text
.global acos
.type acos, %function
acos:
    // acos(x) = atan(sqrt(1 - x * x) / x)
    movsd %xmm0, -8(%rsp)
    fldl -8(%rsp)

    fld %st(0)
    fmul %st(0)
    fld1
    fsubp
    fsqrt
    fxch %st(1)
    fpatan

    fstpl -8(%rsp)
    movsd -8(%rsp), %xmm0
    ret
.size acos, . - acos

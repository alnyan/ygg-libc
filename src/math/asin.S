.section .text
.global asin
.type asin, %function
asin:
    // acos(x) = atan(x / sqrt(1 - x * x))
    movsd %xmm0, -8(%rsp)
    fldl -8(%rsp)

    fld %st(0)
    fmul %st(0)
    fld1
    fsubp
    fsqrt
    fpatan

    fstpl -8(%rsp)
    movsd -8(%rsp), %xmm0
    ret
.size asin, . - asin

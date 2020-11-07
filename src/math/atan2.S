.section .text
.global atan2
.type atan2, %function
atan2:
    movsd %xmm0, -8(%rsp)
    fldl -8(%rsp)
    movsd %xmm1, -8(%rsp)
    fldl -8(%rsp)
    fpatan
    fstpl -8(%rsp)
    movsd -8(%rsp), %xmm0
    ret
.size atan2, . - atan2

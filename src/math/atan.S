.section .text
.global atan
.type atan, %function
atan:
    movsd %xmm0, -8(%rsp)
    fldl -8(%rsp)
    fld1
    fpatan
    fstpl -8(%rsp)
    movsd -8(%rsp), %xmm0
    //jmp .
    ret
.size atan, . - atan

.section .text
.global exp
.type exp, %function
exp:
    movsd %xmm0, -8(%rsp)
    fldl -8(%rsp)

    // TODO: handle out-of-range cases
    // ...

    fldl2e
	fmulp
	fst	%st(1)
	frndint
	fst	%st(2)
	fsubrp
	f2xm1
	fld1
	faddp
	fscale
	fstp %st(1)

    fstpl -8(%rsp)
    movsd -8(%rsp), %xmm0

    ret
.size exp, . - exp

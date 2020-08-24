#include <sys/debug.h>
#include <_libc/stdio.h>
#include <ctype.h>
#include <stdio.h>

enum printf_len {
    PL_0,
    PL_h,
    PL_hh,
    PL_l,
    PL_ll,
    PL_j,
    PL_z,
    PL_t,
    PL_L
};

int __libc_vscanf(const char *format,
                  void *ctx,
                  int (*in)(void *ctx),
                  va_list ap) {
    size_t n_convert = 0;
    char *out_str;
    union {
        unsigned int value_u;
        unsigned long value_ul;
        unsigned long long value_ull;

        uintptr_t value_uintptr;
    } pv;
    enum printf_len lenmod;
    char ch;
    int ic = EOF;
#define peek()  \
    (ic == EOF ? (ic = in(ctx)) : ic)
#define pop()   \
    (ic == EOF ? ic : (ic = in(ctx)))

    (void) out_str;
    (void) lenmod;
    (void) pv;
    (void) ap;

    while ((ch = *format++)) {
        if (ch == ' ') {
            // Skip whitespace
            while (isspace(peek())) {
                if (pop() == EOF) {
                    break;
                }
            }
        } else if (ch == '%') {
            // Collect lenmod
            lenmod = PL_0;

            while ((ch = *format)) {
                switch (ch) {
                case 'l':
                    lenmod = (lenmod == PL_l ? PL_ll : PL_l);
                    ++format;
                    continue;
                case 'h':
                    lenmod = (lenmod == PL_h ? PL_hh : PL_h);
                    ++format;
                    continue;
                default:
                    break;
                }
                break;
            }

            // Conversion spec
            ch = *format++;
            if (ch == 'u') {
                // At least one should be numeric
                uintmax_t rv = 0;

                if (peek() == EOF || !isdigit(peek())) {
                    goto err;
                }

                while (isdigit(peek())) {
                    rv *= 10;
                    rv += (peek() - '0');
                    pop();
                }

                switch (lenmod) {
                case PL_0:
                    *va_arg(ap, int *) = (int) rv;
                    break;
                case PL_l:
                    *va_arg(ap, long *) = (long) rv;
                    break;
                case PL_ll:
                    *va_arg(ap, long long *) = (long long) rv;
                    break;
                default:
                    ygg_debug_trace("%s: unknown lenmod: %u\n", __func__, lenmod);
                    goto err;
                }
                ++n_convert;
            } else {
                ygg_debug_trace("%s: unknown conversion spec: %%%u\n", __func__, ch);
                while (1);
            }
        } else {
            // Literal character match
            if (peek() != ch) {
                goto err;
            }
            ygg_debug_trace("Match: literal %c\n", ch);
            pop();
        }
    }

err:
    if (!n_convert) {
        return -1;
    }
    return n_convert;
}

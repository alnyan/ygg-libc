#include <_libc/stdio.h>
#include <ctype.h>
#include <stdio.h>

int __libc_vscanf(const char *format,
                  void *ctx,
                  int (*in)(void *ctx),
                  va_list ap) {
    size_t n_convert = 0;
    union {
        uint64_t value_unsigned;
    } pv;
    char ch;
    int ic;

    while ((ch = *format)) {
        if (isspace(ch)) {
            // Skip whitespace
        } else if (ch == '%') {
            // Conversion spec
            ch = *++format;

            switch (ch) {
            case 'u':
                pv.value_unsigned = 0;
                while ((ic = in(ctx)) != EOF && isdigit(ic)) {
                    pv.value_unsigned *= 10;
                    pv.value_unsigned += ic - '0';
                }
                *((unsigned int *) va_arg(ap, unsigned int *)) = pv.value_unsigned;
                ++n_convert;
                ++format;
                break;
            default:
                goto err;
            }
        } else {
            ic = in(ctx);

            if (ic == EOF) {
                goto err;
            }
        }
        ++format;
    }

err:
    if (!n_convert) {
        return -1;
    }
    return n_convert;
}

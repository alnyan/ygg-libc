#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#define wrc(c) \
    if (!lim) { \
        dst[0] = 0; \
        return 0; \
    } else { \
        dst[off++] = c; \
        --lim; \
    }

#define wrs(s, l) \
    if (lim < (l)) { \
        dst[0] = 0; \
        return 0; \
    } else { \
        strncpy(&dst[off], s, l); \
        lim -= (l); \
        off += (l); \
    }

static const char *abdays[] = {
    "Mon.", "Tue.", "Wed.", "Thu.", "Fri.", "Sat.", "Sun."
};
static const char *abmon[] = {
    "Jan.", "Feb.", "Mar.", "Apr.", "May ", "Jun.",
    "Jul.", "Aug.", "Sep.", "Oct.", "Nov.", "Dec."
};

static size_t fmtl(char *dst, char ch, const struct tm *tm) {
    switch (ch) {
    case 'a':
        if (tm->tm_wday > 6 || tm->tm_wday < 0) {
            return 0;
        }
        strncpy(dst, abdays[tm->tm_wday], 4);
        return 4;
    case 'b':
        if (tm->tm_mon > 12 || tm->tm_mon < 1) {
            return 0;
        }
        strncpy(dst, abmon[tm->tm_mon - 1], 4);
        return 4;
    case 'd':
        dst[0] = (tm->tm_mday / 10) + '0';
        dst[1] = (tm->tm_mday % 10) + '0';
        return 2;
    case 'e':
        dst[0] = tm->tm_mday / 10;
        dst[1] = (tm->tm_mday % 10) + '0';
        if (dst[0] == 0) {
            dst[0] = ' ';
        } else {
            dst[0] += '0';
        }
        return 2;
    case 'H':
        dst[0] = tm->tm_hour / 10 + '0';
        dst[1] = tm->tm_hour % 10 + '0';
        return 2;
    case 'M':
        dst[0] = tm->tm_min / 10 + '0';
        dst[1] = tm->tm_min % 10 + '0';
        return 2;
    case 'S':
        dst[0] = tm->tm_sec / 10 + '0';
        dst[1] = tm->tm_sec % 10 + '0';
        return 2;
    case 'Y':
        dst[0] = tm->tm_year / 1000 + '0';
        dst[1] = (tm->tm_year / 100) % 10 + '0';
        dst[2] = (tm->tm_year / 10) % 10 + '0';
        dst[3] = tm->tm_year % 10 + '0';
        return 4;
    default:
        return 0;
    }
}

size_t strftime(char *restrict dst, size_t lim, const char *restrict fmt, const struct tm *restrict tm) {
    if (!lim) {
        errno = ENOMEM;
        return -1;
    }
    // Must be enough for all fmtl() calls
    char buf[64];
    size_t off = 0, l;
    char ch;
    --lim;

    while ((ch = *fmt++)) {
        if (ch == '%') {
            ch = *fmt++;

            switch (ch) {
            case 'c':
                // %a %b %e %H:%M:%S %Y
                l = fmtl(buf, 'a', tm);
                wrs(buf, l);
                wrc(' ');

                l = fmtl(buf, 'b', tm);
                wrs(buf, l);
                wrc(' ');

                l = fmtl(buf, 'e', tm);
                wrs(buf, l);
                wrc(' ');

                l = fmtl(buf, 'H', tm);
                wrs(buf, l);
                wrc(':');

                l = fmtl(buf, 'M', tm);
                wrs(buf, l);
                wrc(':');

                l = fmtl(buf, 'S', tm);
                wrs(buf, l);
                wrc(' ');

                l = fmtl(buf, 'Y', tm);
                wrs(buf, l);
                break;
            case 'a':
            case 'b':
            case 'd':
            case 'e':
            case 'H':
            case 'M':
            case 'S':
            case 'Y':
                l = fmtl(buf, ch, tm);
                wrs(buf, l);
                break;
            default:
                wrc('%');
                wrc(ch);
                break;
            }
        } else {
            wrc(ch);
        }
    }

    dst[off] = 0;
    return off;
}

#include <stdlib.h>
#include <stdio.h>

// Initial buffer size
#define GETDELIM_BUF_SIZE 256
#define GETDELIM_BUF_INCR 256

ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *fp) {
    size_t rem;
    size_t read = 0;
    char *p;

    if (!lineptr || !n) {
        return -1;
    }

    if (!*lineptr || !*n) {
        *n = GETDELIM_BUF_SIZE;
        *lineptr = malloc(GETDELIM_BUF_SIZE);
        if (!*lineptr) {
            return -1;
        }
    }

    p = *lineptr;

    while (1) {
        if (!rem) {
            *n += GETDELIM_BUF_INCR;
            if (!(*lineptr = realloc(*lineptr, *n))) {
                return -1;
            }
            p = *lineptr + read;
            rem += GETDELIM_BUF_INCR;
        }

        int ch = fgetc(fp);
        if (ch == EOF) {
            break;
        }

        if (ch == delim) {
            p[read] = 0;
            return read;
        }

        p[read++] = ch;
        --rem;
    }

    if (!read) {
        return -1;
    }
    return read;
}

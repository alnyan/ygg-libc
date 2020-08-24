#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

// TODO: rewrite this crap
struct xorshift32_state {
    uint32_t a;
};

static uint32_t xorshift32(struct xorshift32_state *state) {
	uint32_t x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return state->a = x;
}

static struct xorshift32_state state;

static void randomize(char *tmp) {
    time_t t = time(NULL);
    state.a = t + 1237617;

    for (size_t i = 0; i < 6; ++i) {
        tmp[i] = (xorshift32(&state) % ('z' - 'a')) + 'a';
    }
}

int mkostemps(char *template, int suffixlen, int flags) {
    int fd;

    size_t template_len = strlen(template);
    if (template_len < (size_t) suffixlen + 6) {
        return -1;
    }

    char *tmp = template + template_len - suffixlen - 6;
    if (strncmp(tmp, "XXXXXX", 6)) {
        return -1;
    }

    while (1) {
        randomize(tmp);

        if ((fd = open(template, 0666, flags | O_CREAT | O_EXCL)) > 0) {
            return fd;
        }
    }
}

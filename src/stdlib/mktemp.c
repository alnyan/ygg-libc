#include <unistd.h>
#include <string.h>
#include <stdlib.h>
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

char *mktemp(char *template) {
    size_t template_len = strlen(template);
    if (template_len < 6) {
        return NULL;
    }
    char *tmp = template + template_len - 6;
    while (1) {
        randomize(tmp);

        if (access(template, F_OK) != 0) {
            return tmp;
        }
    }
}

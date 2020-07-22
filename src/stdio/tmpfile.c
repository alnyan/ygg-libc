#include <stdint.h>
#include <stdio.h>
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

static int initialized = 0;
static struct xorshift32_state state;

FILE *tmpfile(void) {
    // TODO: make this atomic?
    char name[32];

    if (!initialized) {
        time_t t = time(NULL);
        state.a = t + 1237617;
        initialized = 1;
    }

    uint32_t rnd = xorshift32(&state);
    snprintf(name, sizeof(name), "/tmp/%u", rnd);

    // TODO: actually support this mode
    // TODO: delete-on-close flag
    FILE *fp = fopen(name, "w+b");
    return fp;
}

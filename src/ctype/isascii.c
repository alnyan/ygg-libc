#include <ctype.h>

int isascii(int ch) {
    return !(ch & ~0x7F);
}

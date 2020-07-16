#include <ctype.h>

int isprint(int ch) {
    return ch >= ' ' && ch != 127;
}

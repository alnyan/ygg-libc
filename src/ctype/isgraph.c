#include <ctype.h>

int isgraph(int ch) {
    return ch > ' ' && ch != 127;
}

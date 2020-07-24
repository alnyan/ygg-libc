#include <ctype.h>

int isprint(int ch) {
    return ch >= ' ' && ch != 127 && ch < 255;
}

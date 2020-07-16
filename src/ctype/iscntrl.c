#include <ctype.h>

int iscntrl(int ch) {
    return (ch <= 31) || ch == 127;
}

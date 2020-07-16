#include <ctype.h>

int isspace(int ch) {
    return ch == '\f' ||
           ch == '\n' ||
           ch == '\r' ||
           ch == '\t' ||
           ch == '\v' ||
           ch == ' ';
}

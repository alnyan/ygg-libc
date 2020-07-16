#include <ctype.h>

int isxdigit(int ch) {
    return (ch >= 'a' && ch <= 'f') ||
           (ch >= 'A' && ch <= 'F') ||
           (ch >= '0' && ch <= '9');
}

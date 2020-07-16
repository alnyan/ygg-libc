#include <ctype.h>

int ispunct(int ch) {
    return (ch >= '!' && ch <= '/') ||
           (ch >= ':' && ch <= '@') ||
           (ch >= '[' && ch <= '`') ||
           (ch >= '{' && ch <= '~');
}

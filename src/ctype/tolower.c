#include <ctype.h>

int tolower(int ch) {
    return isupper(ch) ? (ch - 'A' + 'a') : ch;
}

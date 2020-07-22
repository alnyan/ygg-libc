#include <locale.h>

char *setlocale(int cat, const char *locale) {
    (void) cat;
    (void) locale;
    return 0;
}

#include <math.h>

double sinh(double x) {
    // (exp(2x) - 1) / 2exp(x)
    double w, v;

    w = exp(2 * x) - 1;
    v = 2 * exp(x);

    return w / v;
}

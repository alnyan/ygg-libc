#include <math.h>

double cosh(double x) {
    // (e^2x + 1) / 2e^x
    double w, v;

    w = exp(2 * x) + 1;
    v = 2 * exp(x);

    return w / v;
}

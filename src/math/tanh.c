#include <math.h>

double tanh(double x) {
    // (e^2x - 1) / (e^2x + 1)
    double w, v;

    w = exp(2 * x) - 1;
    v = exp(2 * x) + 1;

    return w / v;
}

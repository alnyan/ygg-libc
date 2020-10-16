#pragma once

#define HUGE_VAL        (__builtin_huge_val())

#if defined(__cplusplus)
extern "C" {
#endif

double log10(double f);
double log2(double f);
double log(double f);
double sqrt(double f);
double floor(double f);
double ceil(double f);
double fmod(double x, double y);
double modf(double x, double *iptr);
double atan(double x);
double atan2(double x, double y);
double asin(double x);
double acos(double x);
double fabs(double x);
double pow(double x, double y);
double tanh(double f);
double cosh(double f);
double sinh(double f);
double sin(double f);
double cos(double f);
double tan(double f);
double frexp(double x, int *exp);
double ldexp(double x, int exp);
double exp(double f);

#if defined(__cplusplus)
}
#endif

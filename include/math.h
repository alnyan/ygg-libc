#pragma once

#define HUGE_VAL        (__builtin_huge_val())
#define M_E             2.7182818284590452354
#define M_LOG2E         1.4426950408889634074
#define M_LOG10E        0.43429448190325182765
#define M_LN2           0.69314718055994530942
#define M_LN10          2.30258509299404568402
#define M_PI            3.14159265358979323846
#define M_PI_2          1.57079632679489661923
#define M_PI_4          0.78539816339744830962
#define M_1_PI          0.31830988618379067154
#define M_2_PI          0.63661977236758134308
#define M_2_SQRTPI      1.12837916709551257390
#define M_SQRT2         1.41421356237309504880
#define M_SQRT1_2       0.70710678118654752440

#define INFINITY        (__builtin_inff())
#define NAN             (__builtin_nanf(""))

#define isinf(x)        (__builtin_types_compatible_p (__typeof (x), _Float128) \
                        ? __isinff128 (x) : __builtin_isinf_sign (x))
#define isnan(x)        (__builtin_isnan(x))

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
double atan(double x);                  // +
double atan2(double y, double x);       // +
double asin(double x);                  // +
double acos(double x);                  // +
double fabs(double x);                  // +
double pow(double x, double y);
double tanh(double f);                  //
double cosh(double f);                  // +
double sinh(double f);                  // +
double sin(double f);                   // +
double cos(double f);                   // +
double tan(double f);                   // +
double frexp(double x, int *exp);
double ldexp(double x, int exp);
double exp(double f);                   // +

#if defined(__cplusplus)
}
#endif

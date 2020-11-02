#include <math.h>

//struct ieee_single {
//	u_int	sng_frac:23;
//	u_int	sng_exp:8;
//	u_int	sng_sign:1;
//};

struct ieee_double {
    unsigned int dbl_fracl;
    unsigned int dbl_frach:20;
    unsigned int dbl_exp:11;
    unsigned int dbl_sign:1;
};

//struct ieee_ext {
//	u_int	ext_fracl;
//	u_int	ext_frach;
//	u_int	ext_exp:15;
//	u_int	ext_sign:1;
//	u_int	ext_padl:16;
//	u_int	ext_padh;
//};

double fabs(double x) {
    struct ieee_double *d = (struct ieee_double *) &x;
    d->dbl_sign = 0;
    return x;
}

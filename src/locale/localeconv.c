#include <locale.h>

static const struct lconv generic = {
    .currency_symbol = "",
    .decimal_point = "",
    .frac_digits = -1,
    .grouping = "",
    .int_curr_symbol = "",
    .int_frac_digits = -1,
    .int_n_cs_precedes = -1,
    .int_n_sep_by_space = -1,
    .int_n_sign_posn = -1,
    .int_p_cs_precedes = -1,
    .int_p_sep_by_space = -1,
    .int_p_sign_posn = -1,
    .mon_decimal_point = "",
    .mon_grouping = "",
    .mon_thousands_sep = "",
    .negative_sign = "",
    .n_cs_precedes = -1,
    .n_sep_by_space = -1,
    .n_sign_posn = -1,
    .positive_sign = "",
    .p_cs_precedes = -1,
    .p_sep_by_space = -1,
    .p_sign_posn = -1,
    .thousands_sep = ""
};

struct lconv *localeconv(void) {
    return (struct lconv *) &generic;
}

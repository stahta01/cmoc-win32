/*---------------------------------------------------------------------------*/
/* locale.h - locale specific header file                                    */
/*---------------------------------------------------------------------------*/

#ifndef _LOCALE_H
#define _LOCALE_H

#define LC_ALL        0
#define LC_COLLATE    1
#define LC_CTYPE      2
#define LC_NUMERIC    3
#define LC_MONETARY   4
#define LC_TIME       5

/* Locales */

#define LC_C          "C"
#define LC_C_FRANCE   "FRANCE"
#define LC_C_GERMANY  "GERMANY"
#define LC_C_ITALY    "ITALY"
#define LC_C_SPAIN    "SPAIN"
#define LC_C_UK       "UK"
#define LC_C_USA      "USA"

struct lconv {
    char* decimal_point;
    char* thousands_sep;
    char* grouping;
    char* int_curr_symbol;
    char* currency_symbol;
    char* mon_decimal_point;
    char* mon_thousands_sep;
    char* mon_grouping;
    char* positive_sign;
    char* negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
};

/*---------------------------------------------------------------------------*/
/* function prototpes                                                        */
/*---------------------------------------------------------------------------*/
char* setlocale(int category,  char* locale);
struct lconv* localeconv(void);

#endif




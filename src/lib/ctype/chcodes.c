
#include <ctype.h>

char  _chcodes[128] = {
    /* 00 */    _CONTROL,
    /* 01 */    _CONTROL,
    /* 02 */    _CONTROL,
    /* 03 */    _CONTROL,
    /* 04 */    _CONTROL,
    /* 05 */    _CONTROL,
    /* 06 */    _CONTROL,
    /* 07 */    _CONTROL,
    /* 08 */    _CONTROL,
    /* 09 */    _CONTROL|_WHITE,
    /* 0A */    _CONTROL|_WHITE,
    /* 0B */    _CONTROL|_WHITE,
    /* 0C */    _CONTROL|_WHITE,
    /* 0D */    _CONTROL|_WHITE,
    /* 0E */    _CONTROL,
    /* 0F */    _CONTROL,
    /* 10 */    _CONTROL,
    /* 11 */    _CONTROL,
    /* 12 */    _CONTROL,
    /* 13 */    _CONTROL,
    /* 14 */    _CONTROL,
    /* 15 */    _CONTROL,
    /* 16 */    _CONTROL,
    /* 17 */    _CONTROL,
    /* 18 */    _CONTROL,
    /* 19 */    _CONTROL,
    /* 1A */    _CONTROL,
    /* 1B */    _CONTROL,
    /* 1C */    _CONTROL,
    /* 1D */    _CONTROL,
    /* 1E */    _CONTROL,
    /* 1F */    _CONTROL,
    /* 20 */    _PUNCT|_WHITE,                      // Space is punct?
    /*  ! */    _PUNCT,
    /*  " */    _PUNCT,
    /*  # */    _PUNCT,
    /*  $ */    _PUNCT,
    /*  % */    _PUNCT,
    /*  & */    _PUNCT,
    /*  ' */    _PUNCT,
    /*  ( */    _PUNCT,
    /*  ) */    _PUNCT,
    /*  * */    _PUNCT,
    /*  + */    _PUNCT,
    /*  , */    _PUNCT,
    /*  - */    _PUNCT,
    /*  . */    _PUNCT,
    /*  / */    _PUNCT,
    /*  0 */    _DIGIT|_HEXDIG,
    /*  1 */    _DIGIT|_HEXDIG,
    /*  2 */    _DIGIT|_HEXDIG,
    /*  3 */    _DIGIT|_HEXDIG,
    /*  4 */    _DIGIT|_HEXDIG,
    /*  5 */    _DIGIT|_HEXDIG,
    /*  6 */    _DIGIT|_HEXDIG,
    /*  7 */    _DIGIT|_HEXDIG,
    /*  8 */    _DIGIT|_HEXDIG,
    /*  9 */    _DIGIT|_HEXDIG,
    /*  : */    _PUNCT,
    /*  ; */    _PUNCT,
    /*  < */    _PUNCT,
    /*  = */    _PUNCT,
    /*  > */    _PUNCT,
    /*  ? */    _PUNCT,
    /*  @ */    _PUNCT,
    /*  A */    _UPPER|_HEXDIG,
    /*  B */    _UPPER|_HEXDIG,
    /*  C */    _UPPER|_HEXDIG,
    /*  D */    _UPPER|_HEXDIG,
    /*  E */    _UPPER|_HEXDIG,
    /*  F */    _UPPER|_HEXDIG,
    /*  G */    _UPPER,
    /*  H */    _UPPER,
    /*  I */    _UPPER,
    /*  J */    _UPPER,
    /*  K */    _UPPER,
    /*  L */    _UPPER,
    /*  M */    _UPPER,
    /*  N */    _UPPER,
    /*  O */    _UPPER,
    /*  P */    _UPPER,
    /*  Q */    _UPPER,
    /*  R */    _UPPER,
    /*  S */    _UPPER,
    /*  T */    _UPPER,
    /*  U */    _UPPER,
    /*  V */    _UPPER,
    /*  W */    _UPPER,
    /*  X */    _UPPER,
    /*  Y */    _UPPER,
    /*  Z */    _UPPER,
    /*  [ */    _PUNCT,
    /*  \ */    _PUNCT,
    /*  ] */    _PUNCT,
    /*  ^ */    _PUNCT,
    /*  _ */    _PUNCT,
    /*  ` */    _PUNCT,
    /*  a */    _LOWER|_HEXDIG,
    /*  b */    _LOWER|_HEXDIG,
    /*  c */    _LOWER|_HEXDIG,
    /*  d */    _LOWER|_HEXDIG,
    /*  e */    _LOWER|_HEXDIG,
    /*  f */    _LOWER|_HEXDIG,
    /*  g */    _LOWER,
    /*  h */    _LOWER,
    /*  i */    _LOWER,
    /*  j */    _LOWER,
    /*  k */    _LOWER,
    /*  l */    _LOWER,
    /*  m */    _LOWER,
    /*  n */    _LOWER,
    /*  o */    _LOWER,
    /*  p */    _LOWER,
    /*  q */    _LOWER,
    /*  r */    _LOWER,
    /*  s */    _LOWER,
    /*  t */    _LOWER,
    /*  u */    _LOWER,
    /*  v */    _LOWER,
    /*  w */    _LOWER,
    /*  x */    _LOWER,
    /*  y */    _LOWER,
    /*  z */    _LOWER,
    /*  { */    _PUNCT,
    /*  | */    _PUNCT,
    /*  } */    _PUNCT,
    /*  ~ */    _PUNCT,
    /* 7f */    _CONTROL
};


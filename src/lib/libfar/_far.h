
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <far.h>
#include <bank.h>
#include <heman.h>
#include <std/array.h>

typedef std_array(bank_t, 10) far_banks_t;

extern far_banks_t far_banks;


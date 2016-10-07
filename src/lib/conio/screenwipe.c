
#include "_conio.h"

void screenwipe(void)
{
    if (_is_coco3_mode) {
        bank_t bank = bank_set(13);
        memset(0xc000, 0, _h_dispen - 0x2000);
        bank_set(bank);
    } else  if (isvidram()) {
        memset(_VIDRAM, 96, 0x200);
    } else if (_conio.clearscreen) {
        // TODO: We dont really need to call graph here.
        _conio.clearscreen(_GCLEARSCREEN);
    }
}


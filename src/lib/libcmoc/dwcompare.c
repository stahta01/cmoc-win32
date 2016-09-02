
#include <coco.h>

sbyte dwcompare(word* a, word* b)
{
    sbyte result;
    asm {
        pshs    y                       // must not use U, which serves to refer to 'a' and 'b'
        ldx     a
        ldy     b
        ldd     ,x++                    // compare MSBs
        cmpd    ,y++
        beq     dwcompare_equal
        blo     dwcompare_lower

        dwcompare_greater:
        ldb     #1
        stb     result
        bra     dwcompare_end

        dwcompare_lower:
        ldb     #-1
        stb     result
        bra     dwcompare_end

        dwcompare_equal:
        ldd     ,x                      // compare LSBs
        cmpd    ,y
        blo     dwcompare_lower
        bhi     dwcompare_greater
        clr     result

        dwcompare_end:
        puls    y
    }
    return result;
}


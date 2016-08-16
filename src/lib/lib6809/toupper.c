
int asm toupper(int c)
{
    asm {
        ldd     2,s             // character in B
        cmpb    #97             // 'a'
        blo     toupper_done
        cmpb    #122            // 'z'
        bhi     toupper_done
        subb    #32
        toupper_done:
    }
}



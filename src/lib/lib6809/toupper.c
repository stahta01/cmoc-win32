
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

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




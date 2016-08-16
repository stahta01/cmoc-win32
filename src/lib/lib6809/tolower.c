
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

int asm tolower(int c)
{
    asm {
        ldd     2,s             // character in B
        cmpb    #65             // 'A'
        blo     tolower_done
        cmpb    #90             // 'Z'
        bhi     tolower_done
        addb    #32

        tolower_done:
    }
}



